#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void registeruser(int i)
{
    printf("register\n");
    //char names[10][50] = {"Shreyas", "Prashant", "Balram", "Durga", "Snehit", "Vedant", "Tanmay", "Meet", "Jash", "Kartick"};
    char branch[7][50] = {"CSD", "CND", "CLD", "CHD", "ECD", "CSE", "ECE"};
    char mess[4][50] = {"Yukhtaar", "NBH", "North", "South"};
    int year[5] = {1, 2, 3, 4, 5};
    char sport[7][50] = {"Cricket", "Footbal", "Chess", "Tennis", "Badminton", "Athletics", "Carrom"};
    char club[8][50] = {"Programming", "ASEC", "Gaming", "ERC", "BajrangDal", "DebSoc", "Literary", "ECell"};
    
    char names[50];
    scanf("%s",names);
    printf("%s\n", names);
    //printf("%s\n", names[i]);

    printf("%d\n", year[rand() % 5]);
    printf("%s\n", branch[rand() % 7]);
    printf("%s\n", club[rand() % 8]);
    printf("%s\n", mess[rand() % 4]);
    printf("%s\n", sport[rand() % 7]);
    printf("home\n");
}

void AddRandomEdges(int NumberofUsers,int MaxRecom)
{
    for (int i = 1; i <= NumberofUsers; i++)
    {
        //assuming to be Menu
        printf("login\n");
        printf("%d\n", i);
        printf("recommendations\n");
        printf("4\n");

        int no_friends_to_add = rand() % MaxRecom + 1;

        for (int j = 0; j < no_friends_to_add; j++)
        {
            int To_friend = rand() % NumberofUsers + 1;
            if(To_friend == i)
            {
                j--;
                continue;
            }

            printf("befriend\n");
            printf("%d\n", To_friend);
        }

        printf("back\n");
        printf("logout\n");
    }
}

int main()
{
    srand(time(NULL));
    for (int i = 0; i < 1000; i++)
    {
        registeruser(i);
    }
    AddRandomEdges(1000,75);
}

