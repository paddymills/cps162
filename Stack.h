#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

// Stack template
template <class T>
class Stack
{
private:
  T *stackArray;
  int stackSize;
  int top;

public:
  //Constructor
  Stack(int);

  // Copy constructor
  Stack(const Stack &);

  // Destructor
  ~Stack();

  // Stack operations
  void push(T);
  void pop(T &);
  bool isFull();
  bool isEmpty();
};

#endif
