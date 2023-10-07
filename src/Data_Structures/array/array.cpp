#include "array.hpp"

Array::OrderedList::OrderedList()
{
  size = 0;
}

void Array::OrderedList::insert(int val)
{
  if (size == MAX_SIZE)
  {
    std::cout << "List is full!" << std::endl;
    return;
  }

  int i;
  for (i = 0; i < size; i++)
  {
    if (arr[i] > val) break;
  }

  for (int j = size; j > i; j--)
  {
    arr[j] = arr[j - 1];
  }

  arr[i] = val;
  size++;
}

void Array::OrderedList::display()
{
  for (int i = 0; i < size; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}