#include "../Header/AllModule.h"

int main()
{
    srand((unsigned long int)time(NULL));
    Graph G = Init_Graph(100);
    MinHeap H = Init_min_heap();
    AddNum(1, H);

    InsertUser(G, H, "Aman", "A", 12, "AM", "AC", "AS");
    InsertUser(G, H, "Bman", "B", 2, "BM", "BC", "BS");
    InsertUser(G, H, "Cman", "C", 1, "CM", "CC", "CS");
    InsertUser(G, H, "Dman", "D", 22, "DM", "DC", "DS");
    InsertUser(G, H, "Eman", "E", 10, "EM", "EC", "ES");
    InsertUser(G, H, "Fman", "F", 2, "FM", "FC", "FS");

    AddEdge(1, 3, G);
    AddEdge(2, 3, G);
    AddEdge(2, 5, G);
    AddEdge(3,2,G);

    Print_Graph(G);
    Friends_Recomandation_old_user(G,1,2);


    //Print_Graph(G);
    DeleteGraph(&G);
    Delete_min_heap(&H);
}