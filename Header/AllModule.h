#ifndef ALL_M
#define ALL_M

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <time.h>

#include "recomendationB.h"
#include "HashTable.h"
#include "Minheap.h"
#include "deque.h"
#include "User.h"
#include "Graph.h"



#include "userfunc.h"

void AddEdge(int A, int B, Graph G);
void DeleteEdge(int A, int B, Graph G);
int checkfriendship(Graph G, int a, int b);
void deleteUser(Graph G, int user, MinHeap H);
Graph InsertUser(Graph info, MinHeap A, char name[], char branch[], int year, char mess[], char club[], char sports[]);
void Friends_Recomandation_old_user(Graph G, int Start, int K);
void toptenrecommendations(Graph info, int newuserID);
void RecommendFriends(Graph G, int user, int k);
void DeleteUserNode(PtrUser *U);
void PrintFriends(Graph G, int user);



#endif