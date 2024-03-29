#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <stdexcept>

template <typename T>
class Array
{
  T *data;
  size_t size;
  size_t capacity;

public:
  Array() : data{nullptr}, size{0}, capacity{0}
  {
  }
  explicit Array(size_t size) : data{new T[Array::powerOf2(size)]}, size{size}, capacity{Array::powerOf2(size)}
  {
    for (size_t i{}; i < size; ++i)
    {
      data[i] = 0;
    }
  }

  Array(const T *elements, size_t size) : data{new T[Array::powerOf2(size)]}, size{size}, capacity{Array::powerOf2(size)}
  {
    for (size_t i{}; i < size; ++i)
    {
      data[i] = elements[i];
    }
  }

  Array(const Array &other) : data{new T[other.capacity]}, size{other.size}, capacity{other.capacity}
  {
    for (size_t i{}; i < size; ++i)
    {
      data[i] = other.data[i];
    }
  }

  Array &operator=(const Array &other)
  {
    if (this != &other)
    {
      T *temp = new T[other.capacity];
      for (size_t i = 0; i < other.size; ++i)
      {
        temp[i] = other.data[i];
      }
      delete[] data;
      data = temp;
      size = other.size;
      capacity = other.capacity;
    }
    return *this;
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

  size_t getSize() const { return size; }
  size_t getCapacity() const { return capacity; }

  static size_t powerOf2(size_t num)
  {
    if (num == 0)
      return num;
    size_t power = 1;
    while (power < num)
    {
      power <<= 1;
    }

    return power;
  }

  void resize(size_t newCapacity)
  {
    capacity = newCapacity;
    T *newData = new T[newCapacity];
    for (size_t i{}; i < size; ++i)
    {
      newData[i] = data[i];
    }
    delete[] data;
    data = newData;
  }

  void addElement(T element)
  {
    if (size == capacity)
    {
      resize(Array::powerOf2(size + 1));
    }
    size += 1;
    data[size - 1] = element;
  }
};

#endif