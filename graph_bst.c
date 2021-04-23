#include "graph_bst.h"

PtrToNode make_node(int e) {
    PtrToNode P = (PtrToNode)malloc(sizeof(Node));
    assert(P != NULL);
    P->id = e;
    P->left = NULL;
    P->right = NULL;

    return P;
}

PtrToNode InsertNode(Tree T, int e) {
    if(T == NULL) {
        T = make_node(e);
    }
    else if(e < T->id) {
        T->left = InsertNode(T->left, e);
    }
    else if (e > T->id) {
        T->right = InsertNode(T->right, e);
    }
    return T;
}

PtrToNode FindID(Tree T, int e) {
    return find(T, e)->id;
}

PtrToNode find(Tree T, int e) {
    if(T == NULL)
        return T;
    
    if (e > T->id) {
        return find(T->right, e);
    }
    else if (e < T->id) {
        return find(T->left, e);
    }
    else {
        return T;
    }
}

void freeNode(PtrToNode P) {
    if(P != NULL) {
        free(P);
    }
}

PtrToNode DeleteNode(Tree T, int e) {
    PtrToNode temp;
    if(e < T->id) {
        T->left = DeleteNode(T->left, e);
    }
    else if(e > T->id) {
        T->right = DeleteNode(T->right, e);
    }
    else {
        if (T->left == NULL || T->right == NULL) {
            temp = T;
            if(T->left == NULL) {
                T = T->right;
            }
            else if(T->right == NULL) {
                T = T->left;
            }
            freeNode(temp);
            return T;
        }
        else {
            temp = findMin(T->right);
            T->id = temp->id;
            T->right = DeleteNode(T->right, T->id);
        }
    }
}

void bstsort(Tree T) {
    if(T != NULL) {
        bstsort(T->left);
        printf("%d ", T->id);
        bstsort(T->right);
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

Tree randomBST(int N) {
    Tree T = NULL;
    int perm[N];
    for(int i = 0; i < N; i++) {
        perm[i] = i + 1;
    }

    for(int i = N; i > 0; i--) {
        int j = rand() % i;
        swap(&perm[j], &perm[i - 1]);
    }

    // for(int i = 0; i < N; i++) { // to check permutation
    //     printf("%d ", perm[i]);
    // }
    // printf("\n");

    for(int i = 0; i < N; i++) {
        T = InsertNode(T, perm[i]);
    }

    return T;
}