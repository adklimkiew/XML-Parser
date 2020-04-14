#include "Parser.hpp"
#include "VResult.hpp"
#include "ParseTreeResult.hpp"

#include <cassert>

void test_example_xml()
{
  Parser p("../xml_files/example.xml");
  auto r = new VResult;
  p.parse(r);
  r->print();

  assert(r->size() == 21);

  std::vector<Data*> data;
  std::vector<Attribute*> attributes;

  data = r->find("top");
  assert(data.size() == 1);
  assert(data[0]->getContents().empty() == true);
  assert(data[0]->getAttributes().size() == 0);

  data = r->find("node");
  assert(data.size() == 1);
  assert(data[0]->getContents().empty() == true);
  assert(data[0]->getAttributes().size() == 0);

  data = r->find("hard");
  assert(data.size() == 1);
  assert(data[0]->getContents().empty() == true);
  attributes = data[0]->getAttributes();
  assert(attributes.size() == 2);
  assert(attributes[0]->name() == "test" && attributes[0]->value() == "unit");
  assert(attributes[1]->name() == "architecture" && attributes[1]->value() == "linux64");

  data = r->find("even_harder");
  assert(data.size() == 1);
  assert(data[0]->getContents() == "hidden contents");
  attributes = data[0]->getAttributes();
  assert(attributes.size() == 2);
  assert(attributes[0]->name() == "test" && attributes[0]->value() == "integration");
  assert(attributes[1]->name() == "architecture" && attributes[1]->value() == "win32");

  data = r->find("regular");
  assert(data.size() == 1);
  assert(data[0]->getContents() == "some data");
  assert(data[0]->getAttributes().size() == 0);

  data = r->find("subnode");
  assert(data.size() == 4);
  assert(data[0]->getContents() == "Here");
  attributes = data[0]->getAttributes();
  assert(attributes.size() == 2);
  assert(attributes[0]->name() == "attr" && attributes[0]->value() == "secret");
  assert(attributes[1]->name() == "type" && attributes[1]->value() == "M");

  assert(data[1]->getContents() == "Another line");
  assert(data[1]->getAttributes().size() == 0);

  assert(data[2]->getContents() == "And another line");
  assert(data[2]->getAttributes().size() == 0);

  assert(data[3]->getContents() == "Contains nested elements");
  attributes = data[3]->getAttributes();
  assert(attributes.size() == 1);
  assert(attributes[0]->name() == "id" && attributes[0]->value() == "014");

  data = r->find("car");
  assert(data.size() == 1);
  assert(data[0]->getContents() == "Audi");
  attributes = data[0]->getAttributes();
  assert(attributes.size() == 2);
  assert(attributes[0]->name() == "access" && attributes[0]->value() == "protected");
  assert(attributes[1]->name() == "model" && attributes[1]->value() == "TT");

  data = r->find("tralala");
  assert(data.size() == 2);
  assert(data[0]->getContents() == "XX");
  assert(data[0]->getAttributes().size() == 0);

  assert(data[1]->getContents() == "YY");
  assert(data[1]->getAttributes().size() == 0);

  data = r->find("INNER");
  assert(data.size() == 1);
  assert(data[0]->getContents() == "inner expression");
  assert(data[0]->getAttributes().size() == 0);

  data = r->find("first");
  assert(data.size() == 1);
  assert(data[0]->getContents() == "first");
  assert(data[0]->getAttributes().size() == 0);

  data = r->find("second");
  assert(data.size() == 1);
  assert(data[0]->getContents() == "second");
  assert(data[0]->getAttributes().size() == 0);

  data = r->find("third");
  assert(data.size() == 1);
  assert(data[0]->getContents().empty() == true);
  attributes = data[0]->getAttributes();
  assert(attributes.size() == 3);
  assert(attributes[0]->name() == "colour" && attributes[0]->value() == "red");
  assert(attributes[1]->name() == "shape" && attributes[1]->value() == "circle");
  assert(attributes[2]->name() == "contrast" && attributes[2]->value() == "low");

  data = r->find("FOURTH");
  assert(data.size() == 1);
  assert(data[0]->getContents().empty() == true);
  assert(data[0]->getAttributes().size() == 0);

  data = r->find("oh-dear");
  assert(data.size() == 1);
  assert(data[0]->getContents() == "There is sth in here...");
  assert(data[0]->getAttributes().size() == 0);

  data = r->find("x");
  assert(data.size() == 2);
  assert(data[0]->getContents().empty() == true);
  attributes = data[0]->getAttributes();
  assert(attributes.size() == 1);
  assert(attributes[0]->name() == "size" && attributes[0]->value() == "XXL");

  assert(data[1]->getContents() == "Will it work?");
  assert(data[1]->getAttributes().size() == 0);

  data = r->find("A");
  assert(data.size() == 1);
  assert(data[0]->getContents() == "surprise");
  assert(data[0]->getAttributes().size() == 0);

  delete r;
}

int main()
{
  test_example_xml();

/*
  Parser p2("../xml_files/menu.xml");
  IResult* r = new VResult;
  p2.parse(r);
  r->print();
  delete r;
*/

/*
  Parser p2("../xml_files/example.xml");
  r = new ParseTreeResult;
  p2.parse(r);
  r->print();
  delete r;
*/

  return 0;
}
