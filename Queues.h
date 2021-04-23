#ifndef que_h
 
#define que_h
 
// node of a QUE
typedef struct node
{
 int a;
 struct node* NEXT; 
} node;
 
typedef node* PTRNODE;
 
// The ADT for a QUE, using linked list
typedef struct QUE
{
 PTRNODE front; // Points to front
 PTRNODE rear; // Points to rear
} QUE;
 
typedef QUE* ptrQUE;
 
PTRNODE makenode(); // Creates a new node
ptrQUE makeQUE(); // To create a QUE
ptrQUE enQUE(ptrQUE Q, int a); // To enQUE an element
ptrQUE deQUE(ptrQUE Q); // To deQUE an element
bool emptyQUE(ptrQUE Q); // To check whether QUE is empty or not
ptrQUE deleteQUE(ptrQUE Q); // To delete QUE
 
#endif