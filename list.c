#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

List CreateEmptyList()
{
    List L = malloc(sizeof(ListNode));
    assert(L != NULL);

    L->Next = NULL;
    L->value = -200;

    return L;
}

//Nothing is printed implies list is empty.
void PrintList(List A)
{
    //A is dummy node.
    PtrListNode L = A->Next;

    while (L != NULL)
    {
        printf("---%d", L->value);
        L = L->Next;
    }
}

void DeleteList(List *A)
{
    assert(*(A) != NULL);
    List L = *A;

    PtrListNode temp;
    while (L != NULL)
    {
        temp = L;
        L = L->Next;
        free(temp);
    }

    *A = NULL;
}

void InsertInList(List A, int New)
{
    PtrListNode New_ListNode;

    while (A->Next != NULL && A->Next->value != New)
        A = A->Next;

    if (A->Next == NULL) //add element
    {
        New_ListNode = malloc(sizeof(ListNode));
        New_ListNode->value = New;
        New_ListNode->Next = NULL;

        A->Next = New_ListNode;
    }
    else //The element already exits.
        return;
}

int search(List A, int elem)
{
    while (A->Next != NULL && A->Next->value != elem)
        A = A->Next;

    if (A->Next == NULL)
        return 0;
    else //(A->Next->value = elem)
        return 1;
}

void DeleteInList(List A, int elem)
{
    PtrListNode Temp;

    while (A->Next != NULL && A->Next->value != elem)
        A = A->Next;
    //~A.~B = A + B

    if (A->Next == NULL)
        return;
    else //(A->Next->value = elem)
    {
        Temp = A->Next;
        A->Next = A->Next->Next;
        free(Temp);        
    }
}
