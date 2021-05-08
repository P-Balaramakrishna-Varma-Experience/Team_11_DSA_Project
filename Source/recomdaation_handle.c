#include <stdlib.h>
#include <stdio.h>
#include "../Header/recomendationB.h"


void PrintGElemType(GElementType G)
{
    printf("%d %d\t",G->id,G->level);
}

void DeleteGElemType(GElementType G)
{
    free(G);
}