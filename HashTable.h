#ifndef __HASH_T
#define __HASH_T

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


typedef struct tab table;
typedef table* Table;

typedef  struct Node* NodePtr;
typedef int ElementType;

struct Node {
    ElementType Elem;
    NodePtr Next;
};

struct tab{
    int size;
    int NumElems;
    NodePtr* Bucket;
};

Table InitTable(int n); // creates a new table of size n
Table ResizeTable(Table T); // resizes the table according to the resize array
void DeleteTable(Table T); // deletes the table
NodePtr CreateNode(int a); // Linked list create function
Table AddElement(Table T, int a); // adds an element to the table (caution do T = AddElement(T, a))
void RemoveElement(Table T, int a); // removes an element from the table
void PrintTable(Table T); // prints the table

#endif