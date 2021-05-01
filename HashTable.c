#include "HashTable.h"

Table InitTable(int n) {
    Table T = (Table)malloc(sizeof(table));
    if(T == NULL) {
        printf("Memory could not be allocated!!\n");
        assert(0);
    }
    T->size = n;
    T->Bucket = (NodePtr*)calloc(T->size, sizeof(NodePtr));
    T->NumElems = 0;
    if(T->Bucket == NULL) {
        printf("Memory could not be allocated!!\n");
        assert(0);
    }
    return T;
}

Table ResizeTable(Table T) {
    int resize_sizes[] = {101, 211, 401, 809, 1601, 3203, 6421, 12809, 25601};
    int i = 0;
    for(i = 0; i < 9; i++) {
        if(T->size != resize_sizes[i]) {
            break;
        }
    }
    Table N = InitTable(resize_sizes[i]);
    if(N == NULL) {
        printf("Memory could not be allocated!!\n");
        assert(0);
    }
    for(int j = 0; j < T->size; j++) {
        NodePtr P = T->Bucket[j];
        while(P != NULL) {
            AddElement(N, P->Elem);
            P = P->Next;
        }
    }
    DeleteTable(T);
    return N;
}

void DeleteTable(Table T) {
    for(int i = 0; i < T->size; i++) {
        while(T->Bucket[i] != NULL) {
            NodePtr P = T->Bucket[i];
            T->Bucket[i] = T->Bucket[i]->Next;
            free(P);
        }
    }
    // free(T->Bucket);
    free(T);
    T = NULL;
}

NodePtr CreateNode(int a) {
    NodePtr P = (NodePtr)malloc(sizeof(struct Node));
    if(P == NULL) {
        printf("Memory could not be allocated!!\n");
    }
    P->Elem = a;
    P->Next = NULL;

    return P;
}

Table AddElement(Table T, int a) {
    if(T->NumElems + 1 > T->size) {
        T = ResizeTable(T);
    }
    int pos = a % T->size;
    NodePtr P = T->Bucket[pos];

    if(P == NULL) {
        T->Bucket[pos] = CreateNode(a);
    } else {
        T->Bucket[pos] = CreateNode(a);
        T->Bucket[pos]->Next = P;
    }
    T->NumElems++;
    return T;
}

void RemoveElement(Table T, int a) {
    int pos = a % T->size;
    if(T->Bucket[pos]->Elem == a) {
        NodePtr P = T->Bucket[pos]->Next;
        free(T->Bucket[pos]);
        T->Bucket[pos] = P;
    } else {
        NodePtr P = T->Bucket[pos];
        while(P->Next != NULL && P->Next->Elem != a) {
            continue;
        }
        if(P->Next == NULL) {
            printf("Element could not be found\n");
        } else {
            NodePtr N = P->Next;
            P->Next = N->Next;
            free(N);
        }
    }
}

void PrintTable(Table T) {
    for(int i = 0; i < T->size; i++) {
        if(T->Bucket[i] == NULL) {
            continue;
        } else {
            NodePtr P = T->Bucket[i];
            printf("%d: ", i);
            while(P != NULL) {
                printf("%d ", P->Elem);
                P = P->Next;
            }
            printf("\n");
        }
    }
}