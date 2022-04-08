//importing libraries
#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include <string.h>
#include <stdbool.h>

//inserting headerfiles
 //#include "userGuess.h"
//#include "randomNumber.h"


//opens a .txt file for reading which contains extra information for the user's convienence
void openExtraInfo() {
  //creating a string variable which is capable of housing an incredibly large number of characters
  char str[2000000];
  int x;

  FILE* f1 = fopen("extrainfo.txt", "r");
  for (x = 0; x < 32; x++) {
    //prints 32 lines from the txt file
    fgets(str, 2000000, f1);
    printf("%s", str);
  }
  fclose(f1);
}

//this function opens a .txt file for reading which contains the list of rooms
void openRoom() {
  //creating a string variable which is capable of housing an incredibly large number of characters
  char str[2000000];
  int x;

  FILE* f1 = fopen("rooms.txt", "r");
  for (x = 0; x < 8; x++) {
    //prints 8 lines from the txt file
    fgets(str, 2000000, f1);
    printf("%s", str);
  }
  fclose(f1);
}

//opens a .txt file for reading which contains the list of weapons
void openWeapons() {
  //creating a string variable which is capable of housing an incredibly large number of characters
  char str[2000000];
  int x;

  FILE* f1 = fopen("weapons.txt", "r");
  for (x = 0; x < 8; x++) {
    //prints 8 lines from the txt file
    fgets(str, 2000000, f1);
    printf("%s", str);
  }
  fclose(f1);
}

//this function opens a .txt file for reading which contains the list of suspects
void openSuspects() {
  //creating a string variable which is capable of housing an incredibly large number of characters
  char str[2000000];
  int x;

  FILE* f1 = fopen("suspects.txt", "r");
  for (x = 0; x < 8; x++) {
    //prints 8 lines from the txt file
    fgets(str, 2000000, f1);
    printf("%s", str);
  }
  fclose(f1);
}

//this function opens a .txt file which contains info about the kitchen
void openKitchenFile() {
  //creating a string variable which is capable of housing an incredibly large number of characters
  char str[2000000];
  int x;

  FILE* f1 = fopen("Kitchen.txt", "r");
  for (x = 0; x < 69; x++) {
    //prints 69 lines from the txt file
    fgets(str, 2000000, f1);
    printf("%s", str);
  }
  fclose(f1);
}

//This function opens a .txt file for reading and prints the beginning of the storyline
void story(int y, int z) {
  //large string variable to allow for an entire line to print
  char str[2000000];
  int x;
  //opening the file and printing all lines from it
  FILE* f1 = fopen("Storyline.txt", "r");
  for (x = y; x < z; x++) {
    fgets(str, 2000000, f1);
    printf("%s", str);
  }
  fclose(f1);
}

//Ammending the text file, to show the correct and incorrect guesses
int userguess(int guess, int real) {
  //opening the file for appending
  FILE* ptr = fopen("records.txt", "a");
  //print the guess in the records.txt file and to the screen
  if (guess == real) {
    fprintf(ptr, "Correct: %d\n", guess);
    printf("Your guess is correct\n");
    return 0;
  } 
  else {
    fprintf(ptr, "Incorrect: %d\n", guess);
    printf("Incorrect\n");
    return 1;
  }
  fclose(ptr);
}
//initializing a function which will randomly choose a number given a range from the user
int randomNumber(int range) {
  int newNumber;
  //srand(time(NULL));
  newNumber = rand()% range + 1;
  return newNumber;
}

typedef struct userGuess {
  int murderer;
  int weapon;
  int room;
}
userGuess;

