#ifndef User_H
#define User_H

#include "AllModule.h" 

struct details
{
    int  ID;
    int  Year;
    char Name[51];
    char Branch[10];
    char Sports[31];
    char Mess[21];
    char Clubs[51];
};
typedef struct details* PtrUser;

struct parametercount
{
    struct details* PtrToDetails;
    int commoncount;
};


#endif