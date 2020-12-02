#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

class CalibPar{
public:
  CalibPar(const std::string &_file)
  {
    std::ifstream ifs(_file.c_str());
    if(!ifs.good())
      return;
    else
      {
	int board, ch;
	double par;
	while(ifs >> board >> ch >> par){
	  //	  std::cout << board << " " << ch << " " <<par <<std::endl;
	  fParameters.push_back(std::make_pair(Address(board, ch), par));
	}

      }
  };

  using par_type = double;
  par_type GetPar(int _board_id, int _ch)
  {
    auto it = std::find_if(fParameters.begin(),
			   fParameters.end(),
			   [&](std::pair<Address, par_type> &_par){
			     return _par.first == Address(_board_id, _ch);
			   });
    if(it != fParameters.end())
    {
      return it->second;
    }
    throw std::out_of_range("Invalid access to CalibPar : board = " + std::to_string(_board_id) + " ch = " +std::to_string(_ch));
    
  }

  struct Address{
    Address() : fBoard(-1), fCh(-1){};
    Address(int _fBoard, int _fCh) : fBoard(_fBoard), fCh(_fCh){};
    bool operator==(Address _rhs) const
    {
      return fBoard == _rhs.fBoard && fCh == _rhs.fCh;
    };
   
    int fBoard, fCh;
  };

private:

  std::vector<std::pair<Address, par_type>> fParameters;
};


int main(int argc, char*argv[])
{
  if(argc < 2)
    return 1;

  CalibPar par(argv[1]);

  std::cout << par.GetPar(0, 9) << std::endl;
  std::cout << par.GetPar(1, 9) << std::endl;
  std::cout << par.GetPar(2, 9) << std::endl;
  //  std::cout << par.GetPar(9999, 9999) << std::endl;

  return 0;
}
