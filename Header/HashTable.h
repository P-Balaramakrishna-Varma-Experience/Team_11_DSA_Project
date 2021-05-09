#ifndef __HASH_T
#define __HASH_T

#include "AllModule.h" 

// This part is an implemetation of linked lists for the purpose of seperate chaining in hastable

typedef struct Node *NodePtr;
typedef int ElementType;

struct Node
{
    ElementType Elem;
    NodePtr Next;
};

// The part ends

typedef struct tab table;
typedef table *Table;

struct tab
{
    int size;
    int NumElems;
    NodePtr *Bucket;
};

// creates a new table of size n
Table InitTable(int n);

// increases the table size according to the resize array
Table IncreaseTableSize(Table T);

// decreases the table size according to the resize array
Table DecreaseTableSize(Table T);

// resizes the table to size s
Table ResizeTable(Table T, int s);

// deletes the table
void DeleteTable(Table T);

// adds an element to the table (caution: always do T = AddElement(T, a) as the table may resize)
Table AddElement(Table T, int a);

// removes an element from the table
Table RemoveElement(Table T, int a);

// returns 1 if 'a' is present in the table ans 0 otherwise
int IsPresent(Table T, int a);

// prints the table
void PrintTable(Table T);

// Linked list create function
NodePtr CreateNode(int a);

#endif