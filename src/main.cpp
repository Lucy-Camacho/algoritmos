#include "../Dictionary/arrDictionary.hpp"
#include "../Dictionary/listDictionary.hpp"
#include "../Dictionary/hashDictionary.hpp"
#include <iostream>

int main()
{
  int choice, type, key, value;
  ArrDictionary arrayDict;
  LinkedListDictionary linkedListDict;
  HashDictionary hashTableDict;
  DictionaryBase* dict = nullptr;

  std::cout << "Choose dictionary type:\n1. Array\n2. Linked List\n3. Hash Table\nChoice: ";
  std::cin >> type;

  switch (type)
  {
    case 1:
      dict = &arrayDict;
    break;
      case 2:
      dict = &linkedListDict;
      break;
    case 3:
      dict = &hashTableDict;
      break;
    default:
      std::cout << "Invalid choice!";
      return 0;
  }

  do
  {
    std::cout << "\nMenu:\n1. Insert\n2. Remove\n3. Search\n4. Display\n5. Clear\n6. Contains\n7. Exit\nChoice: ";
    std::cin >> choice;

    switch (choice)
    {
      case 1:
      std::cout << "Enter key: ";
      std::cin >> key;
      std::cout << "Enter value: ";
      std::cin >> value;
      dict->insert(key, value);
      break;
      case 2:
        std::cout << "Enter key to remove: ";
        std::cin >> key;
        dict->remove(key);
        break;
      case 3:
        std::cout << "Enter key to search: ";
        std::cin >> key;
        value = dict->search(key);
        
        if (value != -1)
        {
          std::cout << "Value: " << value << std::endl;
        }
        else
        {
          std::cout << "Key not found." << std::endl;
        }
      break;
      case 4:
        dict->display();
      break;
      case 5:
        dict->clear();
        std::cout << "Dictionary cleared." << std::endl;
      break;
      case 6:
        std::cout << "Enter key to check: ";
        std::cin >> key;
        
        if (dict->contains(key))
        {
          std::cout << "Key exists in the dictionary." << std::endl;
        }
        else
        {
          std::cout << "Key does not exist in the dictionary." << std::endl;
        }
      break;
      case 7:
        std::cout << "Exiting..." << std::endl;
      break;
      default:
        std::cout << "Invalid choice!" << std::endl;
      break;
  }
  } while (choice != 7);

  return 0;
}