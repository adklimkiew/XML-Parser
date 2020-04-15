#ifndef PARSE_TREE_HPP
#define PARSE_TREE_HPP

#include <vector>

class Data;

class Node
{
public:
  Node(Data* data) : _data(data), _parent(0) {}
  ~Node() { delete _data; }  

  void addChild(Node* child) {
    if (child)
    {
      _children.push_back(child);
      _parent = this;
    }
  }

  Data* data() const { return _data; }
  Node* getParent() const { return _parent; }
  const std::vector<Node*>& children() const { return _children; }

private:
  Data* _data;
  Node* _parent;
  std::vector<Node*> _children;
};

class ParseTree
{
public:
  ParseTree() : _root(0), _currentNode(0) {}
  ~ParseTree() { /*remove all nodes...*/ }

  void add(Node* node) {
    if (_root == 0){
      _root = node;
      _currentNode = _root;
      return;
    }
    
    _currentNode->addChild(node);
    _currentNode = node;
  }

  Node* getCurrent() const { return _currentNode; }

  void moveUp() { _currentNode = _currentNode->getParent(); }

  void print() {
    print(_root);
  }

private:
  void print(const Node* node) {
    if (node == 0)
      return;
    node->data()->print();
    for (size_t i=0; i<node->children().size(); ++i)
      print(node->children()[i]);
  }

private:
  Node* _root;
  Node* _currentNode;
};

#endif
