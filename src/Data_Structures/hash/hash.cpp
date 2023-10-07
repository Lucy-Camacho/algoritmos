#include "hash.hpp"

Hash::HashTable::HashTable() : currentSize(INITIAL_TABLE_SIZE), numElements(0) {
  table = new std::vector<HashEntry*>[currentSize];
}

int Hash::HashTable::hashFunc(int key) {
  return key % currentSize;
}

void Hash::HashTable::resize() {
  int oldSize = currentSize;
  currentSize *= 2;
  std::vector<HashEntry*> *newTable = new std::vector<HashEntry*>[currentSize];
  
  for (int i = 0; i < oldSize; i++) {
    for (auto& entry : table[i])
    {
      int hashVal = entry->key % currentSize;
      newTable[hashVal].push_back(entry);
    }
  }
  delete[] table;
  table = newTable;
}

void Hash::HashTable::insert(int key, int value) {
  if ((numElements * 1.0) / currentSize > 0.7)
  {
    resize();
  }
  int hashVal = hashFunc(key);
  HashEntry* newEntry = new HashEntry(key, value);
  table[hashVal].push_back(newEntry);
  numElements++;
}

bool Hash::HashTable::remove(int key) {
  int hashVal = hashFunc(key);

  for (int i = 0; i < table[hashVal].size(); i++)
  {
    
    if (table[hashVal][i]->key == key)
    {
      delete table[hashVal][i];
      table[hashVal].erase(table[hashVal].begin() + i);
      numElements--;
      return true;
    }

  }

  return false;
}

int Hash::HashTable::search(int key) {
  int hashVal = hashFunc(key);
  
  for (int i = 0; i < table[hashVal].size(); i++)
  {
    if (table[hashVal][i]->key == key)
    {
      return table[hashVal][i]->value;
    }
  }
  return -1;  // Not found
}

void Hash::HashTable::display() {
  for (int i = 0; i < currentSize; i++)
  {
    std::cout << "Bucket " << i << ": ";

    for (auto& entry : table[i])
    {
      std::cout << "[" << entry->key << ":" << entry->value << "] ";
    }
    std::cout << std::endl;
  }
}

Hash::HashTable::~HashTable() {
  for (int i = 0; i < currentSize; i++) {
    for (auto& entry : table[i])
    {
      delete entry;
    }
  }
  delete[] table;
}