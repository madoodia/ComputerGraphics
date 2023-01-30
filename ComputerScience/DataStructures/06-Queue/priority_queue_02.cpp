/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>

template <typename T>
class PriorityQueue
{
private:
  struct Node
  {
    T data;
    int priority; // higher value means higher priority
    Node* next;
  };

  Node* head;

public:
  PriorityQueue()
  {
    head = nullptr;
  }

  ~PriorityQueue()
  {
    Node* temp = head;
    while (temp != nullptr)
    {
      Node* next = temp->next;
      delete temp;
      temp = next;
    }
  }

  void enqueue(T data, int priority)
  {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = nullptr;

    if (head == nullptr)
    {
      head = newNode;
    }
    else
    {
      Node* temp = head;
      while (temp->next != nullptr)
      {
        temp = temp->next;
      }
      temp->next = newNode;
    }
  }

  T dequeue()
  {
    if (head == nullptr)
    {
      std::cout << "Queue is empty" << std::endl;
      return T();
    }

    Node* temp = head;
    Node* prev = nullptr;
    Node* max = head;
    Node* maxPrev = nullptr;

    while (temp != nullptr)
    {
      if (temp->priority > max->priority)
      {
        max = temp;
        maxPrev = prev;
      }
      prev = temp;
      temp = temp->next;
    }

    if (maxPrev == nullptr)
    {
      head = head->next;
    }
    else
    {
      maxPrev->next = max->next;
    }

    T data = max->data;
    delete max;
    return data;
  }

  bool isEmpty()
  {
    return head == nullptr;
  }

  void print()
  {
    Node* temp = head;
    while (temp != nullptr)
    {
      std::cout << temp->data << " ";
      temp = temp->next;
    }
    std::cout << std::endl;
  }
};

int main()
{
  PriorityQueue<int> queue;

  queue.enqueue(1, 1);
  queue.enqueue(2, 2);
  queue.enqueue(3, 3);
  queue.enqueue(4, 4);
  queue.enqueue(5, 5);
  queue.enqueue(6, 6);
  queue.enqueue(7, 7);
  queue.enqueue(8, 8);
  queue.enqueue(9, 9);
  queue.enqueue(10, 10); // higher value means higher priority

  queue.print();

  while (!queue.isEmpty())
    std::cout << queue.dequeue() << " ";
  std::cout << std::endl;

  return 0;
}
