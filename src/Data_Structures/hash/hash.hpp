#pragma once

#include <iostream>
#include <vector>

namespace Hash
{
  const int INITIAL_TABLE_SIZE = 10;

  class HashTable
  {
  private:
    struct HashEntry
    {
      int key;
      int value;
      HashEntry(int k, int v) : key(k), value(v) {}
    };

    std::vector<HashEntry*> *table;
    int currentSize;
    int numElements;
    int hashFunc(int key);
    void resize();

  public:
    HashTable();
    void insert(int key, int value);
    bool remove(int key);
    int search(int key);
    void clear();
    void display();
    ~HashTable();
  };
} // namespace Hash
