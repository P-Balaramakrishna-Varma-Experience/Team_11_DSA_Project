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

// tries to find a node (if not present returns NULL)
PtrToNode find(Tree T, int e);

void freeNode(PtrToNode P);

// finds the smallest element in the tree
PtrToNode findMin(Tree T);

// deletes a node of a particular value
PtrToNode DeleteNode(Tree T, int E);

// prints the bst in a sorted order
void bstsort(Tree T);

void swap(int* a, int* b);

// produces a random bst given n
Tree randomBST(int N);

// destroys the entire tree
void DeleteTree(Tree*);

#endif