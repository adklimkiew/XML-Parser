#include "TagInterpreter.hpp"
#include "XmlLine.hpp"
#include "Attribute.hpp"
#include "IResult.hpp"
#include "Data.hpp"
#include "XmlValidation.hpp"

#include <iostream>

bool TagInterpreter::extractAttributes(const XmlLine* xmlLine, std::string& tag)
{
  const std::string& input = xmlLine->input();
  size_t start = xmlLine->getCurrIndex();

  size_t pos = input.find_first_of(" >", start);
  std::cout << "extractAttributes: copy range" << start+1 << ", " << pos-start-1<< std::endl;
  tag = input.substr(start+1, pos-start-1);

  std::cout << "extractAttributes: tag to push:" << tag << "| pos:" << pos << " start:" << start << std::endl;

  std::vector<Attribute*> attributes;

  while (pos != std::string::npos)
  {
    pos = input.find_first_of('=', pos);
    if (pos == std::string::npos)
      break;

    if (!extractAttribute(input, pos, attributes))
      return false;
  }

//  if (attributes.size() > 0)
    result()->add(new Data(tag, attributes));

  std::cout << "extractAttributes: attributes.size:" << attributes.size() << std::endl;

  return true;
}

bool TagInterpreter::extractAttribute(const std::string& input, size_t& pos, std::vector<Attribute*>& results)
{
  size_t index = pos-1;
  std::cout << pos << " " << input[pos] << std::endl;
  while(input[index] == ' ')
    --index;
  size_t end = index;

  while(input[index] != ' ')
    --index;
  std::string attrName = input.substr(index+1, end-index);

  std::cout << attrName << " " << index << ", " << end << std::endl;

  index = pos+1;
  while(input[index] == ' ')
    ++index;

  if (input[index] != '\"')
    return false;
  
  end = index+1;
  while(input[end] != '\"')
    ++end;

  std::string attrValue = input.substr(index+1, end-index-1);

  std::cout << attrValue << " " << index << ", " << end << std::endl;

  pos = end+1;

  results.push_back(new Attribute(attrName, attrValue));

  return true;
}
