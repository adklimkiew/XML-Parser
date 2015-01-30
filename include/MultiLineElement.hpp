#ifndef MULTI_LINE_ELEMENT_HPP
#define MULTI_LINE_ELEMENT_HPP

#include <vector>

class Attribute;

class MultiLineElement
{
public:
  void insert(std::vector<Attribute*>& vAttributes) {
    for (size_t i=0; i<vAttributes.size(); ++i)
      _attributes.push_back(vAttributes[i]);  
  }

  std::vector<Attribute*> _attributes;
  std::vector _tag;
};

#endif
