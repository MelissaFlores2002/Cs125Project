//importing libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

//header files--these contain the structs we use 
#include "Guesses.h"
#include "Input.h"
#include "Sequence.h"


//All of the functions we use have been put into sepreate .c files to make our main code cleaner
//checks whether the users guess is correct or wrong, then ammends it to a file
int userGuessCheck(int guess, int real);

//how we check our user inputs 
int errorCheck(int userInput, int range, char errorStatement[100]);

//opening files for story/rules/lists
void openRoom();
void openFightRulesFile();
void openWeapons();
void openSuspects();
void story(int y, int z);

//checking if the user has travled to a room already
bool beenInRoomCheck(int room, int* roomsExplored, int* numberOfRooms);

//what the user gets to explore for the rooms 
int explore(int room, int roomreal, int* roomsExploredStored, int* roomsExplored);

//
void testWeap(int input, int fakeWeaponOne, int fakeWeaponTwo, int realWeapon);

//letting the user investigate the suspects
void investigate(int person, int murderer, int* innocentsArray);

//finding the strings for each of the portions for the fighting portion
void findMurdererName(int murdererNumber, char* murdererName);
void findWeaponName(int weaponNumber, char* weaponName);
void findRoomName(int roomNumber, char* roomName);

//Beginning combat functions
int criticalHitFunction(int target);
float damageFunction(int weapon, int critical);
int AItargetFunction();
Sequence AICombatFunction(int playerTurn);
Sequence combatFunction(int attackingPlayerNumber, int blockingPlayerNumber);

//single player mode function
int singlePlayerFightSequence(int weaponOne, int weaponTwo);

//multiplayer mode function
int multiPlayerFightSequence(int weaponOne, int weaponTwo);


