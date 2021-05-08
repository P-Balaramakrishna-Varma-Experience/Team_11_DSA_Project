#include "Header/AllModule.h"

#define WORD_LEN 50


int main(void)
{

    MinHeap H = Init_min_heap();
    AddNum(1,H);
    Graph G = Init_Graph(1000);
    

    printf("\e[1;1H\e[2J");
    char input[WORD_LEN];

    //start page 0
    printf("Welcome! Nice to see you on this beautiful day (◕‿◕✿).\n\n");
    printf("OPTIONS :   register        login       quit\n\n");
    printf("Type your command here : ");
    scanf("%s", input);

    while(strcmp(input, "register") && strcmp(input, "login") && strcmp(input, "quit") && strcmp(input, "\n") && strcmp(input, "\0"))
    {
        printf("Error : incorrect command\n");
        printf("Please type your command again here : ");
        scanf("%s", input);
    }
    while(strcmp(input, "quit"))
	{
		if(!strcmp(input, "register"))
		{   
            printf("\e[1;1H\e[2J");
            int year;
            char name[WORD_LEN];
            char branch[WORD_LEN];
            char club[WORD_LEN];
            char mess[WORD_LEN];
            char sport[WORD_LEN];

            printf("Caution!    :   Do not use space or enter button while entering parameters.\n\n");
            printf("Enter name : ");
            scanf("%s", name);
            /*
            while(strcmp(name, "\n") && strcmp(name, "\0"))
            {
            printf("Error : invalid name\n");
            printf("Please enter your name again here : ");
            scanf("%s", name);
            }
            */

            printf("Enter age : ");
            scanf("%d", &year);
            while(year < 0)
            {
            printf("Error : invalid age\n");
            printf("Please enter your year again here : ");
            scanf("%d", &year);
            }

            printf("Enter branch : ");
            scanf("%s", branch);


            printf("Enter club : ");
            scanf("%s", club);


            printf("Enter mess : ");
            scanf("%s", mess);


            printf("Enter sport : ");
            scanf("%s", sport);

            //create account function
            printf("Congratulations, your account has been created successfully (~˘▾˘)~.\n\n");
            //insertuser(graph, minheap, all info)
            InsertUser(G, H, name, branch, year, mess, club, sport);

            printf("\n\n");

            //login directly and give all menu options
            //recommend friends
            //add friends or exit
            printf("OPTIONS :   login       quit\n\n");
            printf("Type your command here : ");
            scanf("%s", input);
        }

        //page 2
        else if(!strcmp(input, "login"))
		{   
            int loginid;
            printf("Enter login ID : ");
            scanf("%d", &loginid);
            if(loginid > 0 && G->UserArray[loginid]) 
            {
                //login function
                printf("\e[1;1H\e[2J");
                printf("Hi, there ! (｡◕‿‿◕｡), how is it going ?\n\n");  
                printf("MENU    :   recommendations     friends        profile     unregister      logout\n");

                char enter[WORD_LEN];
                printf("Type your command here : ");
                scanf("%s", enter);

                while(strcmp(enter, "recommendations") && strcmp(enter, "friends-list") && strcmp(enter, "profile") && strcmp(enter, "unregister") && strcmp(enter, "logout") && strcmp(enter, "\n") && strcmp(enter, "\0"))
                {
                    printf("Error : incorrect command\n");
                    printf("Please type your command again here : ");
                    scanf("%s", enter);
                }

                while(strcmp(enter, "logout"))
                {
                    if(!strcmp(enter, "recommendations"))
                    {
                        //show recommendations
                        int k = 10;
                        RecommendFriends(G, loginid, k); //prints recommendation list
                        //add friends
                        char next[WORD_LEN];
                        printf("SUBMENU :   befriend       back\n\n");
                        printf("Type your command here : ");
                        
                        scanf("%s", next);

                        while(strcmp(next, "back"))
                        {
                            if(!strcmp(next, "befriend"))
                            {
                                int friend = loginid;
                                printf("Enter friend id: ");
                                scanf("%d", &friend);
                                AddEdge(loginid, friend, G); // adds friend
                                printf("Person has beeen added to your friends list (^̮^).\n\n");
                            }
                            printf("SUBMENU :   befriend      back\n\n");
                            printf("Type your command here : ");
                            scanf("%s", next);
                        }
                    }

                    if(!strcmp(enter, "friends"))
                    {
                        PrintTable(G->UserArray[loginid]->OutVertices);//print friends list seg..
                        char next[WORD_LEN];
                        printf("SUBMENU :   unfriend        check-status        back\n\n");
                        printf("Type your command here : ");
                        scanf("%s", next);
                        while(strcmp(next, "back"))
                        {
                            if(!strcmp(next, "unfriend"))
                            {
                                int friend = loginid;
                                printf("Enter friend id: ");
                                scanf("%d", &friend);
                                DeleteEdge(loginid, friend, G); //remove friend function
                                printf("Person has beeen removed from your friends list ¯/_(ツ)_/¯.\n\n");
                            }
                            else if(!strcmp(next, "check-status"))
                            {
                                int friend;
                                printf("Enter person id to check friendship status : ");
                                scanf("%d", &friend);
                                if(checkfriendship(G, loginid, friend)) //return 1 if friend else 0
                                {
                                    printf("Person is in your friends list (ᵔᴥᵔ).\n\n");
                                }
                                else
                                {
                                    printf("Person is not in your friends list ⚆ _ ⚆.\n\n");
                                }
                            }
                            printf("SUBMENU :   unfriend        check-status        back\n\n");
                            printf("Type your command here : ");
                            scanf("%s", next);
                        }
                    }


                    if(!strcmp(enter, "profile"))
                    {
                        //display details
                        printf("name : s\n");
                        printf("year : s\n");
                        printf("branch : s\n");
                        printf("club : s\n");
                        printf("mess : s\n");
                        printf("sport : s\n");
                        //modify
                        char next[WORD_LEN];
                        printf("SUBMENU :   modify      back\n\n");
                        printf("Type your command here : ");
                        scanf("%s", next);

                        while(strcmp(next, "back"))
                        {
                            if(!strcmp(next, "modify"))
                            {
                                char change[WORD_LEN];
                                printf("MODIFY :   name        year     branch       club       mess       sport       back\n\n");
                                printf("type your command here : ");
                                scanf("%s", change);
                                while(strcmp(change, "back"))
                                {
                                    printf("Caution : do not use space or enter button while entering parameters.\n\n");
                                    if(!strcmp(change, "name"))
                                    {
                                        char name[WORD_LEN];
                                        printf("Enter new name : ");
                                        scanf("%s", name);
                                        //change name function
                                        printf("name changed successfully\n\n");
                                    }
                                    if(!strcmp(change, "year"))
                                    {
                                        int year;
                                        printf("Enter new year : ");
                                        scanf("%d", &year);
                                        //change age function
                                        printf("year changed successfully\n\n");
                                    }         
                                    if(!strcmp(change, "branch"))
                                    {
                                        char branch[WORD_LEN];
                                        printf("Enter new branch : ");
                                        scanf("%s", branch);
                                        //change branch function
                                        printf("branch changed successfully\n\n");
                                    }   
                                    if(!strcmp(change, "club"))
                                    {
                                        char club[WORD_LEN];
                                        printf("Enter new club : ");
                                        scanf("%s", club);
                                        //change club function
                                        printf("club changed successfully\n\n");
                                    }   
                                    if(!strcmp(change, "mess"))
                                    {
                                        char mess[WORD_LEN];
                                        printf("Enter new mess : ");
                                        scanf("%s", mess);
                                        //change mess function
                                        printf("mess changed successfully\n\n");
                                    } 
                                    if(!strcmp(change, "sport"))
                                    {
                                        char sport[WORD_LEN];
                                        printf("Enter new sport : ");
                                        scanf("%s", sport);
                                        //change mess function
                                        printf("sport changed successfully\n\n");
                                    }        
                                    printf("MODIFY :   name        age     ranch       club        mess        back\n\n");
                                    printf("Type your command here : ");
                                    scanf("%s", change);                   
                                }
                            }
                            //display details
                            printf("name : s\n");
                            printf("year : s\n");
                            printf("branch : s\n");
                            printf("club : s\n");
                            printf("mess : s\n");
                            printf("sport : s\n");
                            //modify
                            printf("SUBMENU :   modify      back\n\n");
                            printf("Type your command here : ");
                            scanf("%s", next);
                        }
                    }

                    if(!strcmp(enter, "unregister"))
                    {
                        deleteUser(G, loginid, H);
                        printf("\e[1;1H\e[2J");
                        printf("Account deleted succesfully.\n\n");
                        printf("We will miss you (>人<).\n\n");

                        char exit[WORD_LEN];
                        printf("Type anything to exit : ");
                        scanf("%s", exit);
                        if(!strcmp(exit, "exit"))
                        {
                            break;
                        }
                        else if(strcmp(exit, "exit"))
                        {
                            break;
                        }
                    }
                    printf("MENU    :   recommendations     friends      profile        unregister        logout\n");
                    printf("type your command here : ");
                    scanf("%s", enter);
                }
            }
            printf("\e[1;1H\e[2J");
            printf("Welcome! Nice to see you on this beautiful day (◕‿◕✿).\n");
            printf("OPTIONS :   register        login       quit\n\n");
            printf("type your command here : ");
            scanf("%s", input);
        }   
        printf("\e[1;1H\e[2J");
    }
    
    return 0;
}