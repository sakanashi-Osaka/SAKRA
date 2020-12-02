#ifndef _V1730ZLEHEADER_HPP_
#define _V1730ZLEHEADER_HPP_

#include <TObject.h>
#include <bitset>

class TV1730ZLEHeader : public TObject{
private:
public:
  TV1730ZLEHeader();
  int event_size;
  bool board_fail_flag;

  void Clear();

  ClassDef(TV1730ZLEHeader,1);
};

#endif
