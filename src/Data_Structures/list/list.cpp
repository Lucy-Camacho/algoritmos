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

bool List::OrderedList::remove(int val)
{
  if (!head)
  {
    return false;
  }
  
  if (head->data == val)
  {
    Node* temp = head;
    head = head->next;
    delete temp;
    return true;
  }
    
  Node* current = head;
  while (current->next && current->next->data != val)
  {
    current = current->next;
  }
  
  if (current->next)
  {
    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
    return true;
  }
  return false;
}

int List::OrderedList::search(int val)
{
  Node* current = head;
  int index = 0;
  while (current)
  {
    if (current->data == val)
    {
      return index;
    }
    current = current->next;
    index++;
  }
  
  return -1;  // Not found
}

void List::OrderedList::display()
{
  Node* current = head;
  
  while (current)
  {
    std::cout << current->data << " ";
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