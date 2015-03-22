#ifndef XML_COMMENT_ELEMENT_HPP
#define XML_COMMENT_ELEMENT_HPP

#include "XmlElementInterpreter.hpp"

class XmlCommentElementInterpreter : public XmlElementInterpreter
{
public:
  XmlCommentElementInterpreter(IResult* result, XmlValidation* validation) : XmlElementInterpreter(result, validation) {}

protected:
  bool elementMatches(XmlLine* xmlLine);
  bool extractData(const XmlLine* xmlLine, Data* data) const;
  bool postValidate(Data* data) { return true; }
  void update(XmlLine* xmlLine);
  void store(Data* data);

private:
  size_t _pos;
};

#endif
