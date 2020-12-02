#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include <signal.h>

#include <TFile.h>
#include <TTree.h>
#include <TH2D.h>

using namespace std;

//#define DEBUG

#ifdef DEBUG
#define DB(x) x
#else
#define DB(x)
#endif

#define N_FADC_BOARD 3
#define RECORD_LENGTH 4096
#define N_CH 16

enum RIDF_CID{
  RIDF_EF_BLOCK,
  RIDF_EA_BLOCK,
  RIDF_EAEF_BLOCK,
  RIDF_EVENT,
  RIDF_SEGMENT,
  RIDF_COMMENT,
  RIDF_EVENT_TS,
  RIDF_BLOCK_NUMBER=8,
  RIDF_END_BLOCK,
  RIDF_SCALER=11,
  RIDF_NCSCALER=11,
  RIDF_CSCALER=12,
  RIDF_NCSCALER32,
  RIDF_TIMESTAMP=16,
  RIDF_STATUS=21,

};

typedef struct{
  char name[100];
  char num[100];
  char start[20];
  char stop[20];
  char date[60];
  char comment[200];
} RunInfo;

int nch[3]={16,16,16};
uint32_t v1730_header[4];
uint32_t v1730_ch_header;
int ch_size; // 32-bit word
uint32_t skipped_samples;
uint16_t data[N_FADC_BOARD][N_CH][RECORD_LENGTH];
int Clk[RECORD_LENGTH];
uint data_index;
int baseline[N_FADC_BOARD][N_CH];
int ADC[N_FADC_BOARD][N_CH];
double Energy[N_FADC_BOARD][N_CH];
int PeakClk[N_FADC_BOARD][N_CH];
int RiseEdge[N_FADC_BOARD][N_CH];

double ADCtoE[2]={-201,0.7118};

bool evt_stored=false;
bool quit_flag=false;

TFile* file;
TTree* tree;
TH2D* waveform[N_FADC_BOARD][N_CH];

void stop_dataread(int sig){
  quit_flag=true;
  evt_stored=false;
}

