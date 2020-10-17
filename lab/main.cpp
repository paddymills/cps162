#include <iostream>
#include <iomanip>
#include <string>
#include "MathStack.h"

using namespace std;

/*
  Using MathStack, implement the following member functions:
    - mult: Pops the top two values off the stack, multiplies them, and pushes their product onto the stack
    - div: Pops the top two values off the stack, divides them, and pushes their quotient onto the stack
    - addAll: Pops all values off the stack, adds them, and pushes their sum onto the stack
    - mutlAll: Pops all values off the stack, multiplies them, and pushes their product onto the stack
*/

// display prototype
void displayStackValues(MathStack);

const int NUMBER_DISPLAY_WIDTH = 5;
const string STACK_SEP = "\t+-------+";

int main()
{
  MathStack stack(5);

  // fill with numbers
  stack.push(42);
  stack.push(-2);
  stack.push(100);
  stack.push(50);
  stack.push(10);

  cout << "Initial Stack State:" << endl;
  displayStackValues(stack);

  // test mult
  stack.mult();
  cout << "After mult() call:" << endl;
  displayStackValues(stack);

  // test div
  stack.div();
  cout << "After div() call:" << endl;
  displayStackValues(stack);

  // test addAll
  stack.addAll();
  cout << "After addAll() call:" << endl;
  displayStackValues(stack);

  // add some numbers to test mult
  cout << "Pushing [5, 82] onto the stack" << endl;
  stack.push(5);
  stack.push(82);

  cout << "new Stack State:" << endl;
  displayStackValues(stack);

  // test multAll
  stack.multAll();
  cout << "After multAll() call:" << endl;
  displayStackValues(stack);

  return 0;
}

void displayStackValues(MathStack stack)
{
  /*
    Recursively diplays stack:
      - pops item off stack
      - calls method if stack is not empty
      - after recursive call, displays number that was popped
      - pushes number back on to the stack, to preserve the stack

    This recursive nature is required to 
  */

  int num;

  // pop number off of stack
  stack.pop(num);

  if (stack.isEmpty())
  { // begin display printing (stack is empty)
    cout << STACK_SEP << endl;
  }
  else
  { // recursive call (stack is not empty)
    displayStackValues(stack);
  }

  // display number with formatting
  cout << "\t| " << setw(NUMBER_DISPLAY_WIDTH) << num << " |" << endl;
  cout << STACK_SEP << endl;

  // push number back onto stack
  stack.push(num);
}

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

  pop(sum);
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

  pop(product);
  while (!isEmpty())
  {
    // pop number off stack and store in num
    pop(num);

    // add popped number to product
    product *= num;
  }

  push(product);
}
