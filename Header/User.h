#ifndef User_H
#define User_H

#include "AllModule.h" 

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
typedef struct details* PtrUser;

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
Graph InsertUser(Graph info,MinHeap A,char name[],char branch[],int year , char mess[],char club[],char sports[]);
PtrUserNode AcceptDetails(char name[],char branch[],int year,char mess[],char club[],char sports[]);
void toptenrecommendations(Graph info,int newuserID);


#endif