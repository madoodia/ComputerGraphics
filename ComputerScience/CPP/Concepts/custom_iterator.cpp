/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>

// create an iterator class
class Array
{
private:
  int* m_array;
  int m_length;

public:
  class Iterator
  {
  private:
    int m_index;
    Array& m_array;

  public:
    Iterator(int index, Array& array) : m_index(index), m_array(array) {}

    bool operator==(const Iterator& other) const
    {
      return m_index == other.m_index;
    }

    bool operator!=(const Iterator& other) const
    {
      return m_index != other.m_index;
    }

    int& operator*() const
    {
      return m_array[m_index];
    }

    void operator++()
    {
      m_index++;
    }
  };

public:
  Array(int length)
  {
    m_array = new int[length];
    m_length = length;
  }

  ~Array()
  {
    delete[] m_array;
  }

  Iterator begin() { return Iterator(0, *this); }
  Iterator end() { return Iterator(m_length, *this); }

  int& operator[](int index)
  {
    return m_array[index];
  }

  int size()
  {
    return m_length;
  }
};

int main()
{
  Array array(5);

  array[0] = 1;
  array[1] = 2;
  array[2] = 3;
  array[3] = 4;
  array[4] = 5;

  Array::Iterator it = array.begin();

  while (it != array.end())
  {
    std::cout << *it << std::endl;
    ++it;
  }

  return 0;
}