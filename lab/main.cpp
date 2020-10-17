#include <iostream>
#include "MathStack.h"

using namespace std;

/*
  Using MathStack, implement the following member functions:
    - mult: Pops the top two values off the stack, multiplies them, and pushes their product onto the stack
    - div: Pops the top two values off the stack, divides them, and pushes their quotient onto the stack
    - addAll: Pops all values off the stack, adds them, and pushes their sum onto the stack
    - mutlAll: Pops all values off the stack, multiplies them, and pushes their product onto the stack
*/

void MathStack::mult()
{
  int num, product;

  // Pop the first two values off the stack.
  pop(product);
  pop(num);

  // Multiply the two values, store in product.
  product *= num;

  // Push product back onto the stack.
  push(product);
}

void MathStack::div()
{
  int num, quotent;

  // Pop the first two values off the stack.
  pop(quotent);
  pop(num);

  // Multiply the two values, store in quotent.
  quotent /= num;

  // Push quotent back onto the stack.
  push(quotent);
}

void MathStack::addAll()
{
  int sum, num;

  while (!isEmpty())
  {
    // pop number off stack and store in num
    pop(num);

    // add popped number to sum
    sum += num;
  }

  push(sum);
}

void MathStack::multAll()
{
  int product, num;

  while (!isEmpty())
  {
    // pop number off stack and store in num
    pop(num);

    // add popped number to product
    product += num;
  }

  push(product);
}

int main()
{

  return 0;
}