//errorCheck function that should work with any situation and thoroughly checks for errors
typedef struct inputs {
    int errorCheck;
    int input;
} Input;
Input errorCheck (int userInput, int range, char errorStatement[100]){
        Input errorCheck;
        char line[100];

        printf("userInput = %d", userInput);
        for (x=0;x<strlen(errorStatement);x++){
            if (errorStatement[x] == '0'){
                if ((userInput > range) || (userInput < 0)){
                    printf("\n\n Error, input is out of bounds. \n\n");
                    errorCheck.errorCheck=1;
                    while (errorCheck.errorCheck ==1){
                        printf("%s", errorStatement);
                        fgets(line,100,stdin);
                        errorCheck.input=atoi(line);
                        errorCheck=errorCheck(errorCheck.input, range, errorStatement);
                    }
                }
            }
            else if ((userInput > range) || (userInput < 1)){
                printf("\n\n Error, input is out of bounds. \n\n");
                errorCheck.errorCheck=1;
                while (errorCheck.errorCheck ==1){
                        printf("%s", errorStatement);
                        fgets(line,100,stdin);
                        errorCheck.input=atoi(line);
                        errorCheck=errorCheck(errorCheck.input, range, errorStatement);
                }
            }
            else
                errorCheck.errorCheck=0;
        }
        return errorCheck;
}


int explore(int room, int roomreal) {
  Input exploreCheck;
  switch (room) {
  case 1:
    //Telling the user what is in the room
    printf("\nYou explore the Kitchen. You notice a cupboard is out of place.");
    //Clue to whether this room is the real room
    if (roomreal == room) {
      printf("\nThere is blood splattered on the cupboards.");
    }
    printf("\nWould you like to investigate? (0 for yes, 1 for no): ");
    scanf("%d", &exploreCheck.input);
    
    //Error checking
    exploreCheck = errorCheck(exploreCheck.input, 2, "\nWould you like to take it? (0 for yes, 1 for no): ");
    
    
    //Secret Passage
    if (exploreCheck.input == 0) {
      printf("\nYou notice that there is a passage that can take you to one of the other rooms.");
      printf("\nWould you like to take it? (0 for yes, 1 for no): ");
      scanf("%d", & exploreCheck.input);
      if (ans == 0)
    
    //Error checking
    exploreCheck = errorCheck(exploreCheck.input, 2, "\nWould you like to take it? (0 for yes, 1 for no): ");

        explore(3, roomreal);
    }
    break;

  case 2:
    printf("\nYou explore the Lounge.");
    if (roomreal == room) {
      printf("\nThere is dried blood on one of the couches.");
    }
    break;

  case 3:
    printf("\nYou explore the Library. You notice that there is a bookshelf slightly shifted.");
    if (roomreal == room) {
      printf("\nThere seems to be some type of blood on one of the books.");
    }
    printf("\nWould you like to investigate? (0 for yes, 1 for no): ");
    scanf("%d", & exploreCheck.input);
              //Error checking
    exploreCheck= errorCheck(exploreCheck.input, 2, "\nWould you like to take it? (0 for yes, 1 for no): ");

    if (exploreCheck.input == 0) {
      printf("\nYou notice that there is a passage that can take you to one of the other rooms.");
      printf("\nWould you like to take it? (0 for yes, 1 for no): ");
      scanf("%d", & exploreCheck.input);
                //Error checking
    exploreCheck = errorCheck(exploreCheck.input, 2, "\nWould you like to take it? (0 for yes, 1 for no): ");
      if (ans == 0)
        explore(1, roomreal);
    }
    break;

  case 4:
    printf("\nYou explore the Ball Room.");
    if (roomreal == room) {
      printf("\nThere is smeared blood on the flooring.");
    }
    break;

  case 5:
    printf("\nYou explore the Biliard Room. You notice that there is a lift in the carpet.");
    if (roomreal == room) {
      printf("\nOne of the pool cues seems to be broken.");
    }
    printf("\nWould you like to investigate? (0 for yes, 1 for no): ");
    scanf("%d", &exploreCheck.input);
    //Error checking
    exploreCheck = errorCheck(exploreCheck.input, 2, "\nWould you like to take it? (0 for yes, 1 for no): ");

    if (exploreCheck.input == 0) {
      printf("\nYou notice that there is a passage that can take you to one of the other rooms.");
      printf("\nWould you like to take it? (0 for yes, 1 for no): ");
      scanf("%d", &exploreCheck.input);
      if (exploreCheck.input == 0)
    //Error checking
    exploreCheck = errorCheck(ans, 2, "\nWould you like to take it? (0 for yes, 1 for no): ");

        explore(7, roomreal);
    }
    break;

  case 6:
    printf("\nYou explore the Conservatory.");
    if (roomreal == room) {
      printf("\nYou notice some smudged blood on one of the windows.");
    }
    break;

  case 7:
    printf("\nYou explore the Dining Room. You notice that there is some type of indentation in the wood underneeth the table.");
    if (roomreal == room) {
      printf("\nThere is blood under the table.");
    }
    printf("\nWould you like to investigate? (0 for yes, 1 for no): ");
    scanf("%d", &exploreCheck.input);
    //Error checking
    exploreCheck = errorCheck(exploreCheck.input, 2, "\nWould you like to take it? (0 for yes, 1 for no): ");
    

    if (exploreCheck.input == 0) {
      printf("\nYou notice that there is a passage that can take you to one of the other rooms.");
      printf("\nWould you like to take it? (0 for yes, 1 for no): ");    
      scanf("%d", &exploreCheck.input);
      
          //Error checking
    exploreCheck = errorCheck(exploreCheck.input, 2, "\nWould you like to take it? (0 for yes, 1 for no): ")
    
      if (exploreCheck.input == 0)
        explore(5, roomreal);
    }
    break;

  default:
    printf("\nERROR");
    break;
  }
}

