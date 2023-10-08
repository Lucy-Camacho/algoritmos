#pragma once

// Abstract base class for Dictionary
class DictionaryBase {
public:
  virtual ~DictionaryBase() = default;

  // Pure virtual functions to be implemented by derived classes
  virtual void insert(int key, int value) = 0;
  virtual bool remove(int key) = 0;
  virtual int search(int key) = 0;
  virtual void display() = 0;
  virtual void clear() = 0;
  virtual bool contains(int key) = 0;
};