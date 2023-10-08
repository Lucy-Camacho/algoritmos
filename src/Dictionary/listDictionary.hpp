#pragma once

#include "../Data_Structures/list/list.hpp"
#include "BaseDictionary.hpp"

struct KeyValuePairLL {
  int key;
  int value;

  KeyValuePairLL(int k, int v)
  {
    key = k;
    value = v;
  }

  bool operator<(const KeyValuePairLL& other) const
  {
    return key < other.key;
  }

  bool operator>(const KeyValuePairLL& other) const
  {
    return key > other.key;
  }
};

class LinkedListDictionary : public DictionaryBase
{
private:
  List::OrderedList list;

public:
  LinkedListDictionary();
  ~LinkedListDictionary();
  void insert(int key, int value);
  bool remove(int key);
  int search(int key);
  void display();
  void clear();
  bool contains(int key);
};
