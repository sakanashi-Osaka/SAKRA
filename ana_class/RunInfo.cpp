#include <string.h>
#include <stdlib.h>
#include <iostream>

#include "RunInfo.hpp"

ClassImp(TRunInfo)

TRunInfo::TRunInfo(){
};

int TRunInfo::SetValue(char comment[]){
  strncpy(fname,comment,100);
  char temp[100];
  strncpy(temp,&comment[100],100);
  fnum=atoi(temp);
  strncpy(fstart,&comment[200],20);
  strncpy(fstop,&comment[220],20);
  strncpy(fdate,&comment[240],60);
  strncpy(fcomment,&comment[300],200);
  
  return 1;
};

void TRunInfo::Print(){
  std::cout << "Run_Name: " << fname << std::endl;
  std::cout << "Run_Num : " << fnum << std::endl;
  std::cout << "Start   : " << fstart << std::endl;
  std::cout << "Stop    : " << fstop << " " << fdate << std::endl;
  std::cout << "Comment : " << fcomment << std::endl;
  std::cout << std::endl;  
};

int TRunInfo::GetRunNum(){
  return fnum;
};
