#include "../Header/AllModule.h" 


int key(struct parametercount *A, int dig)
{
    if (dig == 1)
        return (A->commoncount) % 100000;
    if (dig == 2)
        return ((A->commoncount) / 100000);

    else
        return -2; // to through out of bound error.
}

//range 15
void CountSort(struct parametercount *Array, int Size_of_Array, int Range, int di, int *TempArray, struct parametercount *sortedArray)
{
    struct parametercount *A = Array;

    //itializing second array
    for (int i = 0; i < Range; i++)
        TempArray[i] = 0; // a default

    //create a frequency table.
    for (int i = 0; i < Size_of_Array; i++)
        TempArray[key(&A[i], di)]++;

    // overdie fequency array whith cummlative values
    //0th element remains as its.
    //ith iteration i - 1 element are in cummulative order
    for (int i = 1; i < Range; i++)
    {
        TempArray[i] += TempArray[i - 1];
    } // i elements are in cummlative order.

    //Sorting the Array into sorted Array using Temparay
    int loc;
    for (int i = Size_of_Array - 1; i >= 0; i--)
    {
        loc = TempArray[key(&A[i], di)] - 1; // value is atlest 1
        sortedArray[loc] = A[i];
        TempArray[key(&A[i], di)]--;
    }

    //copying sorted array into input array
    for (int i = 0; i < Size_of_Array; i++)
    {
        A[i] = sortedArray[i];
    }

    //freeing memory
}

void RadixSort(struct parametercount *Array, int Size_of_Array) // function to sort the pcount array
{
    int Range = 15; // Can be put as number of (parameters + 1)
    int *TempArray = malloc((Range) * sizeof(int));
    struct parametercount *sortedArray = malloc((Size_of_Array) * sizeof(struct parametercount));

    for (int i = 1; i < 2; i++)
    {
        CountSort(Array, Size_of_Array, Range, i, TempArray, sortedArray);  // calling of count sort function to sort the pcount array
    }
    free(TempArray);    // freeing the memory occupied by TempArray
    free(sortedArray);  // and sortedArray
}

void toptenrecommendations(Graph info, int newuserID) // we will have t first display the top 10 recommendations and then add the new user to the struct array of PTR to ID's
{
    int i;
    PtrUserNode newuser = info->UserArray[newuserID];   // initializing newuser(a pointer) and equating it to the Pointer to User details of position newuserID
    if(newuser == NULL)                                 // condition when the given ID doesn't point to a Non NULL pointer
    {
        printf("New Id does not exit\n");               // print statement
        return;
    }
    struct parametercount* pcount = (struct parametercount*)malloc((info->MAX_Size)*sizeof(struct parametercount)); //dynamically allocating memory to pcount array equal to the size of struct parametercount*size of graph array 
    for(i=0;i<(info->MAX_Size);i++)
    {
        pcount[i].PtrToDetails = NULL; // Loop to make all PtrToDetails to NULL and
        pcount[i].commoncount = 0;     // commoncount to zero in the pcount array
    }

    for (i = 0; i < (info->MAX_Size); i++)
    {
        if (info->UserArray[i] != NULL && info->UserArray[i] != newuser) // info->UserArray[i] != newuser is to ensure that the user doesnot check for common parameters with himself
        {
            pcount[i].PtrToDetails = info->UserArray[i]->User;
            // Checks for the similarity in year
            if (info->UserArray[i]->User->Year == newuser->User->Year) //The code stores 1 value more than
            {                                                          //number of common parameters for ease
                pcount[i].commoncount++;                               //in count sort
            }
            if (strcmp(info->UserArray[i]->User->Branch, newuser->User->Branch) == 0) // Checks for similarity in the Branch
            {
                pcount[i].commoncount++;
            }
            if (strcmp(info->UserArray[i]->User->Mess, newuser->User->Mess) == 0) // Checks for similarity in the Mess
            {
                pcount[i].commoncount++;
            }
            if (strcmp(info->UserArray[i]->User->Clubs, newuser->User->Clubs) == 0) // Checks for similarity in the clubs
            {
                pcount[i].commoncount++;
            }
            if (strcmp(info->UserArray[i]->User->Sports, newuser->User->Sports) == 0) // Checks for similarity in the Sports interested
            {
                pcount[i].commoncount++;
            }
            (pcount[i].commoncount)++; // Final increment of 1 is to differentiate between a NULL user and a user with No similarly with the new user
        }
    }

    //////////////////////////////////////////////////////////////////////
    // Radix Sorting of pcount array on the basis of commoncount

    RadixSort(pcount, info->MAX_Size);

    // // //End of Radix Sort
    // // ////////////////////////////////////////////////////////////////////


    

    if(pcount[(info->MAX_Size)-1].PtrToDetails == NULL)     // This condition is satisfied if the first user has registered 
    {                                                       // and hence will not have any recommendations
        printf("You are the only user in the System");
        return;
    }

    printf("The Reommendations are :\n");                   // printf statement

    for (i = ((info->MAX_Size) - 1); (i > (info->MAX_Size) - 11 && i >= 0); i--)    // Loop to printf the top recommendations
    {
        if (pcount[i].PtrToDetails == NULL)         // This condition is fulfilled when while printing
        {                                           // there are less than 10 users who are registered in the system
            break;                                  // and hence will break from the loop when pointer to details becomes NULL
        }                                          
        printf("%s %d\n", pcount[i].PtrToDetails->Name,pcount[i].PtrToDetails->ID); // prints the Name of the user and respective ID of the Recommendations
    }

    free(pcount);                                   // frees the memory occupied by pcount array. 
}
