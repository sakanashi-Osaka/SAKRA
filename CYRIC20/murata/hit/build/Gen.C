#include <iostream>
#include <TTree.h>
#include <TFile.h>
#include <TRandom3.h>

std::pair<int, int> GenHitNum(TRandom &_randGen)
{
    double tmp = _randGen.Rndm();
    int hit1, hit2;
    if (tmp < 0.9)
    {
        hit1 = 1;
    }
    else if (tmp < 0.99)
    {
        hit1 = 2;
    }
    else
    {
        hit1 = 3;
    }

    if (tmp < 0.99)
    {
        hit2 = 1;
    }
    else if (tmp < 0.999)
    {
        hit2 = 2;
    }
    else
    {
        hit2 = 3;
    }
    return std::make_pair(hit1, hit2);
}

void Gen()
{

    TFile f("test.root", "recreate");
    TTree tr("tree", "");

    int ADC_1F[16];
    int ADC_1R[8];
    int ADC_2F[16];
    int ADC_2R[8];

    int nHit_1;
    int nHit_2;
    int hitCh_1F;
    int hitCh_1R;
    int hitCh_2F;
    int hitCh_2R;

    tr.Branch("nHit_1", &nHit_1, "nHit_1/I");
    tr.Branch("nHit_2", &nHit_2, "nHit_2/I");
    tr.Branch("hitCh_1F", &hitCh_1F, "hitCH_1F/I");
    tr.Branch("hitCh_1R", &hitCh_1R, "hitCH_1R/I");
    tr.Branch("hitCh_2F", &hitCh_2F, "hitCH_2F/I");
    tr.Branch("hitCh_2R", &hitCh_2R, "hitCH_2R/I");

    tr.Branch("ADC_1F", ADC_1F, "ADC_1F[16]/I");
    tr.Branch("ADC_1R", ADC_1R, "ADC_1R[8]/I");
    tr.Branch("ADC_2F", ADC_2F, "ADC_2F[16]/I");
    tr.Branch("ADC_2R", ADC_2R, "ADC_2R[8]/I");

    const int N = 1000000;
    TRandom3 myRandom;
    myRandom.SetSeed(7);

    for (int i = 0; i < N; ++i)
    {

        for (int ch = 0; ch < 8; ch++)
        {
            ADC_1R[ch] = 0;
            ADC_2R[ch] = 0;
        }

        for (int ch = 0; ch < 16; ch++)
        {
            ADC_1F[ch] = 0;
            ADC_2F[ch] = 0;
        }

        int hit1, hit2;
        std::tie(hit1, hit2) = GenHitNum(myRandom);
        nHit_1 = hit1;
        nHit_2 = hit2;
        hitCh_1F = -1;
        hitCh_1R = -1;
        hitCh_2F = -1;
        hitCh_2R = -1;

        for (int h1 = 0; h1 < hit1; ++h1)
        {
            int ch_f = static_cast<int>(myRandom.Rndm() * 16) % 16;
            int ch_r = static_cast<int>(myRandom.Rndm() * 8) % 8;
            double ene = myRandom.Gaus(2000 + hit1 * 100, 20);
            if (ene < 0)
                ene = 0;
            else if (ene > 16000)
                ene = 16000;
            ADC_1F[ch_f] = ene;
            ADC_1R[ch_r] = ene;
            if (hit1 == 1)
            {
                hitCh_1F = ch_f;
                hitCh_1R = ch_r;
            }
        }

        for (int h2 = 0; h2 < hit2; ++h2)
        {

            int ch_f = static_cast<int>(myRandom.Rndm() * 16) % 16;
            int ch_r = static_cast<int>(myRandom.Rndm() * 8) % 8;
            double ene = myRandom.Gaus(7000 + hit1 * 100, 20);
            if (ene < 0)
                ene = 0;
            else if (ene > 16000)
                ene = 16000;
            ADC_2F[ch_f] = ene;
            ADC_2R[ch_r] = ene;

            if (hit2 == 1)
            {
                hitCh_2F = ch_f;
                hitCh_2R = ch_r;
            }
        }

        tr.Fill();
    }
    tr.Write();
    return;
}