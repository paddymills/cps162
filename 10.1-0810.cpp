#include <iostream>

using namespace std;

int i = 1;
int onstack = 0;

void g8(char ch, int n)
{
  if (n == 0)
  {
    cout << endl;
    onstack--;
  }
  else
  {
    onstack++;
    g8(ch - 1, n - 1);
    cout << i++ << "| " << ch << n << " | " << onstack;
    g8(ch + 1, n - 1);
  }
}

void g10(char ch, int n)
{
  if (n == 0)
  {
    cout << endl;
  }
  else
  {
    g10(ch - 1, n - 1);
    cout << i++ << "| " << ch << n;
    g10(ch + 1, n - 1);
  }
}

int main()
{
  cout << "Exercise 8:";
  g8('M', 4);

  cout << endl;

  cout << "Exercise 10:";
  g10('M', 4);

  cout << endl;
}