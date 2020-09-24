#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct ListNode
{
  int value;
  struct ListNode *next;
};

class LinkedList
{
private:
  ListNode *head; // ponter to the head node
  ListNode *findEnd(ListNode *node)
  {
    if (node->next)
      return findEnd(node->next);

    return node;
  }

public:
  // Constructor
  LinkedList();

  // Destructor
  ~LinkedList();

  // member methods
  void appendNode(int);
  void insertNode(int);
  void deleteNode(int);

  void displayNodes();
};

#endif