int main(int argc, char *argv[]){
  uint32_t buf_header[2]; // [header,address]
  uint32_t buf_size;
  uint32_t evtn;
  uint64_t ts;
  uint32_t segid;
  uint32_t *buff;
  uint32_t date,scrid;
  int cid,blksize;
  int segdatasize,scrdatasize;
  unsigned int blkn=-1;
  string gomi;
  char comment[100000];
  int board;
  char hnam[100];
  RunInfo run_info;
  
  signal(SIGINT, stop_dataread);

  if(argc!=3){
    cerr << argv[0] << " ifile ofile" << endl;
    return 0;
  }

  ifstream fin(argv[1], ios::in|ios::binary);

  if(!fin.is_open()){
    cerr << "\033[31mError: faile to open" << argv[1] << "\033[m " << endl;
    return 0;
  }

  buff = new uint32_t[0x800000];

  file = new TFile(argv[2],"RECREATE");
  tree = new TTree("tree","tree");
  char bnam[100];
  sprintf(bnam,"baseline[%d][%d]/I",N_FADC_BOARD,N_CH);
  tree->Branch("baseline",baseline,bnam);
  sprintf(bnam,"ADC[%d][%d]/I",N_FADC_BOARD,N_CH);
  tree->Branch("ADC",ADC,bnam);
  sprintf(bnam,"Energy[%d][%d]/D",N_FADC_BOARD,N_CH);
  tree->Branch("Energy",Energy,bnam);
  sprintf(bnam,"data[%d][%d][%d]/s",N_FADC_BOARD,N_CH,RECORD_LENGTH);
  tree->Branch("data",data,bnam);
  sprintf(bnam,"Clk[%d]/I",RECORD_LENGTH);
  tree->Branch("Clk",Clk,bnam);
  sprintf(bnam,"PeakClk[2][16]/I");
  tree->Branch("PeakClk",PeakClk,bnam);
  sprintf(bnam,"RiseEdge[2][16]/I");
  tree->Branch("RiseEdge",RiseEdge,bnam);
  for(int i=0;i<N_FADC_BOARD;i++){
    for(int j=0;j<N_CH;j++){
      sprintf(hnam,"waveform_%d_%02d",i,j);
      waveform[i][j]=new TH2D(hnam,hnam,RECORD_LENGTH,0,RECORD_LENGTH,1024,0,16384);
    }
  }
  for(int k=0;k<RECORD_LENGTH;k++) Clk[k]=k;

  while(!fin.eof()){
    fin.read((char*)buf_header, sizeof(buf_header));
    cid= (buf_header[0] & 0x0FC00000) >> 22;
    blksize= buf_header[0] & 0x003FFFFF; //2 byte
    DB(cout << "cid=" << cid << endl);
    switch(cid){
    case RIDF_EF_BLOCK:
    case RIDF_EA_BLOCK:
    case RIDF_EAEF_BLOCK:
      ++blkn;
      DB(printf("EF Block Header / blkn=%d\n",blkn));
      break;
    case RIDF_END_BLOCK:
      DB(printf("EF Block Ender / blkn=%d\n",blkn));
      fin.read((char*)&buf_size, sizeof(buf_size));
      DB(printf("Size of this block=%d\n",buf_size));
      break;
    case RIDF_BLOCK_NUMBER:
      DB(printf("EF Block Number / blkn=%d\n",blkn));
      fin.read((char*)&buf_size, sizeof(buf_size));
      DB(printf("The Number of this block=%d\n",buf_size));
      break;
    case RIDF_EVENT:
    case RIDF_EVENT_TS:
      if(evt_stored){
	tree->Fill();
	evt_stored=false;
      }
      evt_stored=true;
      fin.read((char*)&evtn, sizeof(evtn));
      if(cid==RIDF_EVENT_TS){
	fin.read((char*)&ts, sizeof(ts));
	ts &= 0x0000ffffffffffff;
	DB(printf("Event Hearder with Time Stamp / blkn=%d\n",blkn));
	DB(printf("Event Number = %d\n",evtn));
	DB(printf("Time Stamp = %ld\n",ts));
      }
      else{
	DB(printf("Event Hearder / blkn=%d\n",blkn));
	DB(printf("Event Number = %d\n",evtn));
      }
      if(evtn%1000==0){
	printf("\rAnalyzing Event Number: %d",evtn);
	fflush(stdout);
      }
      break;
    case RIDF_SEGMENT:
      fin.read((char*)&segid, sizeof(segid));
      board=(segid & 0x3F00) >> 8;
      if((blksize-(sizeof(buf_header)+sizeof(segid))/2)==0){
	//	printf("\nError: Event_N:%d, board:%d has no Segment data\n",evtn,board);
	break;
      }
      fin.read((char*)v1730_header, sizeof(v1730_header));
      DB(printf("Segment Hearder / blkn=%d\n",blkn));
      DB(printf("Segment ID = %d (0x%08x)\n", segid, segid));
      DB(printf("header0=%x, eventsize=%d\n",v1730_header[0],v1730_header[0] & 0x0FFFFFFF));
      DB(printf("board=%d, event counter=%d\n",board,v1730_header[2] & 0x00FFFFFF));

      segdatasize=blksize-(sizeof(buf_header)+sizeof(segid)+sizeof(v1730_header))/2;
      if(segdatasize==0) break;

      for(int ch=0;ch<nch[board];ch++){
	data_index=0;	
	ADC[board][ch]=-1;
	Energy[board][ch]=-1;
	PeakClk[board][ch]=-1;
	RiseEdge[board][ch]=-1;
	memset(data[board][ch],0,sizeof(uint16_t)*RECORD_LENGTH);
	fin.read((char*)&v1730_ch_header, sizeof(v1730_ch_header));
	baseline[board][ch]=(v1730_ch_header & 0x3FFF0000) >> 16;
	ch_size=v1730_ch_header & 0x0000FFFF;
	DB(printf("ch%d size=%d\n",ch,ch_size));
	fin.read((char*)buff, (ch_size-1)*4);
	if(ch_size==2) continue;
	for(int i=0;i<(ch_size-1);i++){
	  if((buff[i]>>31)  & 0x1){
	    skipped_samples= (buff[i] & 0x0FFFFFFF) * 2;
	    DB(printf("skipped events=%d\n",skipped_samples));
	    for(uint j=0; j<skipped_samples; j++,data_index++) data[board][ch][data_index]=0;
	    continue;
	  }
	  data[board][ch][data_index++]=buff[i] & 0x00003FFF;
	  data[board][ch][data_index++]=(buff[i] & 0x3FFF0000)>>16;
	}
	if(data[board][ch][0]>baseline[board][ch]) continue;
	for(int i=0;i<RECORD_LENGTH;i++){
	  if(data[board][ch][i]==0) continue;
	  waveform[board][ch]->Fill(i,data[board][ch][i],1.);
	  if(ADC[board][ch]<abs(data[board][ch][i]-baseline[board][ch])){
	    ADC[board][ch]=abs(data[board][ch][i]-baseline[board][ch]);
	    Energy[board][ch]=(ADCtoE[0]+ADCtoE[1]*ADC[board][ch]);
	    PeakClk[board][ch]=i;
	  }
	  
	}
	//cout << "next event" << endl;
	
	for(int i=0;i<RECORD_LENGTH;i++){
	  if(data[board][ch][i]==0) continue;
	  if(0.20*ADC[board][ch]>abs(data[board][ch][i]-baseline[board][ch])){
	    RiseEdge[board][ch]=i;
	  }
	}
      }

      break;
    case RIDF_SCALER: // and RIDF_NCSCALER
    case RIDF_CSCALER:
    case RIDF_NCSCALER32:
    case RIDF_STATUS:
    case RIDF_COMMENT:
      fin.read((char*)&date, sizeof(date));
      fin.read((char*)&scrid, sizeof(scrid));
      scrdatasize=blksize-(sizeof(buf_header)+sizeof(date)+sizeof(scrid))/2;
      if(cid==RIDF_STATUS){
	fin.read((char*)buff, scrdatasize*2);
	DB(printf("Status Hearder / blkn=%d\n",blkn));
	DB(printf("Status Date =%d\n",date));
	DB(printf("Status ID =%d\n",scrid));
      }
      else if(cid==RIDF_COMMENT){
	fin.read((char*)comment, scrdatasize*2);
	DB(printf("Comment Hearder / blkn=%d\n",blkn));
	DB(printf("Comment Date =%d\n",date));
	DB(printf("Comment ID =%d\n",scrid));
	if(scrid==1){
	  strncpy(run_info.name,comment,100);
	  strncpy(run_info.num,&comment[100],100);
	  strncpy(run_info.start,&comment[200],20);
	  strncpy(run_info.stop,&comment[220],20);
	  strncpy(run_info.date,&comment[240],60);
	  strncpy(run_info.comment,&comment[300],200);

	  printf("Run_Name: %s\n",run_info.name);
	  printf("Run_Num : %s\n",run_info.num);
	  printf("Start   : %s\n",run_info.start);
	  printf("Stop    : %s %s\n",run_info.stop,run_info.date);
	  printf("Comment : %s\n\n",run_info.comment);
	}
      }
      else{
	fin.read((char*)buff, scrdatasize*2);
	DB(printf("Scaler Hearder / blkn=%d\n",blkn));
	DB(printf("Scaler Date =%d\n",date));
	DB(printf("Scaler ID =%d\n",scrid));
      }
      break;
    case RIDF_TIMESTAMP:
      segdatasize=blksize-sizeof(buf_header)/2;
      fin.read((char*)buff, segdatasize*2);
      DB(printf("Timestamp Hearder / blkn=%d\n",blkn));
      break;
    default:
      printf("Error: RIDF Class ID:%d is invalid.\n",cid);
      printf("Block Number=%d\n",blkn);
      break;
    }

    if(quit_flag) break;

  }

  cout << endl;
  if(evt_stored){
    tree->Fill();
    evt_stored=false;
  }

  file->cd();
  tree->AutoSave();
  for(int i=0;i<N_FADC_BOARD;i++){
    for(int j=0;j<N_CH;j++){
      waveform[i][j]->Write();
    }
  }
  file->Close();
  
  if(quit_flag) printf("\nQuit \n");

  return 0;
}
