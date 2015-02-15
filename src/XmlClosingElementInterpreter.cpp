#include "XmlClosingElementInterpreter.hpp"
#include "XmlValidation.hpp"
#include "XmlLine.hpp"

#include <string>
#include <iostream>

bool XmlClosingElementInterpreter::elementMatches(XmlLine* xmlLine)
{
  const std::string& input = xmlLine->input();
  size_t start = xmlLine->getCurrIndex();

  if (input[start] == '<' && input[start+1] == '/')
    return true;

  return false;
}

bool XmlClosingElementInterpreter::extractData(const XmlLine* xmlLine, Data* data) const
{
  const std::string& input = xmlLine->input();
  size_t start = xmlLine->getCurrIndex();

  std::cout << "interpret closing element: input=" << input << " start:" << start << std::endl;
  std::cout << input[start] << " " << input[start+1] << std::endl;

  const_cast<size_t&>(_pos) = input.find_first_of('>', start+2); // pos == npos ?? TBD...
  std::string tag = input.substr(start+2, _pos-1-start-1);

  data->setTag(tag);

  return true;
}

bool XmlClosingElementInterpreter::postValidate(Data* data)
{
  if (!validation()->validate(data->getTag()))
  {
    std::cout << "XmlClosingElementInterpreter::interpret validation failed tag :" << data->getTag() << " onTop:" << validation()->top() << std::endl;
    return false;
  }
    
  validation()->pop();
  return true;
}

void XmlClosingElementInterpreter::store(Data* data)
{
  delete data;
}

void XmlClosingElementInterpreter::update(XmlLine* xmlLine)
{
  xmlLine->setCurrIndex(_pos+1);
}
