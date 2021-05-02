#ifndef List_H
#define List_H

// can increase speed by storign properly.
typedef struct ListNode ListNode;
typedef ListNode* PtrListNode;
typedef ListNode* List;

struct ListNode
{
    int value;
    PtrListNode Next;
};
// negative value for dummy list.

List CreateEmptyList(); //verified
void PrintList(List A); // verified
void DeleteList(List* PtrList); //verified


void InsertInList(List A, int New);
void DeleteInList(List A, int elem);
int search(List A, int elem);

#endif
