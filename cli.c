#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
#include "graph_bst.c"
#include "HashTable.c"
#include "parameter_bst.c"
#include "deleteUser.c"
#include "add_del_friends.c"
*/

//#include "AllLibraries.h"



int main(void)
{

    //initialise minheap
    //initialise graph
    //initialise 


    char input[25];

    //start page 0
    printf("Welcome! Nice to see you on this beautiful day\n");
    printf("register  login  quit\n");
    printf("type your command here : ");
    scanf("%s", input);

    while(strcmp(input, "quit"))
	{
        //page 1
		if(!strcmp(input, "register"))
		{   
            int age;
            int userid;
            char name[25];
            char branch[4];
            char club[25];
            char mess[25];

            printf("Enter name : ");
            scanf("%s", name);

            printf("Enter age : ");
            scanf("%d", &age);

            printf("Enter branch : ");
            scanf("%s", branch);

            printf("Enter club : ");
            scanf("%s", club);

            printf("Enter mess : ");
            scanf("%s", mess);

            //create account function
            

            //insertuser(graph, minheap, all info)
            printf("Congratulations, your account has been created successfully\n");
            //userid = id generated from minheap = insert user return

            printf("Your login ID is %d, use it to login\n", userid);
            //login directly and give all menu options
            //recommend friends
            //add friends or exit
            printf("register  login  exit\n");
            printf("type your command here : ");
            scanf("%s", input);
        }

        //page 2
        else if(!strcmp(input, "login"))
		{   
            int loginid;
            printf("Enter login ID : ");
            scanf("%d", &loginid);
            if(loginid) //G->userarray[loginid]
            {
                //login function
                printf("Welcome name, how is it going ?\n");  //add %s-name variable
                printf("recommendations  friends-list   profile  unregister   back\n");

                char enter[25];
                printf("type your command here : ");
                scanf("%s", enter);

                while(strcmp(enter, "back"))
                {
                    if(!strcmp(enter, "recommendations"))
                    {
                        //show recommendations
                        printf("insert recommendations list here\n");
                        //add friends
                        char next[25];
                        printf("add-friend id     back\n");
                        printf("type your command here : ");
                        
                        scanf("%s", next); //%d

                        while(strcmp(next, "back"))
                        {
                            if(!strcmp(next, "add-friend"))
                            {
                                int friend;
                                printf("Enter friend id: ");
                                scanf("%d", &friend);
                                //add friend function(AddEdge(loginid, friend)
                                printf("person has beeen added to your friends list\n");
                            }
                            printf("add-friend     back\n");
                            printf("type your command here : ");
                            scanf("%s", next);
                        }
                    }

                    if(!strcmp(enter, "friends-list"))
                    {
                        //print friends list
                        printf("insert friend list here\n");
                        //unfriend
                        char next[25];
                        printf("unfriend     check-status    back\n");
                        printf("type your command here : ");
                        scanf("%s", next);
                        while(strcmp(next, "back"))
                        {
                            if(!strcmp(next, "unfriend"))
                            {
                                int friend;
                                printf("Enter friend id: ");
                                scanf("%d", &friend);
                                //remove friend function
                                //DelEgde(login, friend)
                                printf("person has beeen removed from your friends list\n");
                            }
                            else if(!strcmp(next, "check-status"))
                            {
                                //check status function
                                //char status[25];
                                int friend;
                                printf("Enter person id to check friendship status : ");
                                scanf("%d", friend);
                                int status;
                                //status = check status function
                                if(status)
                                {
                                    printf("person is in your friends list\n");
                                }
                                else
                                {
                                    printf("person is not in your friends list\n");
                                }
                            }
                            printf("unfriend    check-status     back\n");
                            printf("type your command here : ");
                            scanf("%s", next);
                        }
                    }

                    if(!strcmp(enter, "search"))
                    {
                        char find[25];
                        printf("Enter a name to search for : ");
                        scanf("%s", find);
                        //search people
                        //add friends
                        char next[25];
                        printf("add-friend     back\n");
                        printf("type your command here : ");
                        scanf("%s", next);

                        while(strcmp(next, "back"))
                        {
                            if(!strcmp(next, "add-friend"))
                            {
                                //add friend function
                                printf("person has beeen added to your friends list\n");
                            }
                            printf("add-friend     back\n");
                            printf("type your command here : ");
                            scanf("%s", next);
                        }
                    }

                    if(!strcmp(enter, "profile"))
                    {
                        //display details
                        printf("name : s\n");
                        printf("age : s\n");
                        printf("branch : s\n");
                        printf("club : s\n");
                        printf("mess : s\n");
                        //modify
                        char next[25];
                        printf("modify     back\n");
                        printf("type your command here : ");
                        scanf("%s", next);

                        while(strcmp(next, "back"))
                        {
                            if(!strcmp(next, "modify"))
                            {
                                char change[25];
                                printf("name    age    branch    club    mess   back\n");
                                printf("type your command here : ");
                                scanf("%s", change);
                                while(strcmp(change, "back"))
                                {
                                    if(!strcmp(change, "name"))
                                    {
                                        char name[25];
                                        printf("Enter new name : ");
                                        scanf("%s", name);
                                        //change name function
                                        printf("name changed successfully\n");
                                    }
                                    if(!strcmp(change, "age"))
                                    {
                                        int age;
                                        printf("Enter new age : ");
                                        scanf("%d", &age);
                                        //change age function
                                        printf("age changed successfully\n");
                                    }         
                                    if(!strcmp(change, "branch"))
                                    {
                                        char branch[25];
                                        printf("Enter new branch : ");
                                        scanf("%s", branch);
                                        //change branch function
                                        printf("branch changed successfully\n");
                                    }   
                                    if(!strcmp(change, "club"))
                                    {
                                        char club[25];
                                        printf("Enter new club : ");
                                        scanf("%s", club);
                                        //change club function
                                        printf("club changed successfully\n");
                                    }   
                                    if(!strcmp(change, "mess"))
                                    {
                                        char mess[25];
                                        printf("Enter new mess : ");
                                        scanf("%s", mess);
                                        //change mess function
                                        printf("mess changed successfully\n");
                                    }         
                                    printf("name    age    branch    club    mess   back\n");
                                    printf("type your command here : ");
                                    scanf("%s", change);                   
                                }
                            }
                            //display details
                            printf("name : s\n");
                            printf("age : s\n");
                            printf("branch : s\n");
                            printf("club : s\n");
                            printf("mess : s\n");
                            //modify
                            printf("modify     back\n");
                            printf("type your command here : ");
                            scanf("%s", next);
                        }
                    }

                    if(!strcmp(enter, "unregister"))
                    {
                        //deleteUser(graph, login)
                        printf("account deleted succesfully\n");
                        break;
                    }
                    printf("recommendations  friends-list   search   profile  unregister   back\n");
                    printf("type your command here : ");
                    scanf("%s", enter);
                }
            }
            printf("Welcome! Nice to see you on this beautiful day\n");
            printf("register  login  quit\n");
            printf("type your command here : ");
            scanf("%s", input);
        }   
        else
        {
            printf("incorrect command\n");
            printf("type your command again here : ");
            scanf("%s", input);
        }
    }
    
    return 0;
}