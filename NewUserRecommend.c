#include <stdio.h>
#include "CommonHeader.h"

int key(struct parametercount* A , int dig)
{
    if(dig == 1)
        return (A->commoncount)%100000;
    if(dig == 2)
        return ((A->commoncount)/100000);
    
    else return -2; // to through out of bound error.
}


//range 100000
void CountSort(struct parametercount* Array, int Size_of_Array , int Range, int di,int* TempArray,struct parametercount* sortedArray)
{
    struct parametercount* A = Array;

    //itializing second array
    for(int i = 0; i < Range; i++)
        TempArray[i] = 0; // a default

    //create a frequency table.
    for(int i = 0 ; i< Size_of_Array ; i++)
        TempArray[key(&A[i],di)]++;

    // overdie fequency array whith cummlative values
    //0th element remains as its.
    //ith iteration i - 1 element are in cummulative order
    for(int i = 1 ; i < Range ; i++)
    {
        TempArray[i] += TempArray[i-1];
    }// i elements are in cummlative order.


    //Sorting the Array into sorted Array using Temparay
    int loc;
    for(int i = Size_of_Array -1 ; i >= 0 ; i--)
    {
        loc = TempArray[key(&A[i],di)] - 1;  // value is atlest 1
        sortedArray[loc] = A[i];
        TempArray[key(&A[i],di)]--;
    }
    
    //copying sorted array into input array
    for(int i = 0 ; i < Size_of_Array ; i ++)
    {
        A[i] = sortedArray[i];
    }

    //freeing memory

}


void RadixSort(struct parametercount* Array , int Size_of_Array)
{
    int Range = 100000;                                         // Can be put as number of (parameters + 1)
    int* TempArray = malloc((Range)*sizeof(int)); 
    struct parametercount* sortedArray = malloc((Size_of_Array)*sizeof(struct parametercount));

    for(int i = 1 ; i < 2 ; i++)
    {
        CountSort(Array,Size_of_Array,Range,i,TempArray,sortedArray);
    }
    free(TempArray);
    free(sortedArray);
}


void toptenrecommendations(Graph info,struct details* newuser,int arrsize,int numofparameters)// we will have t first display the top 10 recommendations and then add the new user to the struct array of PTR to ID's
{
    int i;
    struct parametercount* pcount = (struct parametercount**)malloc(arrsize*sizeof(struct parametercount));
    for(i=0;i<arrsize;i++)
    {
        pcount[i].PtrToDetails = NULL;
        pcount[i].commoncount = 0;
    }
    for(i=0;i<arrsize;i++)
    {
        if(info->UserArray[i]->User!=NULL)
        {
            pcount[i].PtrToDetails = info->UserArray[i]->User;
            if(info->UserArray[i]->User->age == newuser->age)            //The code stores 1 value more than 
            {                                                            //number of common parameters for ease
                pcount[i].commoncount++;                               //in count sort 
            }
            if(strcmp(info->UserArray[i]->User->city,newuser->city)==0)
            {
                pcount[i].commoncount++;
            }
            (pcount[i].commoncount)++;
        }
    }
    //////////////////////////////////////////////////////////////////////
    // Radix Sorting of pcount array on the basis of commoncount

    RadixSort(pcount,info->LastId);

    //End of Radix Sort
    ////////////////////////////////////////////////////////////////////


    printf("The Reommendations are :\n");

    
    ////////////////////////////////////////////////////////////////////////////
    // We can write code to display the top 10 (or less than 10) recommendations in random
    // orderby using rand() for a group of UserID's with same number of common parameters
    ////////////////////////////////////////////////////////////////////////////
    for(i=(arrsize-1);i>arrsize-11;i--)
    {
        if(pcount[i].PtrToDetails == NULL)
        {
            break;
        }
        printf("%d\n",pcount[i].PtrToDetails->ID);
    }
}
