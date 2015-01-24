#include "Parser.hpp"
#include "VResult.hpp"
#include "ParseTreeResult.hpp"

int main()
{
  Parser p("../xml_files/example.xml");
  IResult* r = new VResult;
  p.parse(r);
  r->print();
  delete r;
  
  Parser p2("../xml_files/example.xml");
  r = new ParseTreeResult;
  p2.parse(r);
  r->print();
  delete r;

  return 0;
}
