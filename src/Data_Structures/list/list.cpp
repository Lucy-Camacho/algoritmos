#include "list.hpp"


List::Node::Node(int val)
{
  data = val;
  next = nullptr;
}

List::OrderedList::OrderedList()
{
  head = nullptr;
}

void List::OrderedList::insert(int val)
{
  Node* newNode = new Node(val);

  if (!head || head->data > val)
  {
    newNode->next = head;
    head = newNode;
  } 
  else
  {
    Node* current = head;

    while (current->next && current->next->data < val)
    {
      current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
  }
}

void List::OrderedList::display()
{
  Node* current = head;
  
  while (current)
  {
    std::cout << current->data << " -> ";
    current = current->next;
  }

  std::cout << "nullptr" << std::endl;
}

List::OrderedList::~OrderedList()
{
  while (head)
  {
    Node* temp = head;
    head = head->next;
    delete temp;
  }
}