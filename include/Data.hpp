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
  Data() {}
  ~Data() {
    for (size_t i=0; i<_attributes.size(); ++i)
      delete _attributes[i];
  }

  void setTag(const std::string& tag) { _tag = tag; }
  void setContents(const std::string& contents) { _contents = contents; }
  void setAttributes(const std::vector<Attribute*>& attributes) {
    _attributes.reserve(attributes.size());
    std::copy(attributes.begin(), attributes.end(), std::back_inserter(_attributes));
  }

  const std::string& getTag() const { return _tag; }
  const std::string& getContents() const { return _contents; }
  const std::vector<Attribute*>& getAttributes() const { return _attributes; }
 
  void print() const {
    std::cout << _tag << ": ";
    if (!_contents.empty())
      std::cout << _contents << std::endl;
    else
      std::cout << std::endl;
    for (size_t i=0; i<_attributes.size(); ++i)
      std::cout << "\t" << _attributes[i]->name() << ": " << _attributes[i]->value() << std::endl;
  }
  
private:
  std::string _contents;
  std::string _tag;
  std::vector<Attribute*> _attributes;
};

#endif
