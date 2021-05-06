#include "CommonHeader.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

PtrUserNode AcceptDetails(void) // other parameters can be added later
{
    PtrUserNode Node = (PtrUserNode)malloc(sizeof(struct UserNode));
    assert(Node!=NULL);

    Node->InVertices = NULL;
    Node->OutVertices = NULL;

    struct details* temp = (struct details*)malloc(sizeof(struct details));
    assert(temp!=NULL);
    //printf("Enter your Name :");
    scanf("%s",temp->Name);

    //printf("Enter your Branch :");
    scanf("%s",temp->Branch);

    //printf("Enter your Year :");
    scanf("%d",&temp->Year);

    //printf("Enter your Mess :");
    scanf("%s",temp->Mess);

    //printf("Enter the club you are in :");
    scanf("%s",temp->Clubs);

    //printf("Enter your coding Level (Level A being highest and F being lowest");
    // scanf("%c",&temp->CodingLevel);

    //printf("Enter your favorite Sport :");
    scanf("%s",temp->Sports);
    
    Node->User = temp;

    return Node;
}

void InsertUser(Graph info,PtrUserNode Node,int leastavailablepos)
{
    Node->ID = leastavailablepos;                   // There is no use to put ID number at 2 places, written only to understand from where to remove form
    Node->User->ID = leastavailablepos;             // We can remove the ID from either of the place
    info->UserArray[leastavailablepos] = Node;   	// Adds the user at the least available position      

    //printf("You are successfully registered with the ID Number : %d",leastavailablepos);
}
