#include "../Header/AllModule.h"

int main()
{
    srand((unsigned long int)time(NULL));
    Graph G = Init_Graph(100);
    MinHeap H = Init_min_heap();
    AddNum(1, H);

   // for(int i = 0 ; i < 1000; i++)
    InsertUser(G, H, "Aman", "A", 2, "AM", "AC", "AS");
    InsertUser(G, H, "Bman", "B", 2, "AM", "AC", "AS");
    InsertUser(G, H, "Cman", "C", 12, "M", "AC", "AS");
    InsertUser(G, H, "Dman", "A", 2, "A", "AC", "AS");
    InsertUser(G, H, "Eman", "B", 2, "BM", "BC", "BS");
    InsertUser(G, H, "Fman", "C", 1, "C", "CC", "CS");
    InsertUser(G, H, "Gman", "D", 22, "M", "DC", "DS");
    InsertUser(G, H, "Hman", "E", 1, "E", "EC", "ES");
    InsertUser(G, H, "iman", "F", 2, "FM", "FC", "FS");

   /*  for(int i = 0 ; i < 1000 ;i++)
    {
        for(int j = 0 ; j < 150 ; j++)
        // {
            int a = rand()%1000 + 1;
            AddEdge(i+1,a,G);
        } */
        //Print_Graph(G);
          //  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    // }
    //Print_Graph(G);
    printf("\n\n");
    //Friends_Recomandation_old_user(G,1,500);
    toptenrecommendations(G,1);
    printf("\n");

    //Print_Graph(G);
    DeleteGraph(&G);
    Delete_min_heap(&H);
}