/* **************************************************************** *
 * THe function in this file is to be invoked in the                *
 * command line interface program                                   *
 * This function checks whether the concerned user has any friends; *
 * if he does he gets the recommendations based on the fact that he *
 * is a old user, otherwise he will be recommended assuming         *
 * he is a new user as recommendations based on friends to a user   *
 * with no friends does not make sense                              *
 * **************************************************************** */

#include "../Header/AllModule.h" 


void RecommendFriends(Graph G, int user, int k)
{
    if (G->UserArray[user] != NULL)
    { // if user exists
        if (G->UserArray[user]->OutVertices->NumElems == 0)
        { // if user has no friends
            printf("You do not have enough friends to get %d recommendations\n", k);
            printf("So we have recommended friends to you based on your simillar interets\n");
            toptenrecommendations(G, user);
        }
        else
        { // if user has some friends
            //printf("else\n");
            // assert(0);
            Friends_Recomandation_old_user(G, user, k);
        }
    }
}

void PrintFriends(Graph G, int user) {
    Table T = G->UserArray[user]->OutVertices;
    if(T != NULL) {
        if(T->NumElems == 0) {
            printf("Your friend list is empty\n");
            return;
        } else {
            printf("Your friends are:\n");
        }
        for (int i = 0; i < T->size; i++)
        {
            if (T->Bucket[i] == NULL)
            {
                continue;
            }
            else
            {
                NodePtr P = T->Bucket[i];
                // printf("%d: ", i);
                while (P != NULL)
                {
                    printf("%s %d\n", G->UserArray[P->Elem]->User->Name, P->Elem);
                    P = P->Next;
                }
                // printf("\n");
            }
        }
    }
}