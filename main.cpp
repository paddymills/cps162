#include "LinkedList.h"

int main()
{
  LinkedList list;

  // append items
  list.appendNode(2);
  list.appendNode(5);
  list.appendNode(8);
  list.displayNodes();

  return 0;
}