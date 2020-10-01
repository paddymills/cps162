#ifndef DYNAMICSTACK_H
#define DYNAMICSTACK_H
#include <iostream>
using namespace std;

// Stack template
template <class T>
class DynamicStack
{
private:
  // Structure for the stach nodes
  struct StackNode
  {
    T value;         // Value in the node
    StackNode *next; // Pointer to next node
  };

  StackNode *top; // Pointer to the stack top

public:
  //Constructor
  DynamicStack()
  {
    top = 0;
  }

  // Destructor
  ~DynamicStack();

  // Stack operations
  void push(T);
  void pop(T &);
  bool isEmpty();
};

#endif
