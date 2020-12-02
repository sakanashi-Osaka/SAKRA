#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>

class Config{
public:
  Config(){
    std::ifstream ifs("../config/directory_cfg.txt");
    if(ifs.good()){
      std::map<std::string, std::string> tmp;
      std::string name, cont;
      while(ifs >> name >> cont){
	tmp.insert(std::make_pair(name,cont));
      }
      auto it = tmp.find( "INPUT_DIR");
      if(it != tmp.end())
	fInputDirectory = it->second;
      it = tmp.find( "OUTPUT_DIR");
      if(it != tmp.end())
	fOutputDirectory = it->second;
    }
  };

  std::string GetInputDir()const{return fInputDirectory;};
  std::string GetOutputDir()const{return fOutputDirectory;};
private:
  std::string fInputDirectory;
  std::string fOutputDirectory;
    
};

