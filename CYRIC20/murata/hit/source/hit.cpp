#include <iostream>
#include <fstream>
#include <map>
#include <regex>

#include <TFile.h>
#include <TTree.h>

#include "Config.hpp"
#include "ChannelMap.hpp"

//Get Run No from RIDF path
int ExtractRunNo(const std::string& _filename){
  std::string obj_str = _filename;
  std::smatch smatch;
  std::regex_search(obj_str, smatch, std::regex("\\d{4}"));
  if(smatch.size() == 0){
    throw std::runtime_error("ExtractRunNo(): NO pattern found. - > " + _filename);
  }
  else if (smatch.size() == 1){
    std::string run_no = smatch[0].str().substr(0,4);
    std::cerr << "OK run " << run_no << std::endl;
    return std::stoi(run_no);
  }
  else{
    throw std::runtime_error("ExtractRunNo(): Multiple hit. " + _filename);
  }
}


//Make friend Ttree having information on hit pattern
int main(int argc, char* argv[])
{

  if(argc < 2){
    std::cerr << argv[0] << " [input] ([N events])" << std::endl;
    return 1;
  }

  Config conf;

  std::string inputfile(conf.GetInputDir() + "/" + argv[1]);
  std::string outputfile(conf.GetOutputDir() + "/" + argv[1] + "_hit_.root");
  const int nRun = ExtractRunNo(argv[1]);
  std::cout << "RUN == " << nRun << std::endl;
  int N_event = -1;
  if(argc > 2)
    N_event = std::atoi(argv[2]);

  TFile fIn(inputfile.c_str());

  TTree *trIn = dynamic_cast<TTree *>(fIn.Get("tree"));
  if (!trIn){
    std::cerr << "tree not found" << std::endl;
    return 1;
  }
    trIn->Print();

    int ADC[3][16];
    double Energy[3][16];
    ChannelMap ch_map(nRun, ADC, Energy);

    trIn->SetBranchAddress("ADC", ADC);
    trIn->SetBranchAddress("Energy", Energy);

    TFile fOut(outputfile.c_str(), "recreate");
    TTree trHit("hit", "");

    int nHit_1F;
    int nHit_1R;
    int nHit_2F;
    int nHit_2R;

    int hitCh_1F;
    int hitCh_1R;
    int hitCh_2F;
    int hitCh_2R;

    double ene_1F;
    double ene_1R;
    double ene_2F;
    double ene_2R;

    trHit.Branch("nHit_1F", &nHit_1F, "nHit_1F/I");
    trHit.Branch("nHit_1R", &nHit_1R, "nHit_1R/I");
    trHit.Branch("nHit_2F", &nHit_2F, "nHit_2F/I");
    trHit.Branch("nHit_2R", &nHit_2R, "nHit_2R/I");

    trHit.Branch("hitCh_1F", &hitCh_1F, "hitCH_1F/I");
    trHit.Branch("hitCh_1R", &hitCh_1R, "hitCH_1R/I");
    trHit.Branch("hitCh_2F", &hitCh_2F, "hitCH_2F/I");
    trHit.Branch("hitCh_2R", &hitCh_2R, "hitCH_2R/I");

    trHit.Branch("ene_1F", &ene_1F, "ene_1F/D");
    trHit.Branch("ene_1R", &ene_1R, "ene_1R/D");
    trHit.Branch("ene_2F", &ene_2F, "ene_2F/D");
    trHit.Branch("ene_2R", &ene_2R, "ene_2R/D");

    const int N = N_event < 0 ? trIn->GetEntries() : N_event;
    const double ene_null = -10;
    const double ch_null = -1;
    const double energy_threshold = 1;//MeV
    for (int i = 0; i < N; ++i)
    {

      if(i % 1000 == 0)
	std::cout << i << std::endl;

        trIn->GetEntry(i);
        nHit_1F = 0;
        nHit_1R = 0;
        nHit_2F = 0;
        nHit_2R = 0;

        hitCh_1F = ch_null;
        hitCh_1R = ch_null;
        hitCh_2F = ch_null;
        hitCh_2R = ch_null;

        ene_1F = ene_null;
        ene_1R = ene_null;
        ene_2F = ene_null;
        ene_2R = ene_null;

        //1 F
        for (int ch = 0; ch < 16; ch++)
        {
	  //	  if (ch_map.ADC_100F(ch) > 100) //hit
	  if (ch_map.Energy_100F(ch) > energy_threshold) //hit
            {
                ++nHit_1F;
                if (nHit_1F > 1) // multi-hit
                {
                    ene_1F = ene_null;
                    hitCh_1F = ch_null;
                }
                else //single-hit
                {
		  ene_1F = ch_map.Energy_100F(ch);
		  hitCh_1F = ch;
                }
            }
        }

        //1 R
        for (int ch = 0; ch < 8; ch++)
        {
	  if (ch_map.ADC_100R(ch) > 100) //hit
	  //	  if (ch_map.Energy_100R(ch) > energy_threshold) //hit
            {
                ++nHit_1R;
                if (nHit_1R > 1) // multi-hit
                {
                    ene_1R = ene_null;
                    hitCh_1R = ch_null;
                }
                else //single-hit
                {
		  ene_1R = ch_map.Energy_100R(ch);
		  hitCh_1R = ch;
                }
            }
        }

        //2 F
        for (int ch = 0; ch < 16; ch++)
        {
	  //	  if (ch_map.ADC_500F(ch) > 100) //hit
	  if (ch_map.Energy_500F(ch) > energy_threshold) //hit
            {
                ++nHit_2F;
                if (nHit_2F > 1) // multi-hit
                {
                    ene_2F = ene_null;
                    hitCh_2F = ch_null;
                }
                else //single-hit
                {
		  ene_2F = ch_map.Energy_500F(ch);
		  hitCh_2F = ch;
                }
            }
        }

        //2 R
        for (int ch = 0; ch < 8; ch++)
        {
	  if (ch_map.ADC_500R(ch) > 100) //hit
	  //if (ch_map.Energy_500R(ch) > energy_threshold) //hit
            {
                ++nHit_2R;
                if (nHit_2R > 1) // multi-hit
                {
                    ene_2R = ene_null;
                    hitCh_2R = ch_null;
                }
                else //single-hit
                {
		  ene_2R = ch_map.Energy_500R(ch);
		  hitCh_2R = ch;
                }
            }
        }

        trHit.Fill();
    }
    trHit.Write();

    return 0;
}
