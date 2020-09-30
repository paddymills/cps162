#include "LinkedList.h"

#include <iostream>
using namespace std;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~               PRIVATE              ~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// recursive methods
ListNode *LinkedList::findEnd(ListNode *node)
{
  if (node->next)
    return findEnd(node->next);

  return node;
}

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
  ListNode *newNode = new ListNode();
  newNode->value = number;

  ListNode *temp = head;
  ListNode *prevElem = nullptr;

  int counter = 0;
  while (counter < index)
  {
    prevElem = temp;
    temp = temp->next;
    counter++;
  }

  prevElem->next = newNode;
  newNode->next = temp;
}
void LinkedList::deleteNode(int index)
{
  ListNode *temp = head;
  ListNode *prevElem = head;

  if (index == 0)
  {
    temp = head->next;
    delete head;
    head = temp;

    return;
  }

  int counter = 0;
  while (counter < index)
  {
    if (!temp->next)
    {
      cout << "Error: index past end of list" << endl;
      return;
    }
    prevElem = temp;
    temp = temp->next;
    counter++;
  }

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