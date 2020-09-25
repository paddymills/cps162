#include "LinkedList.h"

#include <iostream>
using namespace std;

// PRIVATE
ListNode LinkedList::*findEnd(ListNode *node)
{
  if (node->next)
    return findEnd(node->next);

  return node;
}

// Constructor
LinkedList::LinkedList()
{
  head = nullptr;
}

// Destructor
LinkedList::~LinkedList()
{
}

// member methods
void LinkedList::appendNode(int number)
{

  ListNode *newNode = new ListNode();
  newNode->value = number;
  newNode->next = nullptr;

  if (!head)
    head = newNode;
  else
    findEnd(head)->next = newNode;
}

void LinkedList::insertNode(int)
{
}
void LinkedList::deleteNode(int)
{
}

void LinkedList::displayNodes()
{
  // pointer for list iteration
  ListNode *nodePtr;

  // initialize pointer to head
  nodePtr = head;

  // iterate through list and display each element
  while (nodePtr)
  {
    cout << nodePtr->value << endl;

    // set pointer to next
    nodePtr = nodePtr->next;
  }
}