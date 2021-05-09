#include "../Header/AllModule.h"

void TRandomizeij(int *A, int i, int j,int N) //int k is reduntand
{
    int ranNum;

    for (int loop = i; loop <= j; loop++)
    {
        ranNum = rand() % (j - i + 1) + i;

        int temp = A[loop];
        A[loop] = A[ranNum];
        A[ranNum] = temp;
    }
}

void PrintArra(int *A, int N)
{
    printf("\n");
    for (int i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void ReadArray(int *A, int N)
{
    for (int i = 0; i < N; i++)
        scanf("%d ", &A[i]);
}

void main()
{
    int i, j;
    int *A;
    int N;
    srand((unsigned int)(time(NULL)));

    scanf("%d", &N);

    A = malloc(sizeof(int) * N);
    ReadArray(A, N);
    scanf("%d %d", &i, &j);
    TRandomizeij(A, i, j,N);
    PrintArra(A, N);
}