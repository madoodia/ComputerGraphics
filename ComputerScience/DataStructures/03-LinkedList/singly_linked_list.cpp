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
};

class SinglyLinkedList
{
public:
  SinglyLinkedList();
  SinglyLinkedList(int data);
  SinglyLinkedList(int data, Node* next);
  SinglyLinkedList(Node* next);
  ~SinglyLinkedList();

  void pushBack(int data);
  void pushFront(int data);

  void insert(int data);
  void insert(int data, int index);
  void insert(int data, Node* next);
  void insert(int data, int index, Node* next);

  void popBack();
  void popFront();

  void remove(int index);
  void remove(Node* node);
  void remove(int index, bool all);

  void clear();
  int getSize();
  bool isEmpty();

  void print();

private:
  Node* head;
  Node* tail;
  int size;
};

SinglyLinkedList::SinglyLinkedList()
{
  head = NULL;
  tail = NULL;
  size = 0;
}

SinglyLinkedList::SinglyLinkedList(int data)
{
  head = new Node();
  head->data = data;
  head->next = NULL;
  tail = head;
  size = 1;
}

SinglyLinkedList::SinglyLinkedList(int data, Node* next)
{
  head = new Node();
  head->data = data;
  head->next = next;
  tail = head;
  size = 1;
}

SinglyLinkedList::SinglyLinkedList(Node* next)
{
  head = next;
  tail = head;
  size = 1;
}

SinglyLinkedList::~SinglyLinkedList()
{
  Node* current = head;
  Node* next = NULL;

  while (current != NULL)
  {
    next = current->next;
    delete current;
    current = next;
  }

  head = NULL;
  tail = NULL;
  size = 0;
}

void SinglyLinkedList::pushBack(int data)
{
  if (head == NULL)
  {
    head = new Node();
    head->data = data;
    head->next = NULL;
    tail = head;
  }
  else
  {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
  }
  size++;
}

void SinglyLinkedList::pushFront(int data)
{
  if (head == NULL)
  {
    head = new Node();
    head->data = data;
    head->next = NULL;
    tail = head;
  }
  else
  {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
  }
  size++;
}

void SinglyLinkedList::insert(int data)
{
  pushBack(data);
}

void SinglyLinkedList::insert(int data, int index)
{
  if (index == 0)
  {
    pushFront(data);
  }
  else if (index == size)
  {
    pushBack(data);
  }
  else if (index > 0 && index < size)
  {
    Node* current = head;
    Node* previous = NULL;
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    for (int i = 0; i < index; i++)
    {
      previous = current;
      current = current->next;
    }

    previous->next = newNode;
    newNode->next = current;
    size++;
  }
  else
  {
    std::cout << "Index out of range!" << std::endl;
  }
}

void SinglyLinkedList::insert(int data, Node* next)
{
  Node* newNode = new Node();
  newNode->data = data;
  newNode->next = next;
  tail->next = newNode;
  tail = newNode;
  size++;
}

void SinglyLinkedList::insert(int data, int index, Node* next)
{
  if (index == 0)
  {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    size++;
  }
  else if (index == size)
  {
    insert(data, next);
  }
  else if (index > 0 && index < size)
  {
    Node* current = head;
    Node* previous = NULL;
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = next;

    for (int i = 0; i < index; i++)
    {
      previous = current;
      current = current->next;
    }

    previous->next = newNode;
    newNode->next = current;
    size++;
  }
  else
  {
    std::cout << "Index out of range!" << std::endl;
  }
}

void SinglyLinkedList::popBack()
{
  if (head != NULL)
  {
    if (head == tail)
    {
      delete head;
      head = NULL;
      tail = NULL;
    }
    else
    {
      Node* current = head;
      Node* previous = NULL;

      while (current->next != NULL)
      {
        previous = current;
        current = current->next;
      }

      delete current;
      previous->next = NULL;
      tail = previous;
    }
    size--;
  }
}

void SinglyLinkedList::popFront()
{
  if (head != NULL)
  {
    if (head == tail)
    {
      delete head;
      head = NULL;
      tail = NULL;
    }
    else
    {
      Node* current = head;
      head = head->next;
      delete current;
    }
    size--;
  }
}

void SinglyLinkedList::remove(int index)
{
  if (index == 0)
  {
    popFront();
  }
  else if (index == size - 1)
  {
    popBack();
  }
  else if (index > 0 && index < size - 1)
  {
    Node* current = head;
    Node* previous = NULL;

    for (int i = 0; i < index; i++)
    {
      previous = current;
      current = current->next;
    }

    previous->next = current->next;
    delete current;
    size--;
  }
  else
  {
    std::cout << "Index out of range!" << std::endl;
  }
}

void SinglyLinkedList::remove(Node* node)
{
  if (node == head)
  {
    popFront();
  }
  else if (node == tail)
  {
    popBack();
  }
  else
  {
    Node* current = head;
    Node* previous = NULL;

    while (current != node)
    {
      previous = current;
      current = current->next;
    }

    previous->next = current->next;
    delete current;
    size--;
  }
}

void SinglyLinkedList::remove(int data, bool all)
{
  if (head != NULL)
  {
    Node* current = head;
    Node* previous = NULL;

    while (current != NULL)
    {
      if (current->data == data)
      {
        if (current == head)
        {
          popFront();
          current = head;
        }
        else if (current == tail)
        {
          popBack();
          current = NULL;
        }
        else
        {
          previous->next = current->next;
          delete current;
          current = previous->next;
          size--;
        }
        if (!all)
        {
          break;
        }
      }
      else
      {
        previous = current;
        current = current->next;
      }
    }
  }
}

void SinglyLinkedList::clear()
{
  while (head != NULL)
  {
    popFront();
  }
}

int SinglyLinkedList::getSize()
{
  return size;
}

bool SinglyLinkedList::isEmpty()
{
  return size == 0;
}

void SinglyLinkedList::print()
{
  Node* current = head;
  while (current != NULL)
  {
    std::cout << current->data << " ";
    current = current->next;
  }
  std::cout << std::endl;
}

int main()
{
  SinglyLinkedList list;

  std::cout << "List is empty: " << list.isEmpty() << std::endl;

  list.pushBack(1);
  list.pushBack(2);
  list.pushBack(3);
  list.pushBack(4);
  list.pushBack(5);
  list.pushBack(6);
  list.pushBack(7);
  list.pushBack(8);

  list.pushFront(10);
  list.pushFront(20);

  list.remove(5);
  list.print();
  std::cout << "List Size: " << list.getSize() << std::endl;

  list.remove(1, true);
  list.print();
  std::cout << "List Size: " << list.getSize() << std::endl;

  return 0;
}