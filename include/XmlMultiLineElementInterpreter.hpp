#ifndef XML_MULTI_LINE_ELEMENT_HPP
#define XML_MULTI_LINE_ELEMENT_HPP

#include "TagInterpreter.hpp"

class MultiLineElement;

class XmlMultiLineElementInterpreter : public TagInterpreter
{
public:
  XmlMultiLineElementInterpreter(IResult* result, XmlValidation* validation) :
    TagInterpreter(result, validation), _multiLineElement(NULL) {}
  RESULT interpret(XmlLine* xmlLine);

private:
  MultiLineElement* _multiLineElement;
};

#endif
