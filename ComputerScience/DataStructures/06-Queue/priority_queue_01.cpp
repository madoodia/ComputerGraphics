/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>

// Priority data is the value of the element, higher value means higher priority
class PriorityQueue
{
public:
  PriorityQueue();
  ~PriorityQueue();

  void enqueue(int value);
  int dequeue();
  int peek();
  int size();
  bool isEmpty();
  void print();

private:
  int* m_array;
  int m_size;
  int m_capacity;

  void resize();
};

PriorityQueue::PriorityQueue()
{
  m_array = new int[10];
  m_size = 0;
  m_capacity = 10;
}

PriorityQueue::~PriorityQueue()
{
  delete[] m_array;
}

void PriorityQueue::enqueue(int value)
{
  if (m_size == m_capacity)
    resize();

  int i = m_size - 1;
  while (i >= 0 && m_array[i] > value)
  {
    m_array[i + 1] = m_array[i];
    i--;
  }

  m_array[i + 1] = value;
  m_size++;
}

int PriorityQueue::dequeue()
{
  if (isEmpty())
    throw std::runtime_error("Queue is empty");

  return m_array[--m_size];
}

int PriorityQueue::peek()
{
  if (isEmpty())
    throw std::runtime_error("Queue is empty");

  return m_array[m_size - 1];
}

int PriorityQueue::size()
{
  return m_size;
}

bool PriorityQueue::isEmpty()
{
  return m_size == 0;
}

void PriorityQueue::resize()
{
  int* temp = new int[m_capacity * 2];
  for (int i = 0; i < m_size; i++)
    temp[i] = m_array[i];

  delete[] m_array;
  m_array = temp;
  m_capacity *= 2;
}

void PriorityQueue::print()
{
  for (int i = 0; i < m_size; i++)
    std::cout << m_array[i] << " ";
  std::cout << std::endl;
}

// ------------------------------
int main()
{
  PriorityQueue queue;
  queue.enqueue(10);
  queue.enqueue(20);
  queue.enqueue(30);
  queue.enqueue(40);
  queue.print();

  while (!queue.isEmpty())
    std::cout << queue.dequeue() << " ";
  std::cout << std::endl;

  return 0;
}