#include "../Header/AllModule.h" 


void AddEdge(int A, int B, Graph G)
{

    int FOUND = IsPresent(G->UserArray[A]->OutVertices, B);

    if (FOUND == 0)
    {
        G->UserArray[A]->OutVertices = AddElement(G->UserArray[A]->OutVertices, B);
        G->UserArray[B]->InVertices = AddElement(G->UserArray[B]->InVertices, A);
    }

    return;
}

void DeleteEdge(int A, int B, Graph G)
{
    int FOUND = IsPresent(G->UserArray[A]->OutVertices, B);

    if (FOUND != 0)
    {
        G->UserArray[A]->OutVertices = RemoveElement(G->UserArray[A]->OutVertices, B);
        G->UserArray[B]->InVertices = RemoveElement(G->UserArray[B]->InVertices, A);
    }

    return;
}
