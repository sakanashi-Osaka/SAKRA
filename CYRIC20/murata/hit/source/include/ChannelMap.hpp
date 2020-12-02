#pragma once
#include <iostream>
#include <exception>

class ChannelMap{
public:
  ChannelMap(int _fRunNumber,
	     const int (&_ADC)[3][16],
	     const double (&_Energy)[3][16])
    : fRunNumber(_fRunNumber), fADC(_ADC), fEnergy(_Energy){};

  int ADC_100F(int ch) const{
    if(ch < 0 || 15 < ch )
      throw std::out_of_range("ADC_100F");
    if(!IsBoardSwapped())
      return fADC[1][ch];
    else
      return fADC[0][ch];
  };

  int ADC_500F(int ch) const{
    if(ch < 0 || 15 < ch )
      throw std::out_of_range("ADC_100F");
    if(!IsBoardSwapped())
      return fADC[0][ch];
    else
      return fADC[1][ch];
  };

  int ADC_100R(int ch) const{
    if(ch < 0 || 7 < ch )
      throw std::out_of_range("ADC_100F");
    return fADC[2][ch + 8];
  };

   int ADC_500R(int ch) const{
    if(ch < 0 || 7 < ch )
      throw std::out_of_range("ADC_100F");
    return fADC[2][ch];
  };


  double Energy_100F(int ch) const{
    if(ch < 0 || 15 < ch )
      throw std::out_of_range("ADC_100F");
    if(!IsBoardSwapped())
      return fEnergy[1][ch];
    else
      return fEnergy[0][ch];
  };

  double Energy_500F(int ch) const{
    if(ch < 0 || 15 < ch )
      throw std::out_of_range("ADC_100F");
    if(!IsBoardSwapped())
      return fEnergy[0][ch];
    else
      return fEnergy[1][ch];
  };

  double Energy_100R(int ch) const{
    if(ch < 0 || 7 < ch )
      throw std::out_of_range("ADC_100F");
    return fEnergy[2][ch + 8];
  };

   double Energy_500R(int ch) const{
    if(ch < 0 || 7 < ch )
      throw std::out_of_range("ADC_100F");
    return fEnergy[2][ch];
  };
  

private:
  int fRunNumber;
  bool IsBoardSwapped()const
  {
    return fRunNumber >= 47;
  }
  const int (&fADC)[3][16];
  const double (&fEnergy)[3][16];
};

