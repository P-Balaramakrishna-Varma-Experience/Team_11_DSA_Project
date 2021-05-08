#include "../Header/AllModule.h" 


void PrintGElemType(GElementType G)
{
    printf("%d %d\t",G->id,G->level);
}

void DeleteGElemType(GElementType G)
{
    free(G);
}