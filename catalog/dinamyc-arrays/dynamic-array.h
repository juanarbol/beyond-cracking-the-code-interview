#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdlib.h>
#include <vector>

class DynamicArray {
public:
  DynamicArray();
  ~DynamicArray() = default;

  void append(int n);
  int get(int i);
  void set(int i, int n);
  size_t size();
  int capacity();  /* for testing only */
  int pop_back();
private:
  int capacity_;
  std::vector<int> store_;
};

#endif // DYNAMIC_ARRAY_H
