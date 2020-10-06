#include "LinkedList.h"

#include <iostream>
#include <iomanip>
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

  // create new node
  ListNode *newNode = new ListNode();
  newNode->value = number;

  if (index == 0)
  {
    // repoint head
    newNode->next = head->next;
    head = newNode;

    return;
  }

  // temporary nodes for repointing
  ListNode *temp = head;
  ListNode *prevElem = nullptr;

  // find prev element of index
  // if findIndex hits the end of the list
  // it will return the last element
  prevElem = findIndex(head, 0, index);

  // put new node in place or at end
  newNode->next = prevElem->next; // nullptr if at end
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

  // repoint previous element to next element
  temp = prevElem->next;

  // if index is after last element, ERROR
  if (!temp)
  {
    cout << "Error: index is after last index. ";

    return;
  }

  // delete element
  prevElem->next = temp->next;
  delete temp;
}

void LinkedList::displayNodes()
{
  /*
    Display elements in list notation
      - right justified
      - 2 character width
      - single space delimited
    i.e. [ 1  2  3  4]
  */

  // pointer for list iteration
  ListNode *nodePtr;

  // initialize pointer to head
  nodePtr = head;

  // label output
  cout << "[";

  // iterate through list and display each element
  while (nodePtr)
  {
    cout << setw(2) << nodePtr->value << " ";

    // set pointer to next
    nodePtr = nodePtr->next;
  }

  // terminate line
  cout << "]";
}