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

    
    while(strcmp(input, "quit"))
	{
        while(strcmp(input, "register") && strcmp(input, "login") && strcmp(input, "quit"))
        {
            printf("Error : incorrect OPTIONS command.\n\n");
            printf("Please type your command again here : ");
            scanf("%s", input);
        }
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
           
            getchar();
            printf("Enter year : ");
            scanf("%d", &year);
            while(year <= 0 || year > 10)
            {
                getchar();
                printf("Error : invalid year\n");
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

            printf("\n\n");
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
            while(strcmp(input, "login") && strcmp(input, "quit"))
            {
                printf("Error : incorrect OPTIONS command.\n\n");
                printf("Please type your command again here : ");
                scanf("%s", input);
            }
        }

        if(!strcmp(input, "login"))
		{   
            printf("\e[1;1H\e[2J");
            int loginid;
            printf("Enter login ID : ");
            scanf("%d", &loginid);
            while(loginid <= 0  && G->UserArray[loginid] == NULL)
            {
                    printf("Error : login ID does not exist.\n\n");
                    printf("Enter login ID again : ");
                    scanf("%d", &loginid);
            }
            if(loginid > 0 && G->UserArray[loginid]) 
            {
                //login function
                printf("\e[1;1H\e[2J");
                printf("Hi, there ! (｡◕‿‿◕｡), how is it going ?\n\n");  
                printf("MENU    :   recommendations     friends        profile     unregister      logout\n\n");

                char enter[WORD_LEN];
                printf("Type your command here : ");
                scanf("%s", enter);

                while(strcmp(enter, "logout"))
                {
                    while(strcmp(enter, "recommendations") && strcmp(enter, "friends") && strcmp(enter, "profile") && strcmp(enter, "unregister") && strcmp(enter, "logout"))
                    {
                    printf("Error : incorrect MENU command.\n");
                    printf("Please type your command again here : ");
                    scanf("%s", enter);
                    }

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
                            while(strcmp(next, "befriend") && strcmp(next, "back"))
                            {
                                printf("Error : incorrect SUBMENU command.\n");
                                printf("Please type your command again here : ");
                                scanf("%s", next);
                            }
                            if(!strcmp(next, "befriend"))
                            {
                                int person = loginid;
                                printf("Enter person ID: ");
                                scanf("%d", &person);
                                while(person <= 0 && G->UserArray[person] == NULL)
                                {
                                    printf("Error : person ID does not exist.\n\n");
                                    printf("Enter person ID again or enter 0 to exit : ");
                                    scanf("%d", &person);
                                    if(person == 0)
                                    {
                                        printf("\n\n");
                                        break;
                                    }
                                }
                                AddEdge(loginid, person, G); // adds friend
                                if(person != 0)
                                {
                                    printf("Person has beeen added to your friends list (^̮^).\n\n");
                                }
                            }
                            if(strcmp(next, "back"))
                            {
                                printf("SUBMENU :   befriend      back\n\n");
                                printf("Type your command here : ");
                                scanf("%s", next);
                            }                          
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
                            while(strcmp(next, "unfriend") && strcmp(next, "check-status") && strcmp(next, "back"))
                            {
                                printf("Error : incorrect SUBMENU command.\n");
                                printf("Please type your command again here : ");
                                scanf("%s", next);
                            }
                            if(!strcmp(next, "unfriend"))
                            {
                                int friend = loginid;
                                printf("Enter friend id: ");
                                scanf("%d", &friend);
                                while(friend <= 0 && G->UserArray[friend] == NULL)
                                {
                                    printf("Error : friend ID does not exist.\n\n");
                                    printf("Enter friend ID again or enter 0 to exit : ");
                                    scanf("%d", &friend);
                                    if(friend == 0)
                                    {
                                        printf("\n\n");
                                        break;
                                    }
                                }
                                DeleteEdge(loginid, friend, G); //remove friend function
                                if(friend != 0)
                                {
                                    printf("Person has beeen removed from your friends list ¯/_(ツ)_/¯.\n\n");
                                }
                            }
                            if(!strcmp(next, "check-status"))
                            {
                                int friend;
                                printf("Enter person id to check friendship status : ");
                                scanf("%d", &friend);
                                //if(checkfriendship(G, loginid, friend)) //return 1 if friend else 0
                                if(checkfriendship(G, loginid, friend))
                                {
                                    printf("Person is in your friends list (ᵔᴥᵔ).\n\n");
                                }
                                else
                                {
                                    printf("Person is not in your friends list ⚆ _ ⚆.\n\n");
                                }
                            }
                            if(strcmp(next, "back"))
                            {
                                printf("SUBMENU :   unfriend        check-status        back\n\n");
                                printf("Type your command here : ");
                                scanf("%s", next);
                            }
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
                            while(strcmp(next, "modify") && strcmp(next, "back"))
                            {
                                printf("Error : incorrect SUBMENU command.\n");
                                printf("Please type your command again here : ");
                                scanf("%s", next);
                            }
                            if(!strcmp(next, "modify"))
                            {
                                char change[WORD_LEN];
                                printf("PARAMETERS :   name        year     branch       club       mess       sport       back\n\n");
                                printf("type your command here : ");
                                scanf("%s", change);
                                while(strcmp(change, "back"))
                                {
                                    while(strcmp(change, "name") && strcmp(change, "year") && strcmp(change, "branch") && strcmp(change, "club") && strcmp(change, "mess") && strcmp(change, "sport") && strcmp(change, "back"))
                                    {
                                    printf("Error : incorrect PARAMETER command.\n");
                                    printf("Please type your command again here : ");
                                    scanf("%s", change);
                                    }
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
                                    if(strcmp(change, "back"))
                                    {
                                        printf("MODIFY :   name        age     ranch       club        mess        back\n\n");
                                        printf("Type your command here : ");
                                        scanf("%s", change);
                                    }                   
                                }
                            }
                            //display details
                            if(strcmp(next, "back"))
                            {
                                printf("name : s\n");
                                printf("year : s\n");
                                printf("branch : s\n");
                                printf("club : s\n");
                                printf("mess : s\n");
                                printf("sport : s\n");
                                printf("SUBMENU :   modify      back\n\n");
                                printf("Type your command here : ");
                                scanf("%s", next);
                            }
                            
                            //modify
                            
                        }
                    }

                    if(!strcmp(enter, "unregister"))
                    {
                        deleteUser(G, loginid, H);
                        printf("\e[1;1H\e[2J");
                        printf("Account deleted succesfully.\n\n");
                        printf("We will miss you (>人<).\n\n");

                        printf("Press ENTER key to exit : ");
                        getchar();
                        getchar();
                        break;
                    }
                    printf("MENU    :   recommendations     friends      profile        unregister        logout\n\n");
                    printf("type your command here : ");
                    scanf("%s", enter);
                }
            }
        }   
        printf("\e[1;1H\e[2J");
        printf("Welcome! Nice to see you on this beautiful day (◕‿◕✿).\n");
        printf("OPTIONS :   register        login       quit\n\n");
        printf("type your command here : ");
        scanf("%s", input);
    }
    printf("\e[1;1H\e[2J");
    
    return 0;
}