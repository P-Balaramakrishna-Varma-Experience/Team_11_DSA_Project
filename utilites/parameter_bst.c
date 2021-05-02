#include "parameter_bst.h"

PtrTonode make_node(int e) {
    PtrTonode P = (PtrTonode)malloc(sizeof(node));
    assert(P != NULL);
    P->id = e;
    P->left = NULL;
    P->right = NULL;
    P->users = NULL;

    return P;
}

PtrTonode InsertNode(tree T, int e) {
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

PtrTonode find(tree T, int e) {
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

void freeNode(PtrTonode P) {
    if(P != NULL) {
        free(P);
    }
}

PtrTonode DeleteNode(tree T, int e) {
    PtrTonode temp;
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

void bstsort(tree T) {
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

tree randomBST(int N) {
    tree T = NULL;
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