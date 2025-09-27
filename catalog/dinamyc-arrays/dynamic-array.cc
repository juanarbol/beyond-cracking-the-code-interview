#include "dynamic-array.h"
#include <iostream>

DynamicArray::DynamicArray() : capacity_(10) {};

size_t DynamicArray::size() { return store_.size(); }
int DynamicArray::capacity() { return capacity_; }

void DynamicArray::append(int n) {
  store_.push_back(n);
  if (size() == capacity_) {  // Grow
    capacity_ *= 2;
    store_.reserve(capacity_);
  }
};

int DynamicArray::get(int i) {
  if (i >= size() || i < 0) return -1;

  return store_[i];
}

void DynamicArray::set(int i, int n) {
  if (i < 0 || i >= size()) return;

  store_[i] = n;
}

int DynamicArray::pop_back() {
  if (store_.empty()) return -1;

  int element = store_.back();
  store_.pop_back();

  // Shrink
  if ((static_cast<int>(size()) / capacity_) < 0.25 && (capacity_ > 10)) {
    capacity_ /= 2;
    store_.resize(capacity_);
  }

  return element;
}
