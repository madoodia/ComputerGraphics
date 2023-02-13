/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>

class Node
{
public:
  Node(int data);
  ~Node();

  int data;
  Node* left;
  Node* right;
};

Node::Node(int data)
{
  this->data = data;
  left = nullptr;
  right = nullptr;
}

Node::~Node()
{
  delete left;
  delete right;
}

class BinarySearchTree
{
public:
  BinarySearchTree();
  ~BinarySearchTree();

  void insert(int data);
  void remove(int data);
  bool find(int data);

private:
  Node* root;
};

BinarySearchTree::BinarySearchTree()
{
  root = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
  delete root;
  root = nullptr;
}

void BinarySearchTree::insert(int data)
{
  if (root == nullptr)
  {
    root = new Node(data);
    return;
  }

  Node* current = root;
  while (true)
  {
    if (data < current->data)
    {
      if (current->left == nullptr)
      {
        current->left = new Node(data);
        return;
      }
      current = current->left;
    }
    else
    {
      if (current->right == nullptr)
      {
        current->right = new Node(data);
        return;
      }
      current = current->right;
    }
  }
}

void BinarySearchTree::remove(int data)
{
  if (root == nullptr)
    return;

  Node* current = root;
  Node* parent = nullptr;
  while (current != nullptr)
  {
    if (data < current->data)
    {
      parent = current;
      current = current->left;
    }
    else if (data > current->data)
    {
      parent = current;
      current = current->right;
    }
    else // data == current->data
    {
      if (current->left == nullptr && current->right == nullptr)
      {
        if (parent == nullptr)
        {
          delete root;
          root = nullptr;
        }
        else
        {
          if (parent->left == current)
            parent->left = nullptr;
          else
            parent->right = nullptr;
          delete current;
        }
      }
      else if (current->left == nullptr)
      {
        if (parent == nullptr)
        {
          root = current->right;
          delete current;
        }
        else
        {
          if (parent->left == current)
            parent->left = current->right;
          else
            parent->right = current->right;
          delete current;
        }
      }
      else if (current->right == nullptr)
      {
        if (parent == nullptr)
        {
          root = current->left;
          delete current;
        }
        else
        {
          if (parent->left == current)
            parent->left = current->left;
          else
            parent->right = current->left;
          delete current;
        }
      }
      else
      {
        Node* successor = current->right;
        Node* successorParent = current;
        while (successor->left != nullptr)
        {
          successorParent = successor;
          successor = successor->left;
        }

        current->data = successor->data;
        if (successorParent->left == successor)
          successorParent->left = successor->right;
        else
          successorParent->right = successor->right;
        delete successor;
      }
      return;
    }
  }
}

bool BinarySearchTree::find(int data)
{
  if (root == nullptr)
    return false;

  Node* current = root;
  while (current != nullptr)
  {
    if (data < current->data)
      current = current->left;
    else if (data > current->data)
      current = current->right;
    else
      return true;
  }
  return false;
}

// ------------------------------
int main()
{
  BinarySearchTree bst;
  bst.insert(10);
  bst.insert(5);
  bst.insert(15);
  bst.insert(3);
  bst.insert(7);
  bst.insert(12);
  bst.insert(11);

  std::cout << bst.find(10) << std::endl;
  std::cout << bst.find(5) << std::endl;

  bst.remove(3);
  std::cout << bst.find(5) << std::endl;

  return 0;
}