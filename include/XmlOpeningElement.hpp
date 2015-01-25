#ifndef XML_OPENING_ELEMENT_HPP
#define XML_OPENING_ELEMENT_HPP

#include "TagInterpreter.hpp"

class XmlOpeningElement : public TagInterpreter
{
public:
  bool interpret(XmlLine* xmlLine);

};

#endif
