#include "../Header/AllModule.h" 


Table InitTable(int n)
{
    Table T = (Table)malloc(sizeof(table)); // allocates memory for the table struct
    if (T == NULL)
    { // failsafe condition
        printf("Memory could not be allocated!!\n");
        exit(0);
    }
    T->size = n;                                             // initializes size of the table
    T->Bucket = (NodePtr *)calloc(T->size, sizeof(NodePtr)); // alloctes memory for the table array
    T->NumElems = 0;                                         // initializes the number of elements in the table as 0
    if (T->Bucket == NULL)
    { // failsafe condition
        printf("Memory could not be allocated!!\n");
        exit(0);
    }
    return T;
}

Table IncreaseTableSize(Table T)
{
    int resize_sizes[] = {101, 211, 401, 809, 1601, 3203, 6421, 12809, 25601}; // array to store designated resize values
    int i = 0;
    for (i = 0; i < 9; i++)
    {
        if (T->NumElems < resize_sizes[i])
        { // finds the next greatest size in the array
            break;
        }
    }
    return ResizeTable(T, resize_sizes[i]); // uses ResizeTable() as a utility function
}

Table DecreaseTableSize(Table T)
{
    int resize_sizes[] = {101, 211, 401, 809, 1601, 3203, 6421, 12809, 25601}; // array to store designated resize values
    int i = 0;
    for (i = 8; i >= 0; i--)
    {
        if (T->NumElems > resize_sizes[i])
        { // finds the next smaller size in the array
            break;
        }
    }
    return ResizeTable(T, resize_sizes[i]); // uses ResizeTable() as a utility function
}

Table ResizeTable(Table T, int s)
{
    Table N = InitTable(s); // creates a new table
    if (N == NULL)
    {
        printf("Memory could not be allocated!!\n");
        exit(0);
    }
    for (int j = 0; j < T->size; j++)
    { // rehashes all the elements in the hashtable
        NodePtr P = T->Bucket[j];
        while (P != NULL)
        {
            AddElement(N, P->Elem);
            P = P->Next;
        }
    }
    DeleteTable(T); // deletes the previous table
    return N;
}

void DeleteTable(Table T)
{
    for (int i = 0; i < T->size; i++)
    { // traverses through all the buckets
        while (T->Bucket[i] != NULL)
        { // frees the nodes of every bucket in the hashtable
            NodePtr P = T->Bucket[i];
            T->Bucket[i] = T->Bucket[i]->Next;
            free(P);
        }
    }
    free(T->Bucket);
    free(T); // frees the table
    T = NULL;
}

Table AddElement(Table T, int a)
{
    if (T->NumElems + 1 > T->size)
    { // checks whether its time to resize
        T = IncreaseTableSize(T);
    }
    int pos = a % T->size; // pos is the hashvalue
    NodePtr P = T->Bucket[pos];

    if (P == NULL)
    { // checks if no other node in the bucket exists
        T->Bucket[pos] = CreateNode(a);
    }
    else
    {
        while (P->Next != NULL)
        { // checks if the same node exists
            if (P->Elem == a)
            {
                return T;
            }
            P = P->Next;
        }
        P->Next = CreateNode(a); // creates a new node at the end of the list
    }
    T->NumElems++; // increases the number of elements variable
    return T;
}

Table RemoveElement(Table T, int a)
{
    int factr = 4; // when to resize
    if (T->NumElems - 1 == T->size / factr)
    { // checks if its time to resize
        T = DecreaseTableSize(T);
    }
    int pos = a % T->size; // pos is the hashvalue
    if (T->Bucket[pos]->Elem == a)
    { // if the first node in the bucket is a itself
        NodePtr P = T->Bucket[pos]->Next;
        free(T->Bucket[pos]);
        T->Bucket[pos] = P;
    }
    else
    {
        NodePtr P = T->Bucket[pos];
        while (P->Next != NULL && P->Next->Elem != a)
        { // tries to find the required node
            P = P->Next;
        }
        if (P->Next == NULL)
        { // debugging statement
            printf("Element could not be found\n");
            return T;
        }
        else
        { // deletes that node
            NodePtr N = P->Next;
            P->Next = N->Next;
            free(N);
        }
    }
    T->NumElems--; // decreases the number of elements variable
    return T;
}

int IsPresent(Table T, int a)
{
    int pos = a % T->size; // pos is the hashvalue
    NodePtr P = T->Bucket[pos];

    while (P != NULL)
    { // tries to find the element
        if (P->Elem == a)
        { // return 1 if found
            return 1;
        }
        P = P->Next;
    }
    // otherwise return 0
    return 0;
}

void PrintTable(Table T)
{
    for (int i = 0; i < T->size; i++)
    {
        if (T->Bucket[i] == NULL)
        {
            continue;
        }
        else
        {
            NodePtr P = T->Bucket[i];
            // printf("%d: ", i);
            while (P != NULL)
            {
                printf("%d ", P->Elem);
                P = P->Next;
            }
            // printf("\n");
        }
    }
}

// utility function for seperate chaining

NodePtr CreateNode(int a)
{
    NodePtr P = (NodePtr)malloc(sizeof(struct Node));
    if (P == NULL)
    {
        printf("Memory could not be allocated!!\n");
        exit(0);
    }
    P->Elem = a;
    P->Next = NULL;

    return P;
}