#pragma once

#include <iostream>

namespace List
{
  class Node
  {
  public:
    int data;
    Node* next;

    Node(int val);
  };

  class OrderedList
  {
  private:
    Node* head;

  public:
    OrderedList();
    void insert(int val);
    bool remove(int val);
    int search(int val);
    void display();
    ~OrderedList();
  };
}
