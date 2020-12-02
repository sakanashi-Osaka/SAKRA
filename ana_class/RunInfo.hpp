#ifndef _RUNINFO_HPP_
#define _RUNINFO_HPP_

#include <TObject.h>

class TRunInfo : public TObject{
public:
  TRunInfo();
  int SetValue(char comment[]);
  void Print();
  int GetRunNum();
private:
  char fname[100];
  int fnum;
  char fstart[20];
  char fstop[20];
  char fdate[60];
  char fcomment[200];

  ClassDef(TRunInfo,1);
};

#endif
