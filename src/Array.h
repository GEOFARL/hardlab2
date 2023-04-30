#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <stdexcept>

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

  T &operator[](size_t index)
  {
    if (index >= size)
    {
      throw std::out_of_range("Index out of range");
    }
    return data[index];
  }

  const T &operator[](size_t index) const
  {
    if (index >= size)
    {
      throw std::out_of_range("Index out of range");
    }
    return data[index];
  }
};

#endif