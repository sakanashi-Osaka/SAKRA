#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include <signal.h>
#include <bitset>

#include <TFile.h>
#include <TTree.h>
#include <TH2D.h>

#include "RunInfo.hpp"
#include "V1730ZLEHeader.hpp"
#include "ChEvent.hpp"
#include "V1730ZLE.hpp"

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

TH2D* waveform[N_FADC_BOARD][16];

class TEventData{
public:
  uint64_t ts;
  bool evt_stored;
  int Clk[RECORD_LENGTH];

  //*** ROOT ***
  TFile *file;
  TTree *tree;
  TH2D *waveform[N_FADC_BOARD][N_CH];

  //*** data segment ***
  vector<TV1730ZLE> *zle_data;

  TEventData(char *fname);
  void Init();
  void RunEnd();
  void SetEvtNum(uint32_t num) {evtn=num;}
private:
  uint32_t evtn;
  
};

TEventData::TEventData(char *fname){
  evt_stored=false;
  
  file = new TFile(fname,"RECREATE");
  tree = new TTree("tree","tree");

  zle_data=new vector<TV1730ZLE>(N_FADC_BOARD);
  tree->Branch("event","vector<TV1730ZLE>",&zle_data,16000,0);
};

void TEventData::Init(){
  if(evt_stored){
    tree->Fill();
    evt_stored=false;
  }
  // initialize
  ts=-1;
  evtn=-1;

  for(int i=0;i<zle_data->size();++i) zle_data->at(i).Clear();
  
  evt_stored=true;
};

void TEventData::RunEnd(){
  if(evt_stored){
    tree->Fill();
    evt_stored=false;
  }

  file->cd();
  tree->AutoSave();

  file->Close();
};

bool evt_stored=false;
bool quit_flag=false;


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
  uint32_t *rawbuff;
  uint32_t date,scrid;
  int cid,blksize;
  int segdatasize,scrdatasize;
  unsigned int blkn=-1;
  char comment[10000]={};
  int board;
  char hnam[100];

  TEventData evt_data(argv[2]);
  TRunInfo run_info;

  signal(SIGINT, stop_dataread);

  if(argc!=3){
    cerr << "Usage: " << argv[0] << " [ifile] [ofile]" << endl;
    return -1;
  }

  ifstream fin(argv[1], ios::in|ios::binary);
  if(!fin.is_open()){
    cerr << "\033[31mError: faile to open " << argv[1] << "\033[m" << endl;
    return -1;
  }

  buff = new uint32_t[0x800000];
  rawbuff = new uint32_t[0x800000];

  for(int i=0;i<2;i++){
    for(int j=0;j<16;j++){
      sprintf(hnam,"waveform_%d_%02d",i,j);
      waveform[i][j]=new TH2D(hnam,hnam,RECORD_LENGTH,0,RECORD_LENGTH,1024,0,16384);
    }
  }
  
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
      evt_data.Init();
      fin.read((char*)&evtn, sizeof(evtn));
      evt_data.SetEvtNum(evtn);
      if(cid==RIDF_EVENT_TS){
	fin.read((char*)&ts, sizeof(ts));
	evt_data.ts=(ts & 0x0000ffffffffffff);
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
      //board=segid & 0xFF;
      board=(segid & 0x3F00)>>8;
      if((blksize-(sizeof(buf_header)+sizeof(segid))/2)==0){
	//	printf("\nError: Event_N:%d, board:%d has no Segment data\n",evtn,board);
	break;
      }
      fin.read((char*)rawbuff, 2*(blksize-(sizeof(buf_header)+sizeof(segid))/2));
      evt_data.zle_data->at(board).Analyze(rawbuff);
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
	//printf("%s\n",comment);
	DB(printf("Comment Hearder / blkn=%d\n",blkn));
	DB(printf("Comment Date =%d\n",date));
	DB(printf("Comment ID =%d\n",scrid));
	if(scrid==1){
	  run_info.SetValue(comment);
	  run_info.Print();
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
  evt_data.RunEnd();

  /*
  for(int i=0;i<2;i++){
    for(int j=0;j<16;j++){
      waveform[i][j]->Write();
    }
  }
  
  run_info.Write();
  */
  
  if(quit_flag) printf("\nQuit \n");

  return 0;
}
