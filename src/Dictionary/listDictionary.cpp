#include "listDictionary.hpp"

LinkedListDictionary::LinkedListDictionary() {}

LinkedListDictionary::~LinkedListDictionary()
{
  clear();
}

void LinkedListDictionary::insert(int key, int value)
{
  KeyValuePairLL pair(key, value);
  list.insert(*(reinterpret_cast<int*>(&pair)));
}

bool LinkedListDictionary::remove(int key)
{
  KeyValuePairLL pair(key, 0);
  return list.remove(*(reinterpret_cast<int*>(&pair)));
}

int LinkedListDictionary::search(int key)
{
  KeyValuePairLL pair(key, 0);
  int index = list.search(*(reinterpret_cast<int*>(&pair)));
  if (index != -1)
  {
    KeyValuePairLL* foundPair = reinterpret_cast<KeyValuePairLL*>(&index);
    return foundPair->value;
  }
  
  return -1;  // Not found
}

void LinkedListDictionary::display()
{
  list.display();
}

void LinkedListDictionary::clear()
{
  while (list.remove(list.search(0))) {}  // Keep removing until list is empty
}

bool LinkedListDictionary::contains(int key)
{
  KeyValuePairLL pair(key, 0);
  return list.search(*(reinterpret_cast<int*>(&pair))) != -1;
}