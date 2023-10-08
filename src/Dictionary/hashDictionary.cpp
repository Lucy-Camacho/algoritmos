#include "hashDictionary.hpp"

HashDictionary::HashDictionary() {}

HashDictionary::~HashDictionary() {
    clear();
}

void HashDictionary::insert(int key, int value) {
    table.insert(key, value);
}

bool HashDictionary::remove(int key) {
    return table.remove(key);
}

int HashDictionary::search(int key) {
    return table.search(key);
}

void HashDictionary::display() {
    table.display();
}

void HashDictionary::clear() {
    
}

bool HashDictionary::contains(int key) {
  return table.search(key) != -1;
}