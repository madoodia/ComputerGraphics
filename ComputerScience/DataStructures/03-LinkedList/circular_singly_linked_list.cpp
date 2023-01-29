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

class CircularSinglyLinkedList
{
public:
  CircularSinglyLinkedList();
  ~CircularSinglyLinkedList();

  void pushBack(int data);
  void pushFront(int data);
  void popBack();
  void popFront();
  void insert(int data);
  void remove(int data);
  int length();
  void print();

private:
  Node* head;
  Node* tail;
  int size;
};

CircularSinglyLinkedList::CircularSinglyLinkedList()
{
  head = NULL;
  tail = NULL;
  size = 0;
}

CircularSinglyLinkedList::~CircularSinglyLinkedList()
{
  Node* current = head;
  Node* next = NULL;

  while(current != NULL)
  {
    next = current->next;
    delete current;
    current = next;
  }

  head = NULL;
  tail = NULL;
  size = 0;
}


void CircularSinglyLinkedList::pushBack(int data)
{
  Node* newNode = new Node();
  newNode->data = data;
  newNode->next = NULL;

  if(head == NULL)
  {
    head = newNode;
    tail = newNode;
    newNode->next = head;
  }
  else
  {
    tail->next = newNode;
    tail = newNode;
    tail->next = head;
  }

  size++;
}

void CircularSinglyLinkedList::pushFront(int data)
{
  Node* newNode = new Node();
  newNode->data = data;
  newNode->next = NULL;

  if(head == NULL)
  {
    head = newNode;
    tail = newNode;
    newNode->next = head;
  }
  else
  {
    newNode->next = head;
    head = newNode;
    tail->next = head;
  }

  size++;
}

void CircularSinglyLinkedList::popBack()
{
  if(head == NULL)
  {
    std::cout << "List is empty" << std::endl;
    return;
  }

  Node* current = head;
  Node* previous = NULL;

  while(current->next != head)
  {
    previous = current;
    current = current->next;
  }

  tail = previous;
  tail->next = head;
  delete current;
  size--;
}

void CircularSinglyLinkedList::popFront()
{
  if(head == NULL)
  {
    std::cout << "List is empty" << std::endl;
    return;
  }

  Node* current = head;
  head = head->next;
  tail->next = head;
  delete current;
  size--;
}

void CircularSinglyLinkedList::insert(int data)
{
  if(head == NULL)
  {
    std::cout << "List is empty" << std::endl;
    return;
  }

  Node* newNode = new Node();
  newNode->data = data;
  newNode->next = NULL;

  Node* current = head;
  Node* previous = NULL;

  while(current->data < data)
  {
    previous = current;
    current = current->next;
  }

  if(current == head)
  {
    pushFront(data);
  }
  else
  {
    previous->next = newNode;
    newNode->next = current;
    size++;
  }
}

void CircularSinglyLinkedList::remove(int data)
{
  if(head == NULL)
  {
    std::cout << "List is empty" << std::endl;
    return;
  }

  Node* current = head;
  Node* previous = NULL;

  while(current->data != data)
  {
    previous = current;
    current = current->next;
  }

  if(current == head)
  {
    popFront();
  }
  else if(current == tail)
  {
    popBack();
  }
  else
  {
    previous->next = current->next;
    delete current;
    size--;
  }
}

int CircularSinglyLinkedList::length()
{
  return size;
}

void CircularSinglyLinkedList::print()
{
  if(head == NULL)
  {
    std::cout << "List is empty" << std::endl;
    return;
  }

  Node* current = head;

  while(current->next != head)
  {
    std::cout << current->data << " ";
    current = current->next;
  }

  std::cout << current->data << std::endl;
}

int main()
{
  CircularSinglyLinkedList list;

  list.pushBack(1);
  list.pushBack(2);
  list.pushBack(3);
  list.pushBack(4);
  list.pushBack(5);
  list.pushBack(6);
  list.pushBack(7);
  list.pushBack(8);
  list.pushBack(9);
  list.pushBack(10);

  list.print();

  list.popBack();
  list.popBack();
  list.popBack();
  list.popBack();
  list.popBack();
  list.popBack();
  list.popBack();
  list.popBack();
  list.popBack();
  list.popBack();

  list.print();

  list.pushFront(1);
  list.pushFront(2);
  list.pushFront(3);
  list.pushFront(4);
  list.pushFront(5);
  list.pushFront(6);
  list.pushFront(7);
  list.pushFront(8);
  list.pushFront(9);
  list.pushFront(10);

  list.print();

  list.popFront();
  list.popFront();
  list.popFront();
  list.popFront();
  list.popFront();
  list.popFront();
  list.popFront();
  list.popFront();
  list.popFront();
  list.popFront();

  list.print();

  list.pushBack(1);
  list.pushBack(2);
  list.pushBack(3);
  list.pushBack(4);
  list.pushBack(5);
  list.pushBack(6);
  list.pushBack(7);
  list.pushBack(8);
  list.pushBack(9);
  list.pushBack(10);

  list.print();

  list.insert(11);
  list.insert(12);
  list.insert(13);
  list.insert(14);
  list.insert(15);
  list.insert(16);
  list.insert(17);
  list.insert(18);
  list.insert(19);
  list.insert(20);

  list.print();

  list.remove(11);
  list.remove(12);
  list.remove(13);
  list.remove(14);
  list.remove(15);
  list.remove(16);
  list.remove(17);
  list.remove(18);
  list.remove(19);
  list.remove(20);

  list.print();

  return 0;
}