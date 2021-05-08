#ifndef USER_Func_H
#define USER_Func_H

#include "AllModule.h"

int key(struct parametercount* A , int dig);
void CountSort(struct parametercount* Array, int Size_of_Array , int Range, int di,int* TempArray,struct parametercount* sortedArray);
void RadixSort(struct parametercount* Array , int Size_of_Array);
Graph InsertUser(Graph info,MinHeap A,char name[],char branch[],int year , char mess[],char club[],char sports[]);
PtrUserNode AcceptDetails(char name[],char branch[],int year,char mess[],char club[],char sports[]);


#endif