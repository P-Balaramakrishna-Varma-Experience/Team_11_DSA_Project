#include "CommonHeader.h"
#include <stdlib.h>
#include <stdio.h>

struct details* AcceptDetails(void) // other parameters can be added later
{
    struct details* temp = (struct details*)malloc(sizeof(struct details));
    assert(temp!=NULL);
    scanf("%d",&temp->age);
    scanf("%s",temp->city);
    return temp;
}

void InsertUser(Graph info,struct details* temp,int leastavailablepos)
{
    temp->ID = leastavailablepos;
    info->UserArray[leastavailablepos]->User = temp;   	// Adds the user at the least available position      
}
