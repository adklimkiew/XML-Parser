#ifndef IRESULT_HPP
#define IRESULT_HPP

class Data;

class IResult
{
public:
  virtual ~IResult() {}
  virtual void add(Data* data) = 0;
  virtual Data* getLast() = 0;
  virtual void print() const = 0;
};

#endif
