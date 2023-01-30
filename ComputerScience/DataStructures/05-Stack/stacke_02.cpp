/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>

// implement stack class using linkedlist
class Stack
{
public:
  Stack();
  Stack(int size);
  ~Stack();

  void push(int value);
  void pop();
  int size();

  void print();

private:
  struct Node
  {
    int value;
    Node* next;
  };

  Node* m_head;
  Node* m_tail;
  int m_size;
};

Stack::Stack()
{
  m_head = nullptr;
  m_tail = nullptr;
  m_size = 0;
}

Stack::Stack(int size)
{
  m_head = nullptr;
  m_tail = nullptr;
  m_size = size;
}

Stack::~Stack()
{
  Node* current = m_head;
  Node* next = nullptr;

  while (current != nullptr)
  {
    next = current->next;
    delete current;
    current = next;
  }

  m_head = nullptr;
  m_tail = nullptr;
}

void Stack::push(int value)
{
  Node* node = new Node();
  node->value = value;
  node->next = nullptr;

  if (m_head == nullptr)
  {
    m_head = node;
    m_tail = node;
  }
  else
  {
    m_tail->next = node;
    m_tail = node;
  }
}

void Stack::pop()
{
  if (m_head == nullptr)
  {
    std::cout << "Stack is empty" << std::endl;
    return;
  }

  Node* current = m_head;
  Node* next = nullptr;

  while (current->next != nullptr)
  {
    next = current;
    current = current->next;
  }

  delete current;
  next->next = nullptr;
  m_tail = next;
}

void Stack::print()
{
  Node* current = m_head;

  std::cout << "Stack: ";
  while (current != nullptr)
  {
    std::cout << current->value << " ";
    current = current->next;
  }
  std::cout << std::endl;
}

int Stack::size()
{
  return m_size;
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