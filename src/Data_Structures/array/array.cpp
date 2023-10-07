#include "array.hpp"

Array::OrderedList::OrderedList()
{
  size = 0;
}

void Array::OrderedList::resize() {
    capacity *= 2;
    int* newArr = new int[capacity];

    for (int i = 0; i < size; i++)
    {
      newArr[i] = arr[i];
    }

    delete[] arr;
    arr = newArr;
}

void Array::OrderedList::insert(int val)
{
  if (size == capacity)
  {
    resize();
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

bool Array::OrderedList::remove(int val)
{
  for (int i = 0; i < size; i++)
  {
    if (arr[i] == val)
    {
      for (int j = i; j < size - 1; j++)
      {
        arr[j] = arr[j + 1];
      }
      size--;
      return true;
    }
  }
  return false;
}

int Array::OrderedList::search(int val)
{
  for (int i = 0; i < size; i++)
  {
    if (arr[i] == val)
    {
      return i;
    }
  }
  return -1;  // Not found
}

void Array::OrderedList::display()
{
  for (int i = 0; i < size; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}