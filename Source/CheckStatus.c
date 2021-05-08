#include "../Header/AllModule.h" 

/* int search(NodePtr LLPtr, int b)
{
    NodePtr temp = LLPtr;
    while (temp != NULL)
    {
        if (temp->Elem == b)
        {
            return 1;
        }
        temp = temp->Next;
    }
    return 0;
} */

int checkfriendship(Graph G, int a, int b)
{
    int status = IsPresent((G->UserArray[b])->OutVertices, a); // returns 1 if friend and
    return status;                                                          // 0 if not a friend
}