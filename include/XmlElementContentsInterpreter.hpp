#ifndef XML_ELEMENT_CONTENTS_HPP
#define XML_ELEMENT_CONTENTS_HPP

#include "XmlElementInterpreter.hpp"

class XmlElementContentsInterpreter : public XmlElementInterpreter
{
public:
  XmlElementContentsInterpreter(IResult* result, XmlValidation* validation) : XmlElementInterpreter(result, validation) {}
  RESULT interpret(XmlLine* xmlLine);

protected:
  bool elementMatches(XmlLine* xmlLine);
};

#endif
