#ifndef XML_ELEMENT_CONTENTS_HPP
#define XML_ELEMENT_CONTENTS_HPP

#include "TagInterpreter.hpp"

class XmlElementContents : public TagInterpreter
{
public:
  XmlElementContents(IResult* result, XmlValidation* validation) : TagInterpreter(result, validation) {}
  RESULT interpret(XmlLine* xmlLine);
};

#endif
