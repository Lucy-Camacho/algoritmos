#pragma once

#include <iostream>

namespace Array
{
  const int INITIAL_ARRAY_SIZE = 10;

  class OrderedList {
  private:
    int* arr;
    int size;
    int capacity;
    void resize();
  
  public:
    OrderedList();
    void insert(int val);
    bool remove(int val);
    int search(int val);
    void display();
  };
}