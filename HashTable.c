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

Table IncreaseTableSize(Table T) {
    int resize_sizes[] = {101, 211, 401, 809, 1601, 3203, 6421, 12809, 25601};
    int i = 0;
    for(i = 0; i < 9; i++) {
        if(T->NumElems < resize_sizes[i]) {
            break;
        }
    }
    return ResizeTable(T, resize_sizes[i]);
}

Table DecreaseTableSize(Table T) {
    int resize_sizes[] = {101, 211, 401, 809, 1601, 3203, 6421, 12809, 25601};
    int i = 0;
    for(i = 8; i >= 0; i--) {
        if(T->NumElems > resize_sizes[i]) {
            break;
        }
    }
    return ResizeTable(T, resize_sizes[i]);
}

Table ResizeTable(Table T, int s) {
    Table N = InitTable(s);
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
        T = IncreaseTableSize(T);
    }
    int pos = a % T->size;
    NodePtr P = T->Bucket[pos];

    if(P == NULL) {
        T->Bucket[pos] = CreateNode(a);
    } else {
        while(P->Next != NULL) {
            if(P->Elem == a) {
                return T;
            }
            P = P->Next;
        }
        P->Next = CreateNode(a);
    }
    T->NumElems++;
    return T;
}

Table RemoveElement(Table T, int a) {
    int factr = 4; // when to resize
    if(T->NumElems - 1 == T->size / factr) {
        T = DecreaseTableSize(T);
    }
    int pos = a % T->size;
    if(T->Bucket[pos]->Elem == a) {
        NodePtr P = T->Bucket[pos]->Next;
        free(T->Bucket[pos]);
        T->Bucket[pos] = P;
    } else {
        NodePtr P = T->Bucket[pos];
        while(P->Next != NULL && P->Next->Elem != a) {
            P = P->Next;
        }
        if(P->Next == NULL) { // debugging statement
            printf("Element could not be found\n");
            return T;
        } else {
            NodePtr N = P->Next;
            P->Next = N->Next;
            free(N);
        }
    }
    T->NumElems--;
    return T;
}

int IsPresent(Table T, int a) {
    int pos = a % T->size;
    NodePtr P = T->Bucket[pos];

    while(P != NULL) {
        if(P->Elem == a) {
            return 1;
        }
    }

    return 0;
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