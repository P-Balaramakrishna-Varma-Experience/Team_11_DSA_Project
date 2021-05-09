#include "../Header/AllModule.h" 


PtrUserNode AcceptDetails(char name[], char branch[], int year, char mess[], char club[], char sports[]) // Function to Accept the parameter as argument and creating a pointer and storing the details and returning the pointer
{
    PtrUserNode Node = (PtrUserNode)malloc(sizeof(struct UserNode)); // Dynamically allocating the memory to create a PtrUserNode which will be returned by the function
    assert(Node != NULL);

    Node->InVertices = InitTable(101);      // Making the InVertices and OutVertices point to a 
    Node->OutVertices = InitTable(101);     // empty hash table

    // if(Node->InVertices == NULL)
    // {
    //     printf("aJdlkajdkljalkjd\n\n");
    // }

    struct details *temp = (struct details *)malloc(sizeof(struct details)); //dynamically allocating a struct details Ponter which wil be storing all the details of the User
    assert(temp != NULL);

    /* Below 7 statements copy the arguments passed to 
       the function and storing them the struct details 
       Pointer */

    strcpy(temp->Name, name);
    strcpy(temp->Branch, branch);
    temp->Year = year;
    strcpy(temp->Mess, mess);
    strcpy(temp->Clubs, club);
    strcpy(temp->Sports, sports);

    Node->User = temp;      // Equating the Node->User to temp which will be storing the information of that user

    return Node;            // Returning the PtrUserNode to InsertUser function which will be added to the graph array
}

Graph InsertUser(Graph info, MinHeap A, char name[], char branch[], int year, char mess[], char club[], char sports[])
{
    PtrUserNode Node = AcceptDetails(name, branch, year, mess, club, sports);   // Passing the arguments to AcceptDetails create a pointer and return it
    int leastavailablepos = LeastNum(A);         // extracting the minimum element from the minheap
    if (leastavailablepos == info->MAX_Size)    // Resizing the graph when no least availaible is available
    {
        info = ResizeGraph(info);
    }
    RmLeastNum(A);                              // Removing the number extracted from the minheap

    Node->ID = leastavailablepos;              // There is no use to put ID number at 2 places, written only to understand from where to remove form
    Node->User->ID = leastavailablepos;        // We can remove the ID from either of the place
    info->UserArray[leastavailablepos] = Node; // Adds the user at the least available position
    printf("You are successfully registered with the ID Number : %d\n", leastavailablepos);
    if (IsEmpty(A))                             // Adding Element to minheap if is empty
    {
        AddNum((leastavailablepos + 1), A);     
    }

    return info;
}