void testweap(int weap) {
  if (weap == 1)
    printf("\nThe blood appears to be splattered on, someone is trying to make this more difficult for me.");
  else if (weap == 2)
    printf("\nThis blood looks fresher than the other two.");
  else if (weap == 3)
    printf("\nThere seems to be some bloody finger prints on this one.");
  else
    printf("\nERROR: NO PROPER CHOICE SELECTED. MOVING ONTO NEXT PROCESS.");
}

}
void investigate(int person, int murderer, int per1, int per2, int per3, int per4, int per5, int per6) {
    openSuspects();
  switch (person) {
  case 1:
  if (person==murderer){
    printf("\nI was in the kitchen with %d the entire time.", per1);
  }
  else
  printf("\nI was busy preparing dessert in the kitchen, %d came into the room around the time I was finished", murderer);
  case 2:
  if (person==murderer){
    printf("\nI was in the kitchen with %d the entire time.", per1);
  }
  else
  printf("\nI saw Mr.Peters go into the ballroom with %d earlier that night, then %d and I talked in the Dining Room", per3, per5);
  case 3:
  if (person==murderer){
    printf("\nI was in the kitchen with %d the entire time.", per1);
  }
  else
  printf("\n Mr.Peters and I were in the ballroom dancing but then they left into the Conservatory");
  case 4:
  if (person==murderer){
    printf("\nI was in the kitchen with %d the entire time.", per1);
  }
  else
  printf("\nI saw %d go into the Conservatory, but I never saw them leave", murderer);
  case 5:
  if (person==murderer){
    printf("\nI was in the kitchen with %d the entire time.", per1);
  }
  else
  printf("\n%d and I were talking in the Dining Room all night about the affair between Mr.Peters and %d, we cant believe that they could do this to %d!", per2, per3, murderer);
  case 6:
  if (person==murderer){
    printf("\nI was in the kitchen with %d the entire time.", per1);
  }
  else
  printf("\n");
  case 7:
  if (person==murderer){
    printf("\nI was in the kitchen with %d the entire time.", per1);
  }
  else
  printf("\n");
  }
}


//Beginning combat functions

