#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <iostream>

class Data
{
public:
  Data(const std::string& contents, const std::string& descr) :
    _contents(contents), _description(descr) {}
  
  void print() {
    std::cout << _description << ": " << _contents << std::endl;
  }
  
private:
  std::string _contents;
  std::string _description;
};

#endif
