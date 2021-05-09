#ifndef Recom
#define Recom

struct recommondation
{
    int id;
    int level;
};
typedef struct recommondation *recommondation;
typedef recommondation GElementType;

void PrintGElemType(GElementType G);
void DeleteGElemType(GElementType G);

#endif