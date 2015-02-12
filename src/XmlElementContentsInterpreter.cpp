#include "XmlElementContentsInterpreter.hpp"
#include "XmlValidation.hpp"
#include "XmlLine.hpp"
#include "Data.hpp"
#include "IResult.hpp"

#include <string>
#include <iostream>

XmlElementInterpreter::RESULT XmlElementContentsInterpreter::interpret(XmlLine* xmlLine)
{
  const std::string& input = xmlLine->input();
  size_t start = xmlLine->getCurrIndex();

  std::cout << "interpret contents: " << input[start] << " start: " << start << std::endl;

  if (input[start] == '<')
    return XmlElementInterpreter::IGNORED;

  size_t index = 0;
  size_t len = 0;

  size_t pos = input.find_first_of('<', start);
  if (pos == std::string::npos)
  {
    index = input.length();
    len = index-start+1;
  }
  else
  {
    index = pos;
    len = pos-start;
  }

  if (!validation()->validateContentsProperlyNested())
  {
    std::cout << "XmlElementContentsInterpreter:: contents not properly nested!" << std::endl;
    return XmlElementInterpreter::ERROR;
  }

  std::string contents = input.substr(start, len);
  result()->getLast()->update(contents);

  xmlLine->setCurrIndex(index);
  std::cout << "interpret contents:" << contents << "|" << (xmlLine->isAtEnd() ? "end" : "not at end") << std::endl;

  return XmlElementInterpreter::SUCCESS;
}