int criticalHitFunction(int target){
//rolls randomly between 1-10 to find critical hits, varies based on position of attack, the higher the attack the higher the critical strike chance
  int roll, critical;
  srand(time( NULL() );
  roll=rand()%11;
  if ((target==3) && (roll <= 6))
        critical=1;
  if else ((target==2) && (roll <= 4))
        critical=1;
  if else ((target ==1) && (roll <=2))
        critical=1;
  else
        critical=0;
  return critical;
}
int damageFunction(int weapon, int critical){
	if (weapon ==1)
		weaponDamage=3;
	if else ((weapon ==2) || (weapon ==7))
		weaponDamage=4;
	if else ((weapon ==3) || (weapon ==5))
		weaponDamage=1;
	if else ((weapon ==4) || (weapon ==6))
		weaponDamage = 2;
    if (critical ==1)
        weaponDamage=weaponDamage*2;
	return weaponDamage;
}
//errorCheck function that should work with any situation and thoroughly checks for errors
int errorCheck (int userInput, int range, char errorStatement[100]){
        int errorCheck;
        char line[100];

        printf("userInput = %d", userInput);

        if ((userInput > range) || (userInput < 1)){
                printf("\n\n Error, input is out of bounds. \n\n");
                errorCheck=1;
                while (errorCheck ==1){
                        printf("%s", errorStatement);
                        fgets(line,100,stdin);
                        userInput=atoi(line);
                        errorCheck=errorCheck(userInput, range, errorStatement);
                }
        }
        else
                errorCheck=0;
        return errorCheck;
}

typedef struct combatInputs{
		int target;
		int success;
        int dammage;
	} Sequence;

Sequence combatFunction(int attackingPlayerNumber, blockingPlayerNumber){

	Sequence attack, block;
  Input errorCheck;

	printf("Player %d you are attacking now, press 1, 2, or 3 to attack: ", attackingPlayerNumber);
	inputCheck=scanf("%d", attack.target);
    errorCheck(attack.target, 3, "Please try again, press 1, 2, or 3 to attack: ");
    attack.target=errorCheck.input;
	

	printf("Player %d, press 1, 2, or 3 to block their attack: ", blockingPlayerNumber);
	inputCheck=scanf("%d", block.target);
	errorCheck(block.target, 3, "Please try again, press 1, 2, or 3 to block Player %d's attack: ");
  block.target=errorCheck.input;
    
	if (attackerChoice == blockerChoice)
		attack.success = 1;
	else
		attack.success = 0;
	return attack;
}


int main() 
{
    //Establish the variables, they are separated into catagories based on what potion of the code they belong to
    userGuess Guess;
    int murderer, weapon, room, userInput, errorCheck, correctGuess;
    int countermur = 0, countwea = 0, countroo = 0;
    int weap1, weap2, weap3, whichone;
    int per1, per2, per3, per4, per5, per6;
    Input errorCheck;
    
    //randomizer in time
    srand(time(NULL));

    //opens the big list of options, and the story line
    openExtraInfo(0, 36);
    story(0, 54);

    //establishing all of the actual variables for the murder
    murderer = randomNumber(7);
    weapon = randomNumber(7);
    room = randomNumber(7);

    //establishing the numbers for each person
    per1 = randomNumber(7);
    per2 = randomNumber(7);
    per3 = randomNumber(7);
    per4 = randomNumber(7);
    per5 = randomNumber(7);
    per6 = randomNumber(7);
    while((per1 == murderer) || (per2 == murderer) ||(per3 == murderer) ||(per4 == murderer) ||(per5 == murderer) ||(per6 == murderer))
    {
        //srand(time(NULL))
        per1 = randomNumber(7);
        per2 = randomNumber(7);
        per3 = randomNumber(7);
        per4 = randomNumber(7);
        per5 = randomNumber(7);
        per6 = randomNumber(7);
    } 

    //Error checking, please delete before turning in
    printf("%d, %d, %d", murderer, weapon, room);

    //The start of searching for the room
    printf("\n");
    openRoom();
    printf("\n");

    //promting the user to find out what room they'd like to explore
    printf("\nWhat room would you like to explore? (please enter a number): ");
    scanf("%d", &userInput);

    //Error checking
    errorCheck = errorCheck(userInput, 7, "What room would you like to explore? (please enter an integer) ");
    

    //this is the function to go inside individual rooms
    explore(userInput, room);
    printf("\nWould you like to keep exploring? (0 for yes, 1 for no): ");
    scanf("%d", &userInput);

    //Error checking
    errorCheck = errorCheck(userInput, 2, "\nWould you like to keep exploring? (0 for yes, 1 for no): ");
    userInput=errorCheck.input;

    //If the user wishes to continue exploring
    while (userInput == 0) {
      printf("\nWhat room would you like to explore? (please enter a number): ");
      scanf("%d", & userInput);
      //Error checking
      errorCheck = errorCheck(userInput, 7, "\nWhat room would you like to explore? (please enter a number): ");
      userInput=errorCheck.input;

      explore(userInput, room);
      printf("\nWould you like to keep exploring? (0 for yes, 1 for no): ");
      scanf("%d", & userInput);

      //Error checking
      errorCheck = errorCheck(userInput, 2, "\nWould you like to keep exploring? (0 for yes, 1 for no): ");
      userInput=errorCheck.input;
    }

    //Opens the list of rooms
    printf("\n");
    openRoom();
    printf("\n");

    //This is where the user will guess where the murder happened
    printf("\nWhere did it happen: (please enter an integrer)");
    scanf("%d", & Guess.room);

    //Error checking
    errorCheck = errorCheck(Guess.room, 7, "\nWhere did it happen: (please enter an integrer)");
    Guess.room=errorCheck.input;
    correctGuess = userguess(Guess.room, room);

    //correctGuess is the variable that returns whether the guess was correct or not
    //If the guess is incorrect this code reprompts them
    if (correctGuess == 0) {} else if (correctGuess == 1) {
      printf("\nWould you like to try again? (0 for yes, 1 for no): ");
      scanf("%d", & userInput);

      //Error check
      errorCheck = errorCheck(userInput, 2, "\nWould you like to try again? (0 for yes, 1 for no): ");
      userInput=errorCheck.input;

      //places the user into a loop until they want to exit or guess correctly
      while (userInput == 0) {
        printf("\n\nWhere did it happen: (please enter an integer)");
        scanf("%d", & Guess.room);

        //Error checking
        errorCheck = errorCheck(Guess.room, 7, "\nWhere did it happen: (please enter an integrer)");
        Guess.room=errorCheck.input;

        correctGuess = userguess(Guess.room, room);

        if (correctGuess == 0) {
          userInput = 0;
        } else {
          printf("\nWould you like to try again? (0 for yes, 1 for no): ");
          scanf("%d", & userInput);

          //Error check
          errorCheck = errorCheck(userInput, 2, "\nWould you like to try again? (0 for yes, 1 for no): ");
          userInput=errorCheck.input;
        }
      }
    }

    //opening the list of weapons
    printf("\n");
    openWeapons();
    printf("\n");

    //randomizing where the real weapon is 
    //srand(time(NULL));
    whichone = randomNumber(3);

    //randomizing the weapon choices for the user
    switch (whichone) {
    case 1:
      weap1 = weapon;
      weap2 = randonNumber(7);
      weap3 = randomNumber(7);
      break;
    case 2:
      weap2 = weapon;
      weap1 = randomNumber(7);
      weap3 = randomNumber(7);
      break;
    case 3:
      weap3 = weapon;
      weap2 = randomNumber(7);
      weap1 = randomNumber(7);
      break;
    }

    //The weapons randomized above are the choices for the weapon
    printf("\nYou are now in the room where the murder happened. You notice three weapons, all have some from of blood on them.");
    printf("\n 1. %d, 2. %d, 3. %d", weap1, weap2, weap3);

    //prompting the user to invesitgate the weapons
    printf("\nWhich one would you like to invesitgate first? (type 1 for %d, 2 for %d, 3 for %d): ", weap1, weap2, weap3);
    scanf("%d", &userInput);

    //Error checking
    errorCheck = errorCheck(userInput, 4);
    userInput=errorCheck.input;
    while (errorCheck == 1) {
      userInput = 0;
      printf("\nWhich one would you like to invesitgate first? (type 1 for %d, 2 for %d, 3 for %d): ", weap1, weap2, weap3);
      scanf("%d", &userInput);
      errorCheck = errorCheck(userInput, 4);
      userInput = errorCheck.input;
    }

    testweap(userInput);
    printf("\nWould you like to keep invesitgating? (0 for yes, 1 for no): ");
    scanf("%d", & userInput);
    //Error check
      errorCheck = errorCheck(userInput, 2, "\nWould you like to keep invesitgating? (0 for yes, 1 for no): ");
      userInput = errorCheck.input;
      
      

    //If the user wants to continue to investgate it send them here
    while (userInput == 0) {
      printf("\nWhich one would you like to invesitgate? (type 1 for %d, 2 for %d, 3 for %d): ", weap1, weap2, weap3);
      scanf("%d", & userInput);

      //Error checking
      errorCheck = errorCheck(userInput, 3);
      userInput = errorCheck.input;
      while (errorCheck == 1) {
        userInput = 0;
        printf("\nWhich one would you like to invesitgate? (type 1 for %d, 2 for %d, 3 for %d): ", weap1, weap2, weap3);
        scanf("%d", & userInput);
        errorCheck = errorCheck(userInput, 3);
      }

      testweap(userInput);
      printf("\nWould you like to keep invesitgating? (0 for yes, 1 for no): ");
      scanf("%d", & userInput);

      //Error check
      errorCheck = errorCheck(userInput, 2, "\nWould you like to try again? (0 for yes, 1 for no): ");
      userInput = errorCheck.input;
    }

    //This is where the user will guess what was used in the murder
    printf("\nWhat was used to kill them: (please enter an integrer): ");
    scanf("%d", & Guess.weapon);

    //Error checking
    errorCheck = errorCheck(Guess.weapon, 7, "\nWhat was used to kill them: (please enter an integrer): ");
    Guess.weapon = errorCheck.input;
    correctGuess = userguess(Guess.weapon, weapon);

    //correctGuess is the variable that returns whether the guess was correct or not
    //If the guess is incorrect this code repromts one more time
    if (correctGuess == 0) {} else if (correctGuess == 1) {
      printf("\nWould you like to try again? (0 for yes, 1 for no): ");
      scanf("%d", & userInput);
      //Error check
      errorCheck = errorCheck(userInput, 2, "\nWould you like to try again? (0 for yes, 1 for no): ");
      userInput = errorCheck.input;

      if (userInput == 0) {
        printf("\n\nWhat was used to kill them: (please enter an integrer): ");
        scanf("%d", & Guess.weapon);

        //Error checking
        errorCheck = errorCheck(Guess.weapon, 7, "\n\nWhat was used to kill them: (please enter an integrer): ");
        Guess.weapon = errorCheck.input;
        //testing against the correct guess to see if the user has guessed the weapon correctly
        correctGuess = userguess(Guess.weapon, weapon);
      }
    }
    //BEGINNING SUSPECT INVESTIGATION
    //Opens the list of suspects
    printf("\n");
    openSuspects();
    printf("\n");

    //Prompting the user to invesitage the suspects
    printf("\nCHOOSE WHO YOU'D LIKE TO INVESITGATE (please enter a number): ");
    scanf("%d", & userInput);
    //Error checking
    errorCheck = errorCheck(userInput, 7, "\nCHOOSE WHO YOU'D LIKE TO INVESITGATE (please enter a number): ");
    userInput = errorCheck.input;


    investigate(userInput, murderer, per1, per2, per3, per4, per5, per6);

    printf("\nWould you like to keep invesitgating? (0 for yes, 1 for no): ");
    scanf("%d", & userInput);

    //Error checking
    errorCheck = errorCheck(userInput, 2, "\nWould you like to keep invesitgating? (0 for yes, 1 for no): ");
    userInput = errorCheck.input;

    //If the user wants to continue to investgate it send them here
    while (userInput == 0) {
      printf("\nCHOOSE WHO YOU'D LIKE TO INVESITGATE (please enter a number): ");
      scanf("%d", & userInput);

      //Error checking
      errorCheck = errorCheck(userInput, 7, "\nCHOOSE WHO YOU'D LIKE TO INVESITGATE (please enter a number): ");
      userInput = errorCheck.input;

      investigate(userInput, murderer, per1, per2, per3, per4, per5, per6);
      printf("\nWould you like to keep invesitgating? (0 for yes, 1 for no): ");
      scanf("%d", & userInput);

      //Error checking
      errorCheck = errorCheck(userInput, 2, "\nWould you like to keep invesitgating? (0 for yes, 1 for no): ");
        
    }
    //Guess who is the murderer
    printf("\n\nWho is the murderer: (please enter an integer)");
    scanf("%d", & Guess.murderer);

    //Error checking
    errorCheck = errorCheck(Guess.murderer, 7, "\n\nWho is the murderer: (please enter an integer)");
    Guess.murderer = errorCheck.input;

    //testing their guess against the correct value
    correctGuess = userguess(Guess.murderer, murderer);

    //correctGuess is the variable that returns whether the guess was correct or not
    //If the guess is incorrect this code reprompts them
    if (correctGuess == 0) {} else if (correctGuess == 1) {
      printf("\nWould you like to try again? (0 for yes, 1 for no): ");
      scanf("%d", & userInput);

      //Error check
      errorCheck = errorCheck(userInput, 2), "\nWould you like to try again? (0 for yes, 1 for no): ";
      userInput = errorCheck.input;
      while (userInput == 0) {
        printf("\n\nWho is the murderer: (please enter an integer)");
        scanf("%d", & Guess.murderer);

        //Error checking
        errorCheck = errorCheck(Guess.murderer, 7, "\n\nWho is the murderer: (please enter an integer)");
        Guess.murderer = errorCheck.input;

        //checking their guess against the proper value      
        correctGuess = userguess(Guess.murderer, murderer);

        if (correctGuess == 0) {
          userInput = 0;
        } 
        else {
          printf("\nWould you like to try again? (0 for yes, 1 for no): ");
          scanf("%d", & userInput);
          //Error check
          errorCheck = errorCheck(userInput, 2, "\nWould you like to try again? (0 for yes, 1 for no): ");
          userInput = errorCheck.input;
        }
      }
    }
    /*
    //displaying statements to begin the fight, informing the user of the basic rules
    printf("%s: You'll never catch me alive!", murdererName);
    printf("%s grabs the %s and runs into the %s... you follow them", murdererName, weapon, room);
    printf("They've gone mad, you have to stand your ground. The rules are simple, incapacitate him before he can take you down\n");
        
    //giving them the option to read more rules just in case
    printf("\nDo you want more rules? (0 for yes, 1 for no)");
    scanf("%d", &userInput);
    errorCheck = errorCheck(userInput, 2, "\nDo you want more rules? (0 for yes, 1 for no)");
    userInput = errorCheck.input;

    printf("\n\n FIGHT \n\n");
    int playerNumber, critical, result, weaponDamage, healthPlayers[1,2]=10,10;
    playerNumber=1;
    weaponDamage=damageFunction(weaponNumber)
    while ((healthPlayers[1]!=0) && (healthPlayers[2]!=0)){ 

	    if (playerNumber==1){
        succesfulHit=combatFunction(1,2);
		    critical=criticalHitFunction(userChoice);
        weaponDamage=damageFunction(weaponNumber, critical);
		    
      }
		  
      if (succesfulHit==1){
			  printf("Succesful Hit!\n");
			  healthPlayer[1]=healthPlayer[1]-weaponDamage;
		  else{
			  healthPlayer[1]=healthPlayer[1]-(weaponDamage/2);
			  printf("Your attack was blocked, and dealt half the weaponDamage");
			  printf("Your health: %.1f\n%s's health: %.1f\n", healthPlayer[1], murdererName, healthPlayer[2]);
		    playerNumber+=1;
		}
	    if else (playerNumber ==2){
		    result=combatFunction(2);
		    weaponDamage=damageFunction(weaponNumber)
        criticalHitFunction(userChoice)
        
        if result=1
          healthPlayer[2]=healthPlayer[2]-weaponDamage;
        else
         	healthPlayer[2]=healthPlayer[2]-(weaponDamage/2);
        }
      }
    }
  */
  }