#ifndef User_H
#define User_H

#include "AllModule.h" 

struct details              // This struct stores the details of any user of the entire System
{
    int  ID;                // The seven units that are stored in the struct are :
    int  Year;              // 1. ID of the user  2. The year in which he studies  3. The name of the user
    char Name[51];          // 4. The Branch in which he studies  5. The Sport he likes the most   6. The Mess alloted to him
    char Branch[51];        // 7. The club he is most interested in
    char Sports[51];
    char Mess[51];
    char Clubs[51];
};
typedef struct details* PtrUser;

struct parametercount
{                                       // struct which is used in the New User Recommend function which consists of 2 
    struct details* PtrToDetails;       // units one which stores the Pointer to the struct details and another stores 
    int commoncount;                    // the number of common parameters with the new user and user at ith position of graph array
};


#endif