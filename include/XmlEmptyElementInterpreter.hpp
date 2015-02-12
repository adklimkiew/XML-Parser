#ifndef XML_EMPTY_ELEMENT_HPP
#define XML_EMPTY_ELEMENT_HPP

#include "XmlElementInterpreter.hpp"

class XmlEmptyElementInterpreter : public XmlElementInterpreter
{
public:
  XmlEmptyElementInterpreter(IResult* result, XmlValidation* validation) : XmlElementInterpreter(result, validation) {}
  RESULT interpret(XmlLine* xmlLine);
};

#endif
