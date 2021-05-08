#ifndef GRAPH
#define GRAPH


// Copied from Balaramkrishna's Git commit of Graph.h

#include <stdbool.h>

#define IntialSize_Graph 100

typedef struct tab *PtrToTable;             // changed BST to table pointer
typedef struct details *PtrUser;            // changed Int Ptr to Pointer to struct details
typedef int *Minheap;


typedef struct UserNode UserNode;
typedef UserNode *PtrUserNode;

struct UserNode
{
    int ID;
    PtrToTable OutVertices;                     // all friends of this user.
    PtrToTable InVertices;                      // all members whose friend is this user.
    PtrUser User;                               // info about the user.
};

typedef struct GraphS GraphS;
typedef struct GraphS *Graph;

struct GraphS
{
    PtrUserNode* UserArray;                // pointer to Adjacency list
    int MAX_Size;                          // book keeping for when to resize.
    int LastId;                            // book keeping for when to resize.
};
// End of copied code from Balamramkrishna's Git commit



// Copied from Shreyas Git Code of HashTable.h


typedef  struct Node* NodePtr;
typedef int ElementType;

struct Node {
    ElementType Elem;
    NodePtr Next;
};

struct tab
{
    int size;
    int NumElems;
    NodePtr* Bucket;
};

// End of copied code from Shreyas Git commit
/////////////////////////////////////////////////////////////////////

struct details
{
    int  ID;
    int  Year;
    char Name[51];
    char Branch[10];
    char Sports[31];
    char Mess[21];
    char Clubs[51];
};

struct parametercount
{
    struct details* PtrToDetails;
    int commoncount;
};

typedef int *PtrInt;
typedef struct MinHeapS *MinHeap;

struct MinHeapS
{
    int MaxSize;
    int LastIndex;
    PtrInt Heap;
};

int key(struct parametercount* A , int dig);
void CountSort(struct parametercount* Array, int Size_of_Array , int Range, int di,int* TempArray,struct parametercount* sortedArray);
void RadixSort(struct parametercount* Array , int Size_of_Array);
void InsertUser(Graph info,PtrUserNode Node,MinHeap A);
PtrUserNode AcceptDetails(char name[],char branch[],int year,char mess[],char club[],char sports[]);
void toptenrecommendations(Graph info,int newuserID);


#endif