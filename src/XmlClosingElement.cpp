#include "XmlClosingElement.hpp"
#include "XmlValidation.hpp"
#include "XmlLine.hpp"

#include <string>
#include <iostream>

bool XmlClosingElement::interpret(XmlLine* xmlLine)
{
  const std::string& input = xmlLine->input();
  size_t start = xmlLine->getCurrIndex();

  std::cout << "interpret: input=" << input << " start:" << start << std::endl;
  std::cout << input[start] << " " << input[start+1] << std::endl;

  if (input[start] == '<' && input[start+1] == '/')
  {
    size_t pos = input.find_first_of('>', start+2);
    std::string tag = input.substr(start+2, pos-1-start-1);
    if (pos == input.length()-1)
      start = input.length();
    else
      start = pos+1;
    std::cout << "interpret:" << tag << std::endl;

    if(!validation()->validate(tag))
    {
      std::cout << "nextToken:" << tag << " top:" << validation()->top() << std::endl;
      return false;
    }

    xmlLine->setCurrIndex(pos+1);
    return true;
  }
  return false;
}
