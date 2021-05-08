#include<stdio.h>
#include"Graph.h"
#include"HashTable.h"

void AddEdge(int A, int B, Graph G)
{

    int IsPresent=FindID(G->UserArray[A]->OutVertices,B);

    if (FOUND==0)
    {
        AddElement(G->UserArray[A]->OutVertices, B);
        AddElement(G->UserArray[B]->InVertices, A);
    }

    return;
}

void DeleteEdge(int A, int B, Graph G)
{
    int FOUND=IsPresent(G->UserArray[A]->OutVertices,B);

    if (FOUND!=0)
    {
        RemoveElement(G->UserArray[A]->OutVertices, B);
        RemoveElement(G->UserArray[B]->InVertices, A);
    }

    return;
}

