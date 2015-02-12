#include "XmlClosingElementInterpreter.hpp"
#include "XmlValidation.hpp"
#include "XmlLine.hpp"

#include <string>
#include <iostream>

XmlElementInterpreter::RESULT XmlClosingElementInterpreter::interpret(XmlLine* xmlLine)
{
  const std::string& input = xmlLine->input();
  size_t start = xmlLine->getCurrIndex();

  std::cout << "interpret closing element: input=" << input << " start:" << start << std::endl;
  std::cout << input[start] << " " << input[start+1] << std::endl;

  if(!elementMatches(xmlLine))
    return XmlElementInterpreter::IGNORED;

  size_t pos = input.find_first_of('>', start+2); // pos == npos ?? TBD...
  std::string tag = input.substr(start+2, pos-1-start-1);
  if (pos == input.length()-1)
    start = input.length();
  else
    start = pos+1;
  std::cout << "XmlClosingElementInterpreter::interpret tag:" << tag << "|" << std::endl;

  if (!validation()->validate(tag))
  {
    std::cout << "XmlClosingElementInterpreter::interpret validation failed tag :" << tag << " onTop:" << validation()->top() << std::endl;
    return XmlElementInterpreter::ERROR;
  }
    
  validation()->pop();

  xmlLine->setCurrIndex(pos+1);
  return XmlElementInterpreter::SUCCESS;
}

bool XmlClosingElementInterpreter::elementMatches(XmlLine* xmlLine)
{
  const std::string& input = xmlLine->input();
  size_t start = xmlLine->getCurrIndex();

  if (input[start] == '<' && input[start+1] == '/')
    return true;

  return false;
}
