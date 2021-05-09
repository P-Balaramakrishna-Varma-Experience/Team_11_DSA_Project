#ifndef User_H
#define User_H

#include "AllModule.h" 

struct details
{
    int  ID;
    int  Year;
    char Name[51];
    char Branch[51];
    char Sports[51];
    char Mess[51];
    char Clubs[51];
};
typedef struct details* PtrUser;

struct parametercount
{
    struct details* PtrToDetails;
    int commoncount;
};


#endif