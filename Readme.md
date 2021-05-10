# Project DSA  
# Friends Recommondation TEAM 11
https://github.com/P-Balaramakrishna-Varma/Team_11_DSA_Project.git


## COMPILATION :-
1. gcc -o Project Source/*.c cli.c
2. ./Project

## PRECAUTIONS :-
1. Max word length that can be entered is 50 characters.
2. User should not press enter or space in the beginning when inputing a string.
3. The string is only considered till no space or enter is pressed, other characters after that are rejected.
4. The user must not enter a string when a number is asked for, or else the program might behave abruptly.
5. When the user quits, the program deletes all previously stored user database.

## RUNNING :-
1. The programs displays a welcome page first.
2. The user is given 3 OPTIONS to choose from.
3. OPTIONS are register, login, and quit.
4. If the user enter quits, the program terminates deleting all previously stored data.
5. If the user enters register, they will be asked for the profile parameters to create account.
6. If the user enters login, they will be asked for the login ID to login.
7. If the user enters an invalid command, an error message will be displayed and user will be asked to enter input again.


### OPTIONS->register
1. This option asks user to enter 7 PARAMTER to make profile.
2. PARAMETER are their name(first name), year(college year), branch(college major), club(college club/society), mess(college mess/canteen), sport(favourite sport).
3. User must be very careful while entering their details, because they will only be able to change it in login profile MENU after creating account.
4. Input year is assumed to be > 0 and < 10.
5. If input year is invalid, an error message will be displayed the user will be asked to enter input year again.
6. Once the user completes the input parameter, a message displaying is account created succssfully is displayed.
7. The user will also recieve a login ID, which will be used to login into the account.
8. After successful creation of account, the user is giver 2 OPTIONS to choose from.
9. OPTIONS are login and quit.
10. If the user enters login, they will be asked for the login ID to login.
11. If the user enters quit, they will be directed back to the homepage.
12. If the user enters an invalid command, an error message will be displayed and user will be asked to enter input again.

### OPTIONS->login
1. This options takes the user to a new page where is login ID is asked.
2. If the login ID input exists in program database, then user will successfully login into their account.
3. If the login ID does not exists in program database, an error message will be displayed and user will be asked to enter login ID again.
4. The user can enter 0 to go back to home page.
5. If the login is successful, the user will be taken to account page.
6. The user will have a MENU to choose from.
7. MENU has recommendations, friends, profile, unregister, and logout.
8. If the user enters recommendations, a recommendation list of people will be shown and SUBMENU will be displayed.
9. If the user enters friends, their list of friends will be shown and SUBMENU will be displayed.
10. If the user enters profile, their profile details will be shown and SUBMENU will be displayed.
11. If the user enters unregisters, their account deletion will be confirmed in a new page.
12. If the user enters logout, they will be taken back to the homepage.
13. If the user enters an invalid command, an error message will be displayed and user will be asked to enter input again.



#### MENU->recommendations
1. The list of recommeneded people is displayed.
2. The user will get a SUBMENU to choose from.
3. SUBMENU has befriend and back.
4. If the user enters befriend, they will be asked for the person ID to befriend.
5. If the user enters back, they will go back to the account MENU page.
6. If the user enters an invalid command, an error message will be displayed and user will be asked to enter input again.

##### SUBMENU->befriend
1. The user will be asked to enter person ID to befriend.
2. If the person ID does not exist in program database, an error message will be displayed and user will be asked to enter person ID again or enter 0 to go back to MENU.
3. If the person ID does exist in program database, a message confirming that the person is added to friends list will be displayed.
4. If the user enters an invalid command, an error message will be displayed and user will be asked to enter input again.


#### MENU->friends
1. The list of friends is displayed.
2. The user will get a SUBMENU to choose from.
3. SUBMENU has unfriend, check-status and back.
4. If the user enters unfriend, they will be asked for the friend ID to unfriend.
5. If the user enters check-status, they will be asked for the person ID to check-status.
6. If the user enters back, they will go back to the account MENU page.
7. If the user enters an invalid command, an error message will be displayed and user will be asked to enter input again.

##### SUBMENU->unfriend
1. The user will be asked to enter friend ID to unfriend.
2. If the friend ID does not exist in program database, an error message will be displayed and user will be asked to enter person ID again or enter 0 to go back to MENU.
3. If the friend ID does exist in program database, a message confirming that the person is removed from friends list will be displayed.
4. If the user enters an invalid command, an error message will be displayed and user will be asked to enter input again.

##### SUBMENU->check-status
1. The user will be asked to enter person ID to befriend.
2. If the person ID does not exist in program database, an error message will be displayed and user will be asked to enter person ID again or enter 0 to go back to MENU.
3. If the person ID does exist in program database, a message will be displayed whether the person is in our friends list or not.
4. If the user enters an invalid command, an error message will be displayed and user will be asked to enter input again.


#### MENU->profile
1. The user profile details are displayed.
2. The user will get a SUBMENU to choose from.
3. SUBMENU has modify, and back.
4. If the user enters modify, they will be get PARAMETERS to choose which one to modify.
5. If the user enters back, they will go back to the account MENU page.
6. If the user enters an invalid command, an error message will be displayed and user will be asked to enter input again.

##### SUBMENU->modify
1. The user will get to choose the PARAMETERs to modify.
2. PARAMETERS include name, year, branch, club, mess, sport and back.
3. If the user enters name, they will be asked to enter name again, and a confirmation message of name changed will be displayed.
4. If the user enters year, they will be asked to enter year again, and a confirmation message of year changed will be displayed.
3. If the user enters branch, they will be asked to enter branch again, and a confirmation message of branch changed will be displayed.
3. If the user enters club, they will be asked to enter club again, and a confirmation message of club changed will be displayed.
3. If the user enters mess, they will be asked to enter mess again, and a confirmation message of mess changed will be displayed.
3. If the user enters sport, they will be asked to enter sport again, and a confirmation message of sport changed will be displayed.
3. If the user enters back, they will be directed back to the SUBMENU.
4. If the user enters an invalid command, an error message will be displayed and user will be asked to enter input again.


#### MENU->unregister
1. A new page will open confirming account deletion of user.
2. User should press enter and exit back to home page.


## Testing :-

1. For testing we have created a intial database(state of graph). 
2. To get the data from test case run a.out and copy paste the file content of that test case into the terminal (do not redirect the input directly from the file).
3. Test any feature of your choice by following the instructions in **Running** section
=======

