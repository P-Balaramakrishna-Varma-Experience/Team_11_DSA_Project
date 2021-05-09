#include "../Header/AllModule.h"

int main()
{
    srand((unsigned long int)time(NULL));
    Graph G = Init_Graph(100);
    MinHeap H = Init_min_heap();
    AddNum(1, H);

    for(int i = 0 ; i < 1000; i++)
    InsertUser(G, H, "Aman", "A", 12, "AM", "AC", "AS");
    

    for(int i = 0 ; i < 1000 ;i++)
    {
        for(int j = 0 ; j < 150 ; j++)
        {
            int a = rand()%1000 + 1;
            AddEdge(i+1,a,G);
        }
        //Print_Graph(G);
          //  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    }
    Print_Graph(G);
    printf("\n\n");
    Friends_Recomandation_old_user(G,1,100);
    printf("\n");

    //Print_Graph(G);
    //DeleteGraph(&G);
    //Delete_min_heap(&H);
}