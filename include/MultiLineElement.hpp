#ifndef MULTI_LINE_ELEMENT_HPP
#define MULTI_LINE_ELEMENT_HPP

#include <vector>
#include <string>

class Attribute;

class MultiLineElement
{
public:
  void add(std::vector<Attribute*>& vAttributes) {
    for (size_t i=0; i<vAttributes.size(); ++i)
      _attributes.push_back(vAttributes[i]);  
  }

  const std::vector<Attribute*>& attributes() const { return _attributes; }

  std::string _tag;

private:
  std::vector<Attribute*> _attributes;
};

#endif
