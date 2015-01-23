#ifndef RESULT_HPP
#define RESULT_HPP

#include "Data.hpp"

#include <vector>

class Result
{
public:
  void add(Data* data)
  {
    _results.push_back(data);
  }

  void print() const;

private:
  std::vector<Data*> _results;
};

#endif
