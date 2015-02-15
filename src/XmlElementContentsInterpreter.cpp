#include "XmlElementContentsInterpreter.hpp"
#include "XmlValidation.hpp"
#include "XmlLine.hpp"
#include "Data.hpp"
#include "IResult.hpp"

#include <string>
#include <iostream>

bool XmlElementContentsInterpreter::elementMatches(XmlLine* xmlLine)
{
  const std::string& input = xmlLine->input();
  size_t start = xmlLine->getCurrIndex();

  if (input[start] == '<')
    return false;

  return true;
}

bool XmlElementContentsInterpreter::preValidate()
{
  if (!validation()->validateContentsProperlyNested())
  {
    std::cout << "XmlElementContentsInterpreter:: contents not properly nested!" << std::endl;
    return false;
  }
  return true;
}

Data* XmlElementContentsInterpreter::prepareData() const
{
  return const_cast<XmlElementContentsInterpreter*>(this)->result()->getLast();
}

bool XmlElementContentsInterpreter::extractData(const XmlLine* xmlLine, Data* data) const
{
  const std::string& input = xmlLine->input();
  size_t start = xmlLine->getCurrIndex();

  size_t len = 0;
  size_t pos = input.find_first_of('<', start);
  if (pos == std::string::npos)
  {
    pos = input.length();
    len = pos-start+1;
  }
  else
  {
    len = pos-start;
  }

  std::string contents = input.substr(start, len);
  data->setContents(contents);

  std::cout << "interpret extracted contents: " << data->getContents() << std::endl;
  const_cast<size_t&>(_pos) = pos;

  return true;
}

void XmlElementContentsInterpreter::update(XmlLine* xmlLine)
{
  xmlLine->setCurrIndex(_pos);
}

