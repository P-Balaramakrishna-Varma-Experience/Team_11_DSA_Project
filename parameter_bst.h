#ifndef __BST_H
#define __BST_H

#include <assert.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct node node;
typedef node* tree;
typedef tree PtrTonode; 

struct node {
    int id;
    PtrTonode left;
    PtrTonode right;
    List users;
};

PtrTonode make_node(int e);
PtrTonode InsertNode(tree T, int E);
PtrTonode find(tree T, int e);
void freeNode(PtrTonode P);
// PtrTonode findMin(tree T);
PtrTonode DeleteNode(tree T, int E);
void bstsort(tree T);
// void finddepth(tree T, PtrTonode P);
// int finddepth_util(tree T, PtrTonode P);
// void height(tree T);
// int height_util(tree T);
// void isbst(tree T);
// int IsItBst(tree T, int max, int min);
void swap(int* a, int* b);
tree randomBST(int N);
// void avgDepth();
// void inRange(tree T, int k1, int k2);

#endif