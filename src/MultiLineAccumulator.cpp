#include "MultiLineAccumulator.hpp"

void MultiLineAccumulator::tryToMerge(const std::string& str)
{
  size_t pos = str.find_first_of('>');
  if (pos == std::string::npos && str[0] == '<' && !_mergeInProgress)
  {
    _mergeInProgress = true;
  }

  if (_mergeInProgress)
  {
    if(_mergedString.empty())
      _mergedString += str;
    else
      _mergedString += " " + str;
  }

  if(pos != std::string::npos && _mergeInProgress)
  {
    _mergeInProgress = false;
    _isMergeFinished = true;
  }
}

void MultiLineAccumulator::reset()
{
  _mergeInProgress = false;
  _isMergeFinished = false;
  _mergedString.erase();
}    
