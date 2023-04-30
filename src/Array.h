#ifndef _ARRAY_H_
#define _ARRAY_H_

template <typename T>
class Array
{
  T *data;
  size_t size;

public:
  Array() : data{nullptr}, size{0} {}
  explicit Array(size_t size) : data{new T[size]}, size{size} {}
  Array(const T *elements, size_t size) : data{new T[size]}, size{size}
  {
    for (size_t i{}; i < size; ++i)
    {
      data[i] = elements[i];
    }
  }
  ~Array()
  {
    delete[] data;
  }
};

#endif