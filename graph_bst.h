#ifndef __BST_H
#define __BST_H

#include <assert.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct Node Node;
typedef Node* Tree;
typedef Tree PtrToNode; 

struct Node {
    int id;
    PtrToNode left;
    PtrToNode right;
};

PtrToNode make_node(int e);
PtrToNode InsertNode(Tree T, int E);
PtrToNode FindID(Tree T, int e);
PtrToNode find(Tree T, int e);
void freeNode(PtrToNode P);
// PtrToNode findMin(Tree T);
PtrToNode DeleteNode(Tree T, int E);
void bstsort(Tree T);
// void finddepth(Tree T, PtrToNode P);
// int finddepth_util(Tree T, PtrToNode P);
// void height(Tree T);
// int height_util(Tree T);
// void isbst(Tree T);
// int IsItBst(Tree T, int max, int min);
void swap(int* a, int* b);
Tree randomBST(int N);
// void avgDepth();
// void inRange(Tree T, int k1, int k2);

#endif