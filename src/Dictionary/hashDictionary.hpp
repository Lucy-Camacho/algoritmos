#pragma once

#include "../Data_Structures/hash/hash.hpp"
#include "BaseDictionary.hpp"

class HashDictionary : public DictionaryBase
{
private:
  Hash::HashTable table;

public:
  HashDictionary();
  ~HashDictionary();
  void insert(int key, int value);
  bool remove(int key);
  int search(int key);
  void display();
  void clear();
  bool contains(int key);
};