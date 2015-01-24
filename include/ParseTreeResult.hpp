#ifndef PARSE_TREE_RESULT_HPP
#define PARSE_TREE_RESULT_HPP

#include "IResult.hpp"
#include "ParseTree.hpp"

class ParseTreeResult : public IResult
{
public:
  ParseTreeResult() : _tree(new ParseTree()) {}
  ~ParseTreeResult() { delete _tree; }

  void add(Data* data){
    _tree->add(new Node(data));
  }

  Data* getLast() { return _tree->getCurrent()->data(); }
  
  void print() const { _tree->print(); }

private:
  ParseTree* _tree;
};

#endif
