#ifndef MULTI_LINE_ACCUMULATOR
#define MULTI_LINE_ACCUMULATOR

#include <string>

class MultiLineAccumulator
{
public:
  MultiLineAccumulator() : _mergeInProgress(false), _isMergeFinished(false) {}

  void tryToMerge(const std::string& str);
  bool isMergeInProgress() const { return _mergeInProgress; }
  bool isMergeFinished() const { return _isMergeFinished; }
  std::string getMerged() const { return _mergedString; }

  void reset();

private:
  std::string _mergedString;
  bool _mergeInProgress;
  bool _isMergeFinished;
};

#endif
