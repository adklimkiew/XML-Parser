#include "Parser.hpp"
#include "Result.hpp"

int main()
{
  Parser p("example.xml");
  Result r;
  p.parse(&r);
  
  r.print();
  
  return 0;
}