//beginning main function
int main() {
  //Establish the variables, they are separated into catagories based on what potion of the code they belong to
  userGuess Guess;
  Input errorCheckTest;

  int murderer, weapon, room, userInput, inputCheck, correctGuess, numPlayers;
  int weap1, weap2, weap3, detectiveWeaponOne, detectiveWeaponTwo, whichWeapon, detectiveWeapon;
  int innocentsArray[6], loopCounter, secondLoopCounter;

  //variables for explore purposes
  int* roomsExploredStored=(int*)malloc(sizeof(int)*100);
  int* roomsExplored=(int*)malloc(sizeof(int));
  //line to convert input to int using atoi
  char line[100];

  //allocating memory for each string, all of these strings will have their memory changed later
  char* murdererString=(char*)malloc(100*sizeof(char));
  char* weaponString=(char*)malloc(100*sizeof(char));
  char* detectiveWeaponString=(char*)malloc(100*sizeof(char));
  char* roomString=(char*)malloc(100*sizeof(char));

  //seeding time to allow for true random values from here to the end of the code
  srand(time(NULL));

  //opens the big list of options, and the story line, beginning code
  openExtraInfo(0, 36);
  story(0, 54);

  //establishing all of the actual variables for the murder
  murderer = randomNumber(7);
  weapon = randomNumber(7);
  room = randomNumber(7);

  //establishing the numbers for each person
  for (loopCounter=0; loopCounter<(sizeof(innocentsArray)); loopCounter++){
    innocentsArray[loopCounter]=randomNumber(7);
    for (secondLoopCounter=sizeof(innocentsArray); secondLoopCounter<0; secondLoopCounter--){
      while ((innocentsArray[loopCounter]) == (innocentsArray[secondLoopCounter])){
        innocentsArray[loopCounter]=randomNumber(7);
      }
    }
  }
  

  for (loopCounter=0; loopCounter<7; loopCounter++){
    printf("%d", innocentsArray[loopCounter]);
  }
  //Error checking, we use this to speed through the code 
  //printf("%d, %d, %d", murderer, weapon, room);

  //The start of searching for the room
  printf("\n");
  openRoom();
  printf("\n");

  //promting the user to find out what room they'd like to explore
  printf("\nWhat room would you like to explore? (please enter a number): ");
  scanf("%d", &userInput);

  //Error checking
  errorCheckTest = errorCheck(userInput, 7, "What room would you like to explore? (please enter an integer) ");
  userInput=errorCheckTest.userInput;
  
  //this is the function to go inside individual rooms
  explore(userInput, room, roomsExploredStored, roomsExplored);
  printf("\nWould you like to keep exploring? (1 for yes, 2 for no): ");
  scanf("%d", &userInput);
    
  //Error checking
  errorCheckTest = errorCheck(userInput, 2, "\nWould you like to keep exploring? (1 for yes, 2 for no): ");
  userInput=errorCheckTest.userInput;

  //If the user wishes to continue exploring
  while (userInput == 1) {
    openRoom();
    printf("\nWhat room would you like to explore? (please enter a number): ");
    scanf("%d", & userInput);
    //Error checking
    errorCheckTest = errorCheck(userInput, 7, "\nWhat room would you like to explore? (please enter a number): ");
    userInput=errorCheckTest.userInput;

    explore(userInput, room, roomsExploredStored, roomsExplored);
    printf("\nWould you like to keep exploring? (1 for yes, 2 for no): ");
    scanf("%d", &userInput);

    //Error checking
    errorCheckTest = errorCheck(userInput, 2, "\nWould you like to keep exploring? (1 for yes, 2 for no): ");
    userInput=errorCheckTest.userInput;
  }

  //Opens the list of rooms
  printf("\n");
  openRoom();
  printf("\n");

  //This is where the user will guess where the murder happened
  printf("\nWhere did it happen: (please enter an integer) ");
  scanf("%d", &Guess.room);

  //Error checking
  errorCheckTest = errorCheck(Guess.room, 7, "\nWhere did it happen: (please enter an integer)");
  Guess.room=errorCheckTest.userInput;
  correctGuess = userGuessCheck(Guess.room, room);

  //correctGuess is the variable that returns whether the guess was correct or not
  //If the guess is incorrect this code reprompts them
  if (correctGuess == 1) {
    printf("\nWould you like to try again? (1 for yes, 2 for no): ");
    scanf("%d", &userInput);

    //Error check
    errorCheckTest = errorCheck(userInput, 2, "\nWould you like to try again? (1 for yes, 2 for no): ");
    userInput=errorCheckTest.userInput;

    //places the user into a loop until they want to exit or guess correctly
    while (userInput == 1) {
      printf("\n\nWhere did it happen: (please enter an integer)");
      scanf("%d", &userInput);
      //Error checking
      errorCheckTest = errorCheck(Guess.room, 7, "\nWhere did it happen: (please enter an integrer)");
      Guess.room=errorCheckTest.userInput;
      //checking to see if their guess was the correct answer
      correctGuess = userGuessCheck(Guess.room, room);
      //if the guess is corect, do not run through the while loop again
      if (correctGuess == 0) {
        userInput = 2;
      } 
      else {
        printf("\nWould you like to try again? (1 for yes, 2 for no): ");
        scanf("%d", &userInput);

        //Error check
        errorCheckTest = errorCheck(userInput, 2, "\nWould you like to try again? (1 for yes, 2 for no): ");
        userInput=errorCheckTest.userInput;
      }
    }
  }

  //opening the list of weapons
  printf("\n");
  openWeapons();
  printf("\n");

  //randomizing where the real weapon is 
  //srand(time(NULL));
  whichWeapon = randomNumber(3);

  //randomizing the weapon choices for the user
  switch (whichWeapon) {
    case 1:
      weap1 = weapon;
      weap2 = randomNumber(7);
      weap3 = randomNumber(7);
      detectiveWeaponOne=weap2;
      detectiveWeaponTwo=weap3;
      break;
    case 2:
      weap2 = weapon;
      weap1 = randomNumber(7);
      weap3 = randomNumber(7);
      detectiveWeaponOne=weap1;
      detectiveWeaponTwo=weap3;
      break;
    case 3:
      weap3 = weapon;
      weap2 = randomNumber(7);
      weap1 = randomNumber(7);
      detectiveWeaponOne=weap2;
      detectiveWeaponTwo=weap1;
      break;
  }

  //The weapons randomized above are the choices for the weapon
  printf("\nYou are now in the room where the murder happened. You notice three weapons, all have some from of blood on them.");
  printf("\nThe weapons you see are %d, %d, and %d", weap1, weap2, weap3);

  //prompting the user to invesitgate the weapons
  printf("\nWhich one would you like to invesitgate first? (please type an integer): ");
  inputCheck=scanf("%d", &userInput);

  //error checking
  while ((inputCheck !=1) || ((userInput != weap1) && (userInput != weap2) && (userInput != weap3))){
    printf("Bad input, try again.\nWhich one would you like to invesitgate first? ");
    inputCheck=scanf("%d", &userInput);
  }
  //testing to see if their input is the correct weapon
  testWeap(userInput, weap1, weap2, weapon);
  
  //do they want to keep investigating
  printf("\nWould you like to keep invesitgating? (1 for yes, 2 for no): ");
  scanf("%d", &userInput);
  //Error check
  errorCheckTest = errorCheck(userInput, 2, "\nWould you like to keep invesitgating? (1 for yes, 2 for no): ");
  userInput = errorCheckTest.userInput;
      
      

  //If the user wants to continue to investgate it send them here
  while (userInput == 1) {
    //prompting the user to invesitgate the weapons
    printf("\nWhich one would you like to invesitgate next? (please type an integer): ");
    inputCheck=scanf("%d", &userInput);
    //error checking
    while ((inputCheck !=1) || ((userInput != weap1) && (userInput != weap2) && (userInput != weap3))){
      printf("Bad input, try again.\nWhich one would you like to invesitgate first? ");
      inputCheck=scanf("%d", &userInput);
    }
    //testing to see if their input is the correct weapon
    testWeap(userInput, weap1, weap2, weapon);
    printf("\nWould you like to keep invesitgating? (1 for yes, 2 for no): ");
    scanf("%d", &userInput);

    //Error check
    errorCheckTest = errorCheck(userInput, 2, "\nWould you like to keep investigating? (1 for yes, 2 for no): ");
    userInput = errorCheckTest.userInput;
  }

  //This is where the user will guess what was used in the murder
  printf("\nWhat was used to kill them: (please enter an integrer): ");
  inputCheck=scanf("%d", &Guess.weapon);

  //advanced error checking, if the input is not valid in the scanf or the input does not match the weapon values, loop
  while ((inputCheck !=1) || ((Guess.weapon != weap1) && (Guess.weapon != weap2) && (Guess.weapon != weap3))){
    printf("\nWhat was used to kill them: (please enter an integrer): ");
    inputCheck=scanf("%d", &Guess.weapon);
  }

  //correctGuess is the variable that returns whether the guess was correct or not
  correctGuess = userGuessCheck(Guess.weapon, weapon);

  //changing the conditions of userInput so that the loop can work
  userInput=1;

  //If the guess is incorrect this code reprompts
  while ((correctGuess == 1) && (userInput==1)){ 
    printf("\nWould you like to try again? (1 for yes, 2 for no): ");
    scanf("%d", &userInput);
    //Error check
    errorCheckTest = errorCheck(userInput, 2, "\nWould you like to try again? (1 for yes, 2 for no): ");
    userInput = errorCheckTest.userInput;

    if (userInput == 1) {
      printf("\n\nWhat was used to kill them: (please enter an integer): ");
      scanf("%d", &Guess.weapon);

      //advanced error checking, if the input is not valid in the scanf or the input does not match the weapon values, loop
      while ((inputCheck !=1) || ((Guess.weapon != weap1) && (Guess.weapon != weap2) && (Guess.weapon != weap3))){
        printf("\nWhat was used to kill them: (please enter an integer): ");
        inputCheck=scanf("%d", &Guess.weapon);
      }
      //testing against the correct guess to see if the user has guessed the weapon correctly
      correctGuess = userGuessCheck(Guess.weapon, weapon);
    }
  }

  //BEGINNING SUSPECT INVESTIGATION
  //Opens the list of suspects
  printf("\n");
  openSuspects();
  printf("\n");

  //Prompting the user to invesitage the suspects
  printf("\nCHOOSE WHO YOU'D LIKE TO INVESITGATE (please enter a number): ");
  scanf("%d", &userInput);
  //Error checking
  errorCheckTest = errorCheck(userInput, 7, "\nCHOOSE WHO YOU'D LIKE TO INVESITGATE (please enter a number): ");
  userInput = errorCheckTest.userInput;

  //investigating the innocentsArrayson given the user's input, giving clues for each innocentsArrayson
  investigate(userInput, murderer, innocentsArray);

  printf("\nWould you like to keep invesitgating? (1 for yes, 2 for no): ");
  scanf("%d", &userInput);

  //Error checking
  errorCheckTest = errorCheck(userInput, 2, "\nWould you like to keep invesitgating? (1 for yes, 2 for no): ");
  userInput = errorCheckTest.userInput;

  //If the user wants to continue to investgate it send them here
  while (userInput == 1) {
    printf("\nCHOOSE WHO YOU'D LIKE TO INVESITGATE (please enter a number): ");
    scanf("%d", &userInput);

    //Error checking
    errorCheckTest = errorCheck(userInput, 7, "\nCHOOSE WHO YOU'D LIKE TO INVESITGATE (please enter a number): ");
    userInput = errorCheckTest.userInput;

    investigate(userInput, murderer, innocentsArray);
    //allowing them to break from the while loop
    printf("\nWould you like to keep invesitgating? (1 for yes, 2 for no): ");
    scanf("%d", &userInput);

    //Error checking
    errorCheckTest = errorCheck(userInput, 2, "\nWould you like to keep invesitgating? (1 for yes, 2 for no): ");
    userInput = errorCheckTest.userInput;
  }
  //Guess who is the murderer
  printf("\n\nWho is the murderer: (please enter an integer)");
  scanf("%d", &Guess.murderer);

  //Error checking
  errorCheckTest = errorCheck(Guess.murderer, 7, "\n\nWho is the murderer: (please enter an integer)");
  Guess.murderer = errorCheckTest.userInput;

  //testing their guess against the correct value
  correctGuess = userGuessCheck(Guess.murderer, murderer);

  //correctGuess is the variable that returns whether the guess was correct or not
  //If the guess is incorrect this code reprompts them
  if (correctGuess == 1) {
    printf("\nWould you like to try again? (1 for yes, 2 for no): ");
    scanf("%d", &userInput);

    //Error check
    errorCheckTest = errorCheck(userInput, 2, "\nWould you like to try again? (1 for yes, 2 for no): ");
    userInput = errorCheckTest.userInput;
    while (userInput == 1) {
      printf("\n\nWho is the murderer: (please enter an integer) ");
      scanf("%d", &Guess.murderer);

      //Error checking
      errorCheckTest = errorCheck(Guess.murderer, 7, "\n\nWho is the murderer: (please enter an integer) ");
      Guess.murderer = errorCheckTest.userInput;

      //checking their guess against the proper value      
      correctGuess = userGuessCheck(Guess.murderer, murderer);

      if (correctGuess == 1) {
        userInput = 0;
      } 
      else {
        printf("\nWould you like to try again? (1 for yes, 2 for no): ");
        scanf("%d", &userInput);
        //Error check
        errorCheckTest = errorCheck(userInput, 2, "\nWould you like to try again? (1 for yes, 2 for no): ");
        userInput = errorCheckTest.userInput;
      }
    }
  }
  
  //using the findMurdererName function to find their name as a string
  findMurdererName(murderer, murdererString);
  //using the findWeaponName function to find its name as a string
  findWeaponName(weapon, weaponString);
  //using the findRoomName function to find its name as a string
  findRoomName(room, roomString);

  //Displaying statements that lay out the murderer and segway into the fight sequence
  printf("The Detective: The Murderer is %s!\n", murdererString);

  printf("%s: You'll never catch me alive!\n", murdererString);
  printf("%s grabs the %s and runs into the %s, you chase after them.\n", murdererString, weaponString, roomString);
  printf("As soon as you walk through the door, %s turns and faces you with murderous intent. \n", murdererString);
  printf("You have to stand your ground before they get everyone else. \n\nIncapacitate them before they can take you down, prepare to fight!\n");

  //giving them the option to read more rules just in case
  printf("\nDo you want more rules? (1 for yes, 2 for no) ");
  scanf("%d", &userInput);
  //errorchecking
  errorCheckTest = errorCheck(userInput, 2, "\nDo you want more rules? (1 for yes, 2 for no) ");
  if (errorCheckTest.userInput == 1){
      //if they say yes, display the rules, otherwise continue running the file
      openFightRulesFile();
  }
  

  //displaying their available weapons
  printf("\nThe Detective's available weapons: %d, %d\n", detectiveWeaponOne, detectiveWeaponTwo);
  printf("What will you choose? ");
  scanf("%d", &detectiveWeapon);

  //error checking
  while ((detectiveWeapon != detectiveWeaponOne) && (detectiveWeapon != detectiveWeaponTwo)){
    printf("\n\n Error, input is out of bounds. \n\n");
    printf("\nThe Detective's available weapons: %d, %d\n", weap2, weap3);
    printf("What will you choose? ");
    scanf("%d",&detectiveWeapon);
  }

  findWeaponName(detectiveWeapon, detectiveWeaponString);
    
  printf("The Detective will wield the %s \n", detectiveWeaponString);
  //Single Player or Multiplayer
  printf("One or Two Players? (1 for Single Player, 2 for Multiplayer) ");
  scanf("%d", &numPlayers);
  errorCheckTest = errorCheck(numPlayers, 2, "One or Two Players? (1 for Single Player, 2 for Multiplayer) ");

  if (errorCheckTest.userInput == 2){
    multiPlayerFightSequence(detectiveWeapon, weapon);
  }
  else if (errorCheckTest.userInput == 1){
    singlePlayerFightSequence(detectiveWeapon, weapon);
  }
  else 
    printf("ERROR, NO INPUT SELECTED");
  
  //freeing all dynamically allocated memory
  free(murdererString);
  free(weaponString);
  free(detectiveWeaponString);
  free(roomString);
  return 0;
}   
