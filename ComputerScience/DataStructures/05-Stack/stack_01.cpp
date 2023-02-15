/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>

class Stack
{
public:
  Stack(); // size 3 by default
  Stack(int size);
  ~Stack();

  void push(int value);
  int pop();

  int peek();

  bool isEmpty();
  bool isFull();

  int size();

  void print();

private:
  int* m_array;
  int m_size;
  int m_top;
};

Stack::Stack()
    : m_size(3), m_top(-1)
{
  m_array = new int[m_size];
}

Stack::Stack(int size)
    : m_size(size), m_top(-1)
{
  m_array = new int[m_size];
}

Stack::~Stack()
{
  delete[] m_array;
}

void Stack::push(int value)
{
  if (isFull())
  {
    std::cout << "Stack is full!" << std::endl;
    return;
  }

  m_array[++m_top] = value;
}

int Stack::pop()
{
  if (isEmpty())
  {
    std::cout << "Stack is empty!" << std::endl;
    return -1;
  }

  return m_array[m_top--];
}

int Stack::peek()
{
  if (isEmpty())
  {
    std::cout << "Stack is empty!" << std::endl;
    return -1;
  }

  return m_array[m_top];
}

bool Stack::isEmpty()
{
  return m_top == -1;
}

bool Stack::isFull()
{
  return m_top == m_size - 1;
}

int Stack::size()
{
  return m_size;
}

void Stack::print()
{
  std::cout << "Stack: ";
  for (int i = 0; i <= m_top; i++)
  {
    std::cout << m_array[i] << " ";
  }
  std::cout << std::endl;
}

// -----------------------------------------
int main()
{
  Stack stack(5);

  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.push(4);
  stack.push(5);

  stack.print();

  stack.pop();
  stack.pop();

  stack.print();

    return 0;
}