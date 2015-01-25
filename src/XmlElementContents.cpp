#include "XmlElementContents.hpp"
#include "XmlValidation.hpp"
#include "XmlLine.hpp"
#include "Data.hpp"
#include "IResult.hpp"

#include <string>
#include <iostream>

bool XmlElementContents::interpret(XmlLine* xmlLine)
{
  const std::string& input = xmlLine->input();
  size_t start = xmlLine->getCurrIndex();

  if (input[start] == '<')
    return false;

  size_t index = 0;
  size_t end = 0;

  size_t pos = input.find_first_of('<', start);
  if (pos == std::string::npos)
  {
    index = input.length();
    end = pos-start+1;
  }
  else
  {
    index = pos;
    end = pos-start;
  }

  std::string contents = input.substr(start, end);
  result()->add(new Data(validation()->top(), contents));

  xmlLine->setCurrIndex(index);
  return true;
}
