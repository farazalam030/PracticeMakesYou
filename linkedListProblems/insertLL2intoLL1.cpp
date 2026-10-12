#include "linkedList_utility.h"

Node *insertLL2intoLL1(Node *h1, Node *h2, int i, int j) {
  
  if (!h1)
    return h2;
  if (!h2)
    return h1;

  Node *t1 = h1;
  Node *t2 = h2;
  Node *prev1 = nullptr;
  int k;
  
  for (k = 1; k < i && t1; k++) {
    prev1 = t1;
    t1 = t1->next;
  }
  
  if (!prev1)
    h1 = h2;
  else if (prev1)
    prev1->next = h2;

  Node *l2Last = h2;
  while (l2Last->next) {
    l2Last = l2Last->next;
  }
  
  for (; k <= j && t1; k++) {
    t1 = t1->next;
  }
  if (l2Last && t1)
    l2Last->next = t1;
  return h1;
}

int main(int argc, char const *argv[]) {
  Node *h1 = nullptr;
  Node *h2 = nullptr;
  Node *h3 = nullptr;
  //   createLinkedList(&h1);
  for (int i = 101; i <= 110; i += 1) {
    insertNodeatLast(&h2, i);
  }
  for (int i = 201; i <= 205; i += 1) {
    insertNodeatLast(&h3, i);
  }

  //   displayList(h1);
  cout << "list_1 -> ";
  displayList(h2);
  cout << "list_2 -> ";
  displayList(h3);

  h1 = insertLL2intoLL1(h2, h3, 9, 10);
  cout << "list_1 after insertion -> ";
  displayList(h1);
  return 0;
}
