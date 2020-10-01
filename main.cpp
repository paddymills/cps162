#include <iostream>
#include "./source_code/Stack.h"
#include "./source_code/DynamicStack.h"

using namespace std;

void testStack();
void testDynamicStack();

int main()
{
  cout << "testing stack" << endl;
  testStack();

  cout << endl
       << "testing dynamic stack" << endl;
  testDynamicStack();

  return 0;
}

void testStack()
{
  Stack<int> test(5);
  int popVar;

  cout << "Adding 1..6" << endl;
  test.push(1);
  test.push(2);
  test.push(3);
  test.push(4);
  test.push(5);
  test.push(6);

  while (!test.isEmpty())
  {
    test.pop(popVar);
    cout << popVar;
  }
  cout << endl;
}

void testDynamicStack()
{
  DynamicStack<int> test;
  int popVar;

  cout << "Adding 1..6" << endl;
  test.push(1);
  test.push(2);
  test.push(3);
  test.push(4);
  test.push(5);
  test.push(6);

  while (!test.isEmpty())
  {
    test.pop(popVar);
    cout << popVar;
  }
  cout << endl;
}