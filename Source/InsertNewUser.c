#include "../Header/AllModule.h" 


PtrUserNode AcceptDetails(char name[], char branch[], int year, char mess[], char club[], char sports[]) // other parameters can be added later
{
    PtrUserNode Node = (PtrUserNode)malloc(sizeof(struct UserNode));
    assert(Node != NULL);

    Node->InVertices = NULL;
    Node->OutVertices = NULL;

    struct details *temp = (struct details *)malloc(sizeof(struct details));
    assert(temp != NULL);

    strcpy(temp->Name, name);
    strcpy(temp->Branch, branch);
    temp->Year = year;
    strcpy(temp->Mess, mess);
    strcpy(temp->Clubs, club);
    strcpy(temp->Sports, sports);

    Node->User = temp;

    return Node;
}

Graph InsertUser(Graph info, MinHeap A, char name[], char branch[], int year, char mess[], char club[], char sports[])
{
    PtrUserNode Node = AcceptDetails(name, branch, year, mess, club, sports);
    int leastavailablepos = LeastNum(A);
    if (leastavailablepos == info->MAX_Size)
    {
        info = ResizeGraph(info);
    }
    RmLeastNum(A);
    Node->ID = leastavailablepos;              // There is no use to put ID number at 2 places, written only to understand from where to remove form
    Node->User->ID = leastavailablepos;        // We can remove the ID from either of the place
    info->UserArray[leastavailablepos] = Node; // Adds the user at the least available position
    printf("You are successfully registered with the ID Number : %d\n", leastavailablepos);
    if (IsEmpty(A))
    {
        AddNum((leastavailablepos + 1), A);
    }

    return info;
}
