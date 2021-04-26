#ifndef GRAPH
#define GRAPH

#include <stdbool.h>

#define IntialSize_Graph 100

typedef int *PtrBST;
typedef int *PtrUser;
typedef int *Minheap;




typedef struct UserNode UserNode;
typedef UserNode *PtrUserNode;

struct UserNode
{
    int ID;
    PtrBST OutVertices;                     // all friends of this user.
    PtrBST InVertices;                      // all members whose friend is this user.
    PtrUser User;                           // info about the user.
    bool Isvalid;
};

typedef struct GraphS GraphS;
typedef struct GraphS *Graph;

struct GraphS
{
    PtrUserNode *UserArray;                // pointer to Adjacency list
    int MAX_Size;                          // book keeping for when to resize.
    int LastId;                            // book keeping for when to resize.
};







Graph Init_Graph(Graph G);
void Print_Graph(Graph G);
void Delete_Graph(Graph *PtrG);

void AddNode(int New_id, Graph G);
void RemoveNode(int Del_Id, Graph G);
void AddEdge(int A, int B, Graph G);
bool checkEdge(int A, int B, Graph G);
void PrintNode(int Node_id, Graph G);

#endif