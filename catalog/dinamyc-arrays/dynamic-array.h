#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdexcept>

class DynamicArray {
private:
  int* arr;
  int capacity;
  int size;

  void resize() {
    capacity *= 2;
    int* newArr = new int[capacity];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
  }
public:
  DynamicArray() : capacity(2), size(0) {
    arr = new int[capacity];
  }

  ~DynamicArray() {
    delete[] arr;
  }

  void add(int value) {
    if (size == capacity) {
      resize();
    }
    arr[size++] = value;
  }

  void remove() {
    if (size > 0) {
      size--;
    }
  }

  int get(int index) const {
    if (index < 0 || size == 0 || index >= size) {
      throw std::out_of_range("Index out of range");
    }

    return arr[index];
  }

  int getSize() const {
    return size;
  }
};

#endif // DYNAMIC_ARRAY_H
