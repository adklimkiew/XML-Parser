#ifndef ATTRIBUTE_HPP
#define ATTRIBUTE_HPP

#include <string>

class Attribute
{
public:
  Attribute(const std::string& name, const std::string value) :
    _name(name), _value(value) {}

  const std::string& name() const { return _name; }
  const std::string& value() const { return _value; }

private:
  std::string _name;
  std::string _value;
};

#endif
