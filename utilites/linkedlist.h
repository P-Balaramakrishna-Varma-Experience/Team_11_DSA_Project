#ifndef __linkedlist_
#define __linkedlist_

typedef  struct Node* NodePtr;
typedef int ElementType;

struct Node {
    ElementType Elem;
    NodePtr Next;
};

void createnode(NodePtr N);
// to create a node

void deletenode(NodePtr N,ElementType Elem);
//to delete a node at a certain point

void Addnode(NodePtr N,ElementType Elem);
//to insert a node

void Isempty(NodePtr N);
//to check whether the node is empty or not

void print(NodePtr N);
// to print the node

#endif