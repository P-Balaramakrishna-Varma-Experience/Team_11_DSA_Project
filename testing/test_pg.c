#include <stdio.h>
#include "CommonHeader.h"
#include <stdlib.h>

///////////////////////////////////////////////////////////
// testing for the Sorting code of parametercount array

// int main(void)
// {
//     struct details* arr = malloc(sizeof(struct details)*5);
//     arr[0].ID = 455;
//     arr[1].ID = 584;
//     arr[2].ID = 934;
//     arr[3].ID = 842;
//     arr[4].ID = 201;

//     struct parametercount array[5];

//     array[0].commoncount = 3;
//     array[0].PtrToDetails = &arr[0];

//     array[1].commoncount = 7;
//     array[1].PtrToDetails = &arr[1];

//     array[2].commoncount = 2;
//     array[2].PtrToDetails = &arr[2];

//     array[3].commoncount = 9;
//     array[3].PtrToDetails = &arr[3];

//     array[4].commoncount = 0;
//     array[4].PtrToDetails = &arr[4];

//     RadixSort(array , 5);

//     printf("%d\n",array[0].PtrToDetails->ID);
//     printf("%d\n",array[1].PtrToDetails->ID);
//     printf("%d\n",array[2].PtrToDetails->ID);
//     printf("%d\n",array[3].PtrToDetails->ID);
//     printf("%d\n",array[4].PtrToDetails->ID);
// }

/////////////////////////////////////////////////////////////////////////

//Testing of Inserting 5 elements as well as checking the working of top 10 recommendations

// int main(void)
// {
//     Graph graph = (Graph)malloc(sizeof(GraphS));

//     graph->UserArray = (PtrUserNode*)malloc(sizeof(PtrUserNode)*20);
//     graph->MAX_Size = 20;

//     for(int i=0;i<20;i++)
//     {
//         graph->UserArray[i] = NULL;
//     }

//     PtrUserNode detailPtr = NULL;

//     int i;
//     for(i=0;i<5;i++)
//     {
//         detailPtr = AcceptDetails();
//         InsertUser(graph , detailPtr , i);
//     }
//     detailPtr = AcceptDetails();
//     InsertUser(graph , detailPtr , i);

//     // for(int i=0;i<5;i++)
//     // {
//     //     printf("%s\n",graph->UserArray[i]->User->Name);
//     //     printf("%s\n",graph->UserArray[i]->User->Branch);
//     //     printf("%d\n",graph->UserArray[i]->User->Year);
//     //     printf("%s\n",graph->UserArray[i]->User->Mess);
//     //     printf("%s\n",graph->UserArray[i]->User->Clubs);
//     //     printf("%s\n",graph->UserArray[i]->User->Sports);
//     // }

//     toptenrecommendations(graph , detailPtr , graph->MAX_Size , 6);
// }


///////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

// int main(void)
// {
//     Graph graph = (Graph)malloc(sizeof(GraphS));
//     graph->UserArray = (PtrUserNode *)malloc(sizeof(PtrUserNode) * 20);
//     graph->MAX_Size = 20;

//     for (int i = 0; i < 20; i++)
//     {
//         graph->UserArray[i] = NULL;
//     }

//     PtrUserNode detailPtr = NULL;
//     int i;
//     for (i = 0; i < 12 ; i++)
//     {
//         detailPtr = AcceptDetails();
//         InsertUser(graph, detailPtr, i);
//     }
//     detailPtr = AcceptDetails();
//     InsertUser(graph, detailPtr, i);

//     toptenrecommendations(graph , detailPtr , graph->MAX_Size , 6);
// }

// int main(void)
// {
//     Graph graph = (Graph)malloc(sizeof(GraphS));
//     graph->UserArray = (PtrUserNode *)malloc(sizeof(PtrUserNode) * 20);
//     graph->MAX_Size = 20;

//     for (int i = 0; i < 20; i++)
//     {
//         graph->UserArray[i] = NULL;
//     }

//     PtrUserNode detailPtr = NULL,check = NULL;

//     detailPtr = AcceptDetails();
//     InsertUser(graph, detailPtr, 0);

//     detailPtr = AcceptDetails();
//     InsertUser(graph, detailPtr, 1);

//     detailPtr = AcceptDetails();
//     InsertUser(graph, detailPtr, 2);

//     check = AcceptDetails();
//     InsertUser(graph, check, 3);

//     detailPtr = AcceptDetails();
//     InsertUser(graph, detailPtr, 4);

//     detailPtr = AcceptDetails();
//     InsertUser(graph, detailPtr, 5);



//     // for(int i=0;i<5;i++)
//     // {
//     //     printf("%s\n",graph->UserArray[i]->User->Name);
//     //     printf("%s\n",graph->UserArray[i]->User->Branch);
//     //     printf("%d\n",graph->UserArray[i]->User->Year);
//     //     printf("%s\n",graph->UserArray[i]->User->Mess);
//     //     printf("%s\n",graph->UserArray[i]->User->Clubs);
//     //     printf("%s\n",graph->UserArray[i]->User->Sports);
//     // }
//     toptenrecommendations(graph,check, graph->MAX_Size , 6);
// }


int main(void)
{
    Graph graph = (Graph)malloc(sizeof(GraphS));
    graph->UserArray = (PtrUserNode *)malloc(sizeof(PtrUserNode) * 20);
    graph->MAX_Size = 20;

    for (int i = 0; i < 20; i++)
    {
        graph->UserArray[i] = NULL;
    }

    PtrUserNode detailPtr = NULL;
    int i;
    for (i = 0; i < 11 ; i++)
    {
        detailPtr = AcceptDetails();
        InsertUser(graph, detailPtr, i);
    }

    detailPtr = AcceptDetails();
    InsertUser(graph, detailPtr, i);

    toptenrecommendations(graph , detailPtr , graph->MAX_Size , 10);
}