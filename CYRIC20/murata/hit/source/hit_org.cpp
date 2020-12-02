#include <iostream>
#include <TFile.h>
#include <TTree.h>

int main()
{
    TFile fIn("test.root");
    TTree *trIn = dynamic_cast<TTree *>(fIn.Get("tree"));
    if (!trIn)
        return 1;
    trIn->Print();

    int ADC_1F[16];
    int ADC_1R[8];
    int ADC_2F[16];
    int ADC_2R[8];
    trIn->SetBranchAddress("ADC_1F", ADC_1F);
    trIn->SetBranchAddress("ADC_1R", ADC_1R);
    trIn->SetBranchAddress("ADC_2F", ADC_2F);
    trIn->SetBranchAddress("ADC_2R", ADC_2R);

    TFile fOut("hit.root", "recreate");
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

    const int N = trIn->GetEntries();
    const double ene_null = -10;
    const double ch_null = -1;
    for (int i = 0; i < N; ++i)
    {

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
            if (ADC_1F[ch] > 100) //hit
            {
                ++nHit_1F;
                if (nHit_1F > 1) // multi-hit
                {
                    ene_1F = ene_null;
                    hitCh_1F = ch_null;
                }
                else //single-hit
                {
                    ene_1F = ADC_1F[ch];
                    hitCh_1F = ch;
                }
            }
        }

        //1 R
        for (int ch = 0; ch < 8; ch++)
        {
            if (ADC_1R[ch] > 100) //hit
            {
                ++nHit_1R;
                if (nHit_1R > 1) // multi-hit
                {
                    ene_1R = ene_null;
                    hitCh_1R = ch_null;
                }
                else //single-hit
                {
                    ene_1R = ADC_1R[ch];
                    hitCh_1R = ch;
                }
            }
        }

        //2 F
        for (int ch = 0; ch < 16; ch++)
        {
            if (ADC_2F[ch] > 100) //hit
            {
                ++nHit_2F;
                if (nHit_2F > 1) // multi-hit
                {
                    ene_2F = ene_null;
                    hitCh_2F = ch_null;
                }
                else //single-hit
                {
                    ene_2F = ADC_1F[ch];
                    hitCh_2F = ch;
                }
            }
        }

        //1 R
        for (int ch = 0; ch < 8; ch++)
        {
            if (ADC_2R[ch] > 100) //hit
            {
                ++nHit_2R;
                if (nHit_2R > 1) // multi-hit
                {
                    ene_2R = ene_null;
                    hitCh_2R = ch_null;
                }
                else //single-hit
                {
                    ene_2R = ADC_1R[ch];
                    hitCh_2R = ch;
                }
            }
        }

        trHit.Fill();
    }
    trHit.Write();

    return 0;
}