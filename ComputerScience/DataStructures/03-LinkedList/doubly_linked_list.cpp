/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>

class Node
{
public:
  int data;
  Node* next;
  Node* prev;
};

class DoublyLinkedList
{
public:
  DoublyLinkedList();
  ~DoublyLinkedList();

  void push_back(int data);
  void push_front(int data);
  void pop_back();
  void pop_front();
  void insert(int data, int index);
  void remove(int index);
  int length() const;
  void print();

private:
  Node* head;
  Node* tail;
  int size;
};

DoublyLinkedList::DoublyLinkedList()
{
  head = nullptr;
  tail = nullptr;
  size = 0;
}

DoublyLinkedList::~DoublyLinkedList()
{
  Node* current = head;
  while (current != nullptr)
  {
    Node* next = current->next;
    delete current;
    current = next;
  }
}

void DoublyLinkedList::push_back(int data)
{
  Node* node = new Node();
  node->data = data;
  node->next = nullptr;
  node->prev = nullptr;

  if (head == nullptr)
  {
    head = node;
    tail = node;
  }
  else
  {
    tail->next = node;
    node->prev = tail;
    tail = node;
  }

  size++;
}

void DoublyLinkedList::push_front(int data)
{
  Node* node = new Node();
  node->data = data;
  node->next = nullptr;
  node->prev = nullptr;

  if (head == nullptr)
  {
    head = node;
    tail = node;
  }
  else
  {
    node->next = head;
    head->prev = node;
    head = node;
  }

  size++;
}

void DoublyLinkedList::pop_back()
{
  if (head == nullptr)
    return;

  if (head == tail)
  {
    delete head;
    head = nullptr;
    tail = nullptr;
  }
  else
  {
    Node* newTail = tail->prev;
    delete tail;
    tail = newTail;
    tail->next = nullptr;
  }

  size--;
}

void DoublyLinkedList::pop_front()
{
  if (head == nullptr)
    return;

  if (head == tail)
  {
    delete head;
    head = nullptr;
    tail = nullptr;
  }
  else
  {
    Node* newHead = head->next;
    delete head;
    head = newHead;
    head->prev = nullptr;
  }

  size--;
}

void DoublyLinkedList::insert(int data, int index)
{
  if (index < 0 || index > size)
    return;

  if (index == 0)
  {
    push_front(data);
    return;
  }

  if (index == size)
  {
    push_back(data);
    return;
  }

  Node* node = new Node();
  node->data = data;
  node->next = nullptr;
  node->prev = nullptr;

  Node* current = head;
  for (int i = 0; i < index - 1; i++)
    current = current->next;

  Node* next = current->next;
  current->next = node;
  node->prev = current;
  node->next = next;
  next->prev = node;

  size++;
}

void DoublyLinkedList::remove(int index)
{
  if (index < 0 || index >= size)
    return;

  if (index == 0)
  {
    pop_front();
    return;
  }

  if (index == size - 1)
  {
    pop_back();
    return;
  }

  Node* current = head;
  for (int i = 0; i < index - 1; i++)
    current = current->next;

  Node* toDelete = current->next;
  Node* next = toDelete->next;
  current->next = next;
  next->prev = current;
  delete toDelete;

  size--;
}

int DoublyLinkedList::length() const
{
  return size;
}

void DoublyLinkedList::print()
{
  Node* current = head;
  while (current != nullptr)
  {
    std::cout << current->data << " ";
    current = current->next;
  }
  std::cout << std::endl;
}

// --------------------------------------------
int main()
{
  DoublyLinkedList list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.push_back(4);

  list.print();

  list.pop_back();
  list.print();

  list.pop_front();
  list.print();

  list.insert(5, 2);
  list.print();

  list.remove(1);
  list.print();

  std::cout << "Length: " << list.length() << std::endl;

  return 0;
}
