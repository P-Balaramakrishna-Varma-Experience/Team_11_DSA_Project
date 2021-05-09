#ifndef GRAPH
#define GRAPH

#include "AllModule.h" 

#define IntialSize_Graph 100

typedef struct UserNode UserNode;
typedef UserNode *PtrUserNode;

struct UserNode
{
    int ID;
    Table OutVertices; // all friends of this user.
    Table InVertices;  // all members whose friend is this user.
    PtrUser User;      // info about the user.
    bool Isvalid;
};

typedef struct GraphS GraphS;
typedef struct GraphS *Graph;

struct GraphS
{
    PtrUserNode *UserArray; // pointer to Adjacency list
    int MAX_Size;           // book keeping for when to resize.
    // int LastId;                          // book keeping for when to resize.
};

Graph Init_Graph(int n);       // intializes a graph of size 'n' and returns its pointer
Graph ResizeGraph(Graph G);    // resizes the graph size to initial size * fact (currently fact = 5)
void Print_Graph(Graph G);     // Prints the Graph
void DeleteGraph(Graph *PtrG); // Deletes the Graph, argument is a pointer to the concerned Graph

void DeleteUserNode(PtrUser *U); // Utility function for deleting G->User


#endif