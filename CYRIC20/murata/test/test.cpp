#include <iostream>
#include <regex>
#include <string>


int ExtractRunNo(std::string _ridf_path){
  std::string obj_str = _ridf_path;
  std::smatch smatch;
  std::regex_search(obj_str, smatch, std::regex("\\d{4}.ridf$"));
  if(smatch.size() == 0){
    std::cerr << "NO pattern found." <<std::endl;
    return -1;
  }
  else if (smatch.size() == 1){
    std::string run_no = smatch[0].str().substr(0,4);
    std::cerr << "FOUND -> " << smatch[0] << " -> " << run_no << std::endl;
    return std::stoi(run_no);
  }
  else{
     std::cerr << "nultiple-hit ?" <<std::endl;
     return -1;
  }
}


int main(int argc, char *argv[]){
  if(argc < 2)
    return 1;

  std::cout << ExtractRunNo(argv[1]) << std::endl;

  return 0;
}
