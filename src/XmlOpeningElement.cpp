#include "XmlOpeningElement.hpp"
#include "XmlLine.hpp"

#include <string>
#include <iostream>

bool XmlOpeningElement::interpret(XmlLine* xmlLine)
{
  const std::string& input = xmlLine->input();
  size_t start = xmlLine->getCurrIndex();
  std::cout << input << "---" << input.length() << " " << start << std::endl;

  if (input[start] == '<' && input[start+1] != '/')
  {
    size_t pos = input.find_first_of('>', start);
    std::cout << pos << std::endl;
    if (input[pos-1] == '/')
      return false;

    std::string tag = input.substr(start+1, pos-start-1);
    std::cout << tag << std::endl;
    xmlLine->setCurrIndex(pos+1);

    if(!extractAttributes(xmlLine))
      return false;
   
    return true;
  }
  return false;
}
