#ifndef DATA_HPP
#define DATA_HPP

#include "Attribute.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <iterator>

class Data
{
public:
  Data(const std::string& element, const std::string& contents) :
    _contents(contents), _element(element) {}
  
  Data(const std::string& element, const std::vector<Attribute*>& attributes) :
    _element(element)
  {
    _attributes.reserve(attributes.size());
    std::copy(attributes.begin(), attributes.end(), std::back_inserter(_attributes));
  }

  void print() {
    std::cout << _element << ": ";
    if (!_contents.empty())
      std::cout << _contents << std::endl;
    else
      std::cout << std::endl;
    for (size_t i=0; i<_attributes.size(); ++i)
      std::cout << "\t" << _attributes[i]->name() << ": " << _attributes[i]->value() << std::endl;
  }
  
private:
  std::string _contents;
  std::string _element;
  std::vector<Attribute*> _attributes;
};

#endif
