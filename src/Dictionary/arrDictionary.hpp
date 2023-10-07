#pragma once

#include "../Data_Structures/array/array.hpp"

struct KeyValuePair {
  int key;
  int value;

  KeyValuePair(int k, int v)
  {
    key = k;
    value = v;
  }

  bool operator<(const KeyValuePair& other) const
  {
    return key < other.key;
  }

  bool operator>(const KeyValuePair& other) const
  {
    return key > other.key;
  }
};

class ArrDictionary
{
private:
  Array::OrderedList list;

public:
  ArrDictionary();
  ~ArrDictionary();
  void insert(int key, int value);
  bool remove(int key);
  int search(int key);
  void display();
  void clear();
  bool contains(int key);
};