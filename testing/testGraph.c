#include "../Header/Graph.h"
#include "../Header/HashTable.h"

int main() {
    Graph G = Init_Graph(10);
    G = ResizeGraph(G);
    DeleteGraph(&G);

}