#include "XmlCommentElementInterpreter.hpp"
#include "XmlLine.hpp"

#include <string>
#include <iostream>

bool XmlCommentElementInterpreter::elementMatches(XmlLine* xmlLine)
{
  const std::string& input = xmlLine->input();
  size_t start = xmlLine->getCurrIndex();

  std::cout << "Comment elem interpret:" << input << "---" << input.length() << " " << start << std::endl;

  if (input[start] == '<' && input[start+1] == '!' && input[start+2] == '-' && input[start+2] == '-')
  {
    _pos = input.find("-->", start);
    if (_pos == std::string::npos)
      return false;

    std::cout << "OK! _pos=" << _pos << " start: " << start << std::endl;
    _pos += 2;
    return true;
  }
  return false;
}

bool XmlCommentElementInterpreter::extractData(const XmlLine* xmlLine, Data* data) const
{
  return true;
}

void XmlCommentElementInterpreter::store(Data* data)
{
  delete data;
}

void XmlCommentElementInterpreter::update(XmlLine* xmlLine)
{
  xmlLine->setCurrIndex(_pos+1);
}
