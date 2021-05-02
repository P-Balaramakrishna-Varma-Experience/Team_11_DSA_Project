#include "CommonHeader.h"
#include <stdlib.h>

int search(NodePtr LLPtr,int b)
{
    NodePtr temp = LLPtr;
    while(temp != NULL)
    {
        if(temp->Elem == b)
        {
            return 1;
        }
        temp = temp->Next;
    }
    return 0;
}

int checkfriendship(Graph G,int a,int b)
{
    int status = search(&((G->UserArray[a])->OutVertices->Bucket[a]) , b);     // returns 1 if friend and
    return status;                                                          // 0 if not a friend
}