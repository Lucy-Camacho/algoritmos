#include "arrDictionary.hpp"

ArrDictionary::ArrDictionary()
{

}

ArrDictionary::~ArrDictionary()
{
  clear();
}

void ArrDictionary::insert(int key, int value)
{
  KeyValuePair pair(key, value);
  list.insert(*(reinterpret_cast<int*>(&pair)));
}

bool ArrDictionary::remove(int key)
{
  KeyValuePair pair(key, 0);
  return list.remove(*(reinterpret_cast<int*>(&pair)));
}

int ArrDictionary::search(int key) {
  KeyValuePair pair(key, 0);
  int index = list.search(*(reinterpret_cast<int*>(&pair)));
  if (index != -1)
  {
    KeyValuePair* foundPair = reinterpret_cast<KeyValuePair*>(&index);
    return foundPair->value;
  }
  return -1;  // Not found
}

void ArrDictionary::display()
{
  list.display();
}

void ArrDictionary::clear()
{
  while (list.remove(list.search(0))) {}  // Keep removing until list is empty
}

bool ArrDictionary::contains(int key)
{
  KeyValuePair pair(key, 0);
  return list.search(*(reinterpret_cast<int*>(&pair))) != -1;
}