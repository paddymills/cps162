#include "LinkedList.h"

#include <iostream>
using namespace std;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~               PRIVATE              ~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// recursively finds the end of the list
ListNode *LinkedList::findEnd(ListNode *node)
{
  if (node->next)
    return findEnd(node->next);

  return node;
}

// recursively finds node at specific index
// ***        returns node BEFORE index        ***
// ^^^ so that a insertion/deletion can happen ^^^
ListNode *LinkedList::findIndex(ListNode *currentPosition, int indexCounter, int wantedIndex)
{
  // reached wanted index
  if (indexCounter == wantedIndex - 1)
    return currentPosition;

  // reached end of list
  if (!currentPosition->next)
    return currentPosition;

  return findIndex(currentPosition->next, ++indexCounter, wantedIndex);
}

// recursively deletes all elements after the given node
void LinkedList::deleteAllAfter(ListNode *node)
{
  // deletes all elements after node
  if (node->next)
    deleteAllAfter(node->next);

  delete node;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~                PUBLIC              ~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Constructor
LinkedList::LinkedList()
{
  head = nullptr;
}

// Destructor
LinkedList::~LinkedList()
{
  if (head)
    deleteAllAfter(head);
}

// member methods
void LinkedList::appendNode(int number)
{
  ListNode *newNode = new ListNode();
  newNode->value = number;
  newNode->next = nullptr;

  if (!head) // head == nullptr
    head = newNode;
  else
    findEnd(head)->next = newNode;
}

void LinkedList::insertNode(int number, int index)
{
  /*
    Inserts number at index:
      - index 0 puts number at hed
      - other indexes put item at location and reattach list
      - indexes higher than length put number at end
      - negative indexes cause error
  */

  ListNode *newNode = new ListNode();
  newNode->value = number;

  ListNode *temp = head;
  ListNode *prevElem = nullptr;

  if (index == 0)
  {
    // repoint head
    newNode->next = head->next;
    head = newNode;

    return;
  }

  prevElem = findIndex(head, 0, index);

  newNode->next = prevElem->next;
  prevElem->next = newNode;
}
void LinkedList::deleteNode(int index)
{
  ListNode *temp = head;
  ListNode *prevElem = head;

  if (index == 0)
  {
    // delete first element (repoint head)
    temp = head->next;
    delete head;
    head = temp;

    return;
  }

  // get elem at index
  prevElem = findIndex(head, 0, index);

  temp = prevElem->next;
  prevElem->next = temp->next;
  delete temp;
}

void LinkedList::displayNodes()
{
  // pointer for list iteration
  ListNode *nodePtr;

  // initialize pointer to head
  nodePtr = head;

  // label output
  cout << "Node Values:";

  // iterate through list and display each element
  while (nodePtr)
  {
    cout << " " << nodePtr->value;

    // set pointer to next
    nodePtr = nodePtr->next;
  }

  // terminate line
  cout << endl;
}