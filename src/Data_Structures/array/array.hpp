#pragma once

#include <iostream>

namespace Array
{
  const int MAX_SIZE = 100;

  class OrderedList {
  private:
    int arr[MAX_SIZE];
    int size;

  public:
    OrderedList();
    void insert(int val);
    void display();
  };
}