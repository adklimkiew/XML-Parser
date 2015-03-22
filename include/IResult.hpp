#ifndef IRESULT_HPP
#define IRESULT_HPP

#include <string>
#include <vector>

class Data;

class IResult
{
public:
  virtual ~IResult() {}
  virtual void add(Data* data) = 0;
  virtual Data* getLast() = 0;
  virtual void print() const = 0;
  virtual size_t size() const = 0;
  virtual std::vector<Data*> find(const std::string& tag) = 0;
};

#endif
