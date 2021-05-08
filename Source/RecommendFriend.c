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
        if (G->UserArray[user]->OutVertices == NULL)
        { // if user has no friends
            printf("You do not have enough friends to get %d recommendations\n", k);
            printf("So we have recommended friends to you based on your simillar interets\n");
            toptenrecommendations(G, user);
        }
        else
        { // if user has some friends
            Friends_Recomandation_old_user(G, user, k);
        }
    }
}