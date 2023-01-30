/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>

// implement Queue using linked list
class Queue
{
public:
  Queue();
  ~Queue();
  void enqueue(int data);
  int dequeue();
  int peek();
  bool isEmpty();
  int size();
  void print();

private:
  class Node
  {
  public:
    int data;
    Node* next;
  };

  Node* head;
  Node* tail;
  int m_size;
};

Queue::Queue()
    : head(NULL), tail(NULL), m_size(0)
{
}

Queue::~Queue()
{
  while (!isEmpty())
    dequeue();
}

void Queue::enqueue(int data)
{
  Node* node = new Node(data);
  if (isEmpty())
  {
    head = node;
    tail = node;
  }
  else
  {
    tail->next = node;
    tail = node;
  }
  m_size++;
}

int Queue::dequeue()
{
  if (isEmpty())
    return -1;
  Node* node = head;
  head = head->next;
  int data = node->data;
  delete node;
  m_size--;
  return data;
}

int Queue::peek()
{
  if (isEmpty())
    return -1;
  return head->data;
}

bool Queue::isEmpty()
{
  return m_size == 0;
}

int Queue::size()
{
  return m_size;
}

void Queue::print()
{
  Node* node = head;
  while (node != NULL)
  {
    std::cout << node->data << " ";
    node = node->next;
  }
  std::cout << std::endl;
}

int main()
{
  Queue queue;
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  queue.enqueue(4);
  queue.enqueue(5);
  queue.print();
  std::cout << "size: " << queue.size() << std::endl;
  std::cout << "peek: " << queue.peek() << std::endl;
  queue.dequeue();
  queue.dequeue();
  queue.dequeue();
  std::cout << "size: " << queue.size() << std::endl;
  std::cout << "peek: " << queue.peek() << std::endl;
  queue.print();
}
