/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>

class Queue
{
public:
  Queue();
  Queue(int size);
  ~Queue();
  void enqueue(int value); // add to the end of the queue
  int dequeue();           // remove from the front of the queue
  bool isEmpty();
  bool isFull();
  int size();
  void print();

private:
  int* m_array;
  int m_size;
  int m_front;
  int m_rear;
};

Queue::Queue()
    : m_array(nullptr), m_size(0), m_front(-1), m_rear(-1)
{
}

Queue::Queue(int size)
    : m_size(size), m_front(-1), m_rear(-1)
{
  m_array = new int[m_size];
}

Queue::~Queue()
{
  delete[] m_array;
}

void Queue::enqueue(int value)
{
  if (isFull())
  {
    std::cout << "Queue is full!" << std::endl;
    return;
  }

  if (isEmpty())
  {
    m_front = 0;
  }

  m_rear = (m_rear + 1) % m_size;
  m_array[m_rear] = value;
}

int Queue::dequeue()
{
  if (isEmpty())
  {
    std::cout << "Queue is empty!" << std::endl;
    return -1;
  }

  int value = m_array[m_front];
  if (m_front == m_rear)
  {
    m_front = -1;
    m_rear = -1;
  }
  else
  {
    m_front = (m_front + 1) % m_size;
  }

  return value;
}

bool Queue::isEmpty()
{
  return (m_front == -1 && m_rear == -1);
}

bool Queue::isFull()
{
  return ((m_rear + 1) % m_size == m_front);
}

int Queue::size()
{
  if (isEmpty())
  {
    return 0;
  }
  else if (m_rear >= m_front)
  {
    return m_rear - m_front + 1;
  }
  else
  {
    return m_size - (m_front - m_rear - 1);
  }
}

void Queue::print()
{
  if (isEmpty())
  {
    std::cout << "Queue is empty!" << std::endl;
    return;
  }

  std::cout << "Queue: ";
  if (m_rear >= m_front)
  {
    for (int i = m_front; i <= m_rear; i++)
    {
      std::cout << m_array[i] << " ";
    }
  }
  else
  {
    for (int i = m_front; i < m_size; i++)
    {
      std::cout << m_array[i] << " ";
    }
    for (int i = 0; i <= m_rear; i++)
    {
      std::cout << m_array[i] << " ";
    }
  }
  std::cout << std::endl;
}

int main()
{
  Queue queue(5);

  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  queue.enqueue(4);
  queue.enqueue(5);
  queue.enqueue(10);
  queue.enqueue(20);
  queue.print();

  queue.dequeue();
  queue.dequeue();
  queue.print();

  queue.enqueue(6);
  queue.enqueue(7);
  queue.print();

  queue.dequeue();
  queue.dequeue();
  queue.dequeue();
  queue.dequeue();
  queue.dequeue();
  queue.dequeue();
  queue.print();

  return 0;
}