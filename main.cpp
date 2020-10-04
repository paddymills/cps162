#include "LinkedList.h"
#include <iostream>
#include <list>

using namespace std;

void test_our_list();
void test_stl();

int main()
{
  test_our_list();
  // test_stl();

  return 0;
}

void test_our_list()
{
  LinkedList list;

  // append items
  list.displayNodes();
  cout << "Appending nodes 2, 5, 8, 15 -> ";
  list.appendNode(2);
  list.appendNode(5);
  list.appendNode(8);
  list.appendNode(15);
  list.displayNodes();

  // insert items
  cout << "Insert 3 at index 1         -> ";
  list.insertNode(3, 1);
  list.displayNodes();
  cout << "Insert 7 at index 3         -> ";
  list.insertNode(7, 3);
  list.displayNodes();

  // delete items
  cout << "Deleting index 2            -> ";
  list.deleteNode(2);
  list.displayNodes();
  cout << "Deleting index 4            -> ";
  list.deleteNode(4);
  list.displayNodes();
  cout << "Deleting index 1            -> ";
  list.deleteNode(1);
  list.displayNodes();
  cout << "Deleting index 0            -> ";
  list.deleteNode(0);
  list.displayNodes();
}

void test_stl()
{
  list<int> list;

  // append items
  list.push_back(2);
  list.push_back(5);
  list.push_back(8);

  // insert items
  // int *ref = list.begin();
  // ref++;
  // list.insert(ref, 3);
  // cout << "Insert 3 at index 1" << endl;
  // display_stl(list);
}

// void display_stl(forward_list<int> *list)
// {
//   cout << "list:" for (auto it = list.begin(); it != list.end(); it++)
//   {
//     cout << " " << *it;
//   }

//   cout << endl;
// }