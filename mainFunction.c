//importing libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

//inserting headerfiles
 //#include "userGuessCheck.h"
//#include "randomNumber.h"

//defining a structure which contains the user's guess for the murderer, weapon, and room
typedef struct guesses {
  int murderer;
  int weapon;
  int room;
} userGuess;

//defining a structure which contains the user's inputs for usage in the errorCheck function
typedef struct inputs {
    int errorCheck;
    int userInput;
} Input;

//defining a structure which takes into account location and success of the attack
typedef struct combatInputs{
		int target;
		int success;
} Sequence;

//opens a .txt file for reading which contains extra information for the user's convienence
void openExtraInfo() {
  //creating a string variable which is capable of housing an incredibly large number of characters
  char str[2000000];
  int x;

  FILE* f1 = fopen("extrainfo.txt", "r");
  if (f1==NULL){
    printf("ERROR opening file\n");
    return;
  }
  //prints 32 lines from the txt file
  for (x = 0; x < 32; x++) {
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
  if (f1==NULL){
    printf("ERROR opening file\n");
    return;
  }
  //prints 8 lines from the txt file
  for (x = 0; x < 8; x++) {
    fgets(str, 2000000, f1);
    printf("%s", str);
  }
  fclose(f1);
}
//opens a .txt file for reading which contains the rules for the fight sequence
void openFightRulesFile() {
    //creating a string variable which is capable of housing an incredibly large number of characters
  char str[2000000];
  int x;

  FILE* f1 = fopen("fightRules.txt", "r");
  if (f1==NULL){
    printf("ERROR opening file\n");
    return;
  }
  //prints 30 lines from the txt file
  for (x = 0; x < 30; x++) {
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
  if (f1==NULL){
    printf("ERROR opening file\n");
    return;
  }
  //prints 8 lines from the txt file
  for (x = 0; x < 8; x++) {
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
  if (f1==NULL){
    printf("ERROR opening file\n");
    return;
  }
  //prints 8 lines from the txt file
  for (x = 0; x < 8; x++) {
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
  FILE* f1 = fopen("storyLine.txt", "r");
  if (f1==NULL){
    printf("ERROR opening file\n");
    return;
  }
  //returns as many lines as inputted
  for (x = y; x < z; x++) {
    fgets(str, 2000000, f1);
    printf("%s", str);
  }
  fclose(f1);
}

//Ammending the text file, to show the correct and incorrect guesses
int userGuessCheck(int guess, int real) {
  //opening the file for appending
  FILE* ptr = fopen("records.txt", "a");
  if (ptr==NULL){
    printf("ERROR opening file\n");
    return 2;
}
  //print the guess in the records.txt file and to the screen
  if (guess == real) {
    fprintf(ptr, "Correct: %d\n", guess);
    printf("Your guess %d is correct. \n", guess);
    return 0;
  } 
  else {
    fprintf(ptr, "Incorrect: %d\n", guess);
    printf("%d is incorrect.\n", guess);
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


/*creating a function which will take in the user's inputs, a range that the input cannot be greater than, 
and an error statement unique for each function. This contains a while loop which repeats the error statement as well as prompts the user
until they give a valid input. It accomplishes this by using recursion and has the function return a value of 1 for the "errorCheck" value
within the structure. This sets the user into the while loop, after prompting the user, the user's input is put into the "input" value within
the structure. If there is no error, which can be accomplished in the first input or after running through the while looop multiple times,
set the structure "errorCheck" to have a value of 0 for "errorCheck" and set the value of "input" to "userInput". This function is very thorough
in its error checking.
*/
Input errorCheck(int userInput, int range, char errorStatement[100]){

  Input errorCheckTest;
  char line[100];        
  if ((userInput > range) || (userInput < 1)){
    printf("\n\nInput is out of bounds, please try again. \n\n");
    errorCheckTest.errorCheck=1;
    while (errorCheckTest.errorCheck ==1){
      printf("%s", errorStatement);
      fgets(line,100,stdin);
      errorCheckTest.userInput=atoi(line);
      errorCheckTest=errorCheck(errorCheckTest.userInput, range, errorStatement);
    }
  }
  else{
    errorCheckTest.errorCheck=0;
    errorCheckTest.userInput=userInput;
  }
  return errorCheckTest;
}

/*
function which takes in the input of the roomsExplored array as well as the input of the room
with the purpose of discovering if the user has been in the room already
*/
bool beenInRoomCheck(int room, int* roomsExplored, int* numberOfRooms){
  //loop counter
  int loopCounter;
  bool check;
  if (numberOfRooms==NULL){
    check=false;
  }
  else{
    for (loopCounter=0; loopCounter<=*numberOfRooms; loopCounter++){
      if (roomsExplored[loopCounter]==room){
        check=true;
        printf("Check is %d", check);
      }
      else{
        check=false;
        printf("Check is %d", check);
      }
    }
  }
  return check;
}

/*function which scans the room the user is "in" and compares it to the room of the murder, giving specific clues based on the case
certain rooms link to each other via a secret passage and the user can choose to enter other rooms via the passageways, these intracies help
the murder feel like a mystery which must be solved rather than one based soley on randomization
*/

int explore(int room, int roomreal, int* roomsExploredStored, int* roomsExplored) {
  //structure to check input and error
  Input exploreCheck;
  //boolean to check if conditions are true or false for if the user has been in a given room
  bool beenInRoom;
  
  switch (room) {
  case 1:
    //finding if the user has been to the room which the secret passage connects to
    beenInRoom=beenInRoomCheck(3, roomsExploredStored, roomsExplored);
    //standard print statement
    printf("\nYou explore the Kitchen.\n");

    //custom print statements situationally

    //if they haven't been in the library and it is the room of the murder, printf statements accordingly
    if ((beenInRoom==false) && (roomreal==room)){
      printf("\nThere is blood splattered on the cupboards.\nAdditionally, you notice a cupboard is out of place.\n");
    }
    //if they have been in the library and the room is not the same as the room of the murder, printf accordingly
    else if ((beenInRoom==true) && (roomreal!=room)){
      printf("You find nothing out of the ordinary except the hidden passage to the Library. \n");
    }
    //if they have been in the library and the room is the same as the room of the murder, printf accordingly
    else if ((beenInRoom==true) && (roomreal == room)) {
      printf("\nThere is blood splattered on the cupboards.\nThe hidden passage to the Library is the only other noteworthy thing here\n");
    }
    //if they havent been in the library and it isnt the room of the murder, printf accordingly
    else if ((beenInRoom==false) && (roomreal != room)) {
      printf("One of the cupboards is out of place.\n");
    }
    printf("\nWould you like to investigate? (1 for yes, 2 for no): ");
    scanf("%d", & exploreCheck.userInput);
    
    //Error checking
    exploreCheck = errorCheck(exploreCheck.userInput, 2, "\nWould you like to investigate? (1 for yes, 2 for no): ");

    //Secret Passage
    if (exploreCheck.userInput == 1) {
      printf("\nYou notice that there is a passage that can take you to one of the other rooms.");
      printf("\nWould you like to take it? (1 for yes, 2 for no): ");
      scanf("%d", & exploreCheck.userInput);
      //error checking
      exploreCheck = errorCheck(exploreCheck.userInput, 2, "\nWould you like to take it? (1 for yes, 2 for no): ");
      if (exploreCheck.userInput == 1){
        roomsExploredStored[*roomsExplored]=1;
        *roomsExplored++;
        explore(3, roomreal, roomsExploredStored, roomsExplored);
      }
    }
    roomsExploredStored[*roomsExplored]=1;
    *roomsExplored++;
    break;

  case 2:
    printf("\nYou explore the Lounge.");
    if (roomreal == room) {

      printf("\nThere is dried blood on one of the couches.\n");
    }
    else {
      printf("\nYou find nothing of significance. \n");
    }
    *roomsExplored++;
    break;

  case 3:
    beenInRoom=beenInRoomCheck(1, roomsExploredStored, roomsExplored);
    printf("\nYou explore the Library.\n");
    if ((beenInRoom==false) && (roomreal==room)){
      printf("\nThere seems to be some typ1e of blood on one of the books.\nAdditionally, you notice that there is a bookshelf slightly shifted.\n");
    }
    else if ((beenInRoom==true) && (roomreal!=room)){
      printf("You find nothing out of the ordinary except the hidden passage to the Kitchen. \n");
    }
    else if ((beenInRoom==true) && (roomreal == room)) {
      printf("\nYou find that there seems to be some type of blood on one of the books.\nThe hidden passage to the Kitchen is the only other noteworthy thing here\n");
    }
    else if ((beenInRoom==false) && (roomreal != room)) {
      printf("One of the bookshelfs looks like it has been moved recently.\n");
    }
    printf("\nWould you like to investigate it? (1 for yes, 2 for no): ");
    scanf("%d", &exploreCheck.userInput);
    //Error checking
    exploreCheck= errorCheck(exploreCheck.userInput, 2, "\nWould you like to investigate it? (1 for yes, 2 for no): ");

    if (exploreCheck.userInput == 1) {
      printf("\nYou notice that there is a passage that can take you to one of the other rooms.");
      printf("\nWould you like to take it? (1 for yes, 2 for no): ");
      scanf("%d", &exploreCheck.userInput);
      //Error checking
      exploreCheck = errorCheck(exploreCheck.userInput, 2, "\nWould you like to take it? (1 for yes, 2 for no): ");
      if (exploreCheck.userInput == 1){
        roomsExploredStored[*roomsExplored]=3;
        *roomsExplored++;
        explore(1, roomreal, roomsExploredStored, roomsExplored);
      }
    }
    roomsExploredStored[*roomsExplored]=3;
    *roomsExplored++;
    break;

  case 4:
    printf("\nYou explore the Ball Room.\n");
    if (roomreal == room) {
      printf("\nThere is smeared blood on the flooring.");
    }
    else {
      printf("\nThere's nothing of note except the unfinished drinks, and the smell of cigarettes.");
    }
    *roomsExplored++;
    break;

  case 5:
    printf("\nYou explore the Biliard Room.\n");
    beenInRoom=beenInRoomCheck(7, roomsExploredStored, roomsExplored);
    //if they haven't been in the Dining Room and it is the room of the murder, printf statements accordingly
    if ((beenInRoom==false) && (roomreal==room)){
      printf("\nOne of the pool cues seems to be broken. innocentsArrayhaps someone tried to use it to fend the Murderer off.\nAdditionally, you notice a lift in the carpet.\n");
    }
    //if they have been in the Dining Room and the room is not the same as the room of the murder, printf accordingly
    else if ((beenInRoom==true) && (roomreal!=room)){
      printf("You find nothing out of the ordinary except the hidden passage to the Dining Room. \n");
    }
    //if they have been in the Dining Room and the room is the same as the room of the murder, printf accordingly
    else if ((beenInRoom==true) && (roomreal == room)) {
      printf("\nOne of the pool cues seems to be broken. innocentsArrayhaps someone tried to use it to fend the Murderer off.\nThe hidden passage to the Dining Room is the only other noteworthy thing here\n");
    }
    //if they havent been in the Dining Room and it isnt the room of the murder, printf accordingly
    else if ((beenInRoom==false) && (roomreal != room)) {
      printf("There's a lift in the carpet.\n");
    }
    printf("\nWould you like to investigate? (1 for yes, 2 for no): ");
    scanf("%d", &exploreCheck.userInput);
    //Error checking
    exploreCheck = errorCheck(exploreCheck.userInput, 2, "\nWould you like to take it? (1 for yes, 2 for no): ");

    if (exploreCheck.userInput == 1) {
      //prompting the user
      printf("\nYou notice that there is a passage that can take you to one of the other rooms.");
      printf("\nWould you like to take it? (1 for yes, 2 for no): ");
      scanf("%d", &exploreCheck.userInput);
      //error checking
      exploreCheck = errorCheck(exploreCheck.userInput, 2, "\nWould you like to take it? (1 for yes, 2 for no): ");
      if (exploreCheck.userInput == 1){
        roomsExploredStored[*roomsExplored]=5;
        *roomsExplored++;
        explore(7, roomreal, roomsExploredStored, roomsExplored);
      }
    }
    roomsExploredStored[*roomsExplored]=5;
    *roomsExplored++;
    break;

  case 6:
    printf("\nYou explore the Conservatory.\n");
    if (roomreal == room) {
      printf("\nYou notice some smudged blood on one of the windows.");
    }
    else {
      printf("\nIt seems like a nice spot to clear your head.");
    }
    *roomsExplored++;
    break;

  case 7:
    printf("\nYou explore the Dining Room.\n");
    beenInRoom=beenInRoomCheck(5, roomsExploredStored, roomsExplored);
    //if they haven't been in the Biliard Room and it is the room of the murder, printf statements accordingly
    if ((beenInRoom==false) && (roomreal==room)){
      printf("\nThere is blood on the corner of the table. Someone tried to cover it up with the tablecloth.\nAdditionally, you notice an off-colored wooden board underneath the table.\n");
    }
    //if they have been in the Biliard Room and the room is not the same as the room of the murder, printf accordingly
    else if ((beenInRoom==true) && (roomreal!=room)){
      printf("You find nothing out of the ordinary except the hidden passage to the Biliard Room. \n");
    }
    //if they have been in the Biliard Room and the room is the same as the room of the murder, printf accordingly
    else if ((beenInRoom==true) && (roomreal == room)) {
      printf("\nhere is blood on the corner of the table. Someone tried to cover it up with the tablecloth.\nThe hidden passage to the Biliard Room is the only other noteworthy thing here\n");
    }
    //if they havent been in the Biliard Room and it isnt the room of the murder, printf accordingly
    else if ((beenInRoom==false) && (roomreal != room)) {
      printf("You notice an off-colored wooden board underneath the table.\n");
    }

    printf("\nWould you like to investigate? (1 for yes, 2 for no): ");
    scanf("%d", &exploreCheck.userInput);
    //Error checking
    exploreCheck = errorCheck(exploreCheck.userInput, 2, "\nWould you like to take it? (1 for yes, 2 for no): ");
    
    if (exploreCheck.userInput == 1) {
      printf("\nYou notice that there is a passage that can take you to one of the other rooms.");
      printf("\nWould you like to take it? (1 for yes, 2 for no): ");    
      scanf("%d", &exploreCheck.userInput);
      
      //Error checking
      exploreCheck = errorCheck(exploreCheck.userInput, 2, "\nWould you like to take it? (1 for yes, 2 for no): ");
      if (exploreCheck.userInput == 1){
        roomsExploredStored[*roomsExplored]=7;
        *roomsExplored++;
        explore(5, roomreal, roomsExploredStored, roomsExplored);
      }
    }
    printf("Not investigating. \n");
    roomsExploredStored[*roomsExplored]=7;
    *roomsExplored++;
    break;

  default:
    printf("\nERROR");
    break;
  }
}

//clue function for weapons, these clues do not help the user to guess as all are randomized
void testWeap(int input, int fakeWeaponOne, int fakeWeaponTwo, int realWeapon) {
  if (input == fakeWeaponOne)
    printf("\nThe blood appears to be splattered on, someone is trying to make this more difficult for me.");
  else if (input == fakeWeaponTwo)
    printf("\nThis blood looks too fresh for how long ago the murder was. ");
  else if (input == realWeapon)
    printf("\nThere seems to be the remnants of finger prints on this one, someone may have tried to clean them off.");
}

void investigate(int person, int murderer, int* innocentsArray) {
  openSuspects();
  switch (person) {
  case 1:
  if (person==murderer){
    printf("\nI was in the kitchen with %d the entire time.", innocentsArray[0]);
    break;
  }
  else
    printf("\nI was busy preparing dessert in the kitchen, %d came into the room around the time I was finished", murderer);
    break;
  case 2:
  if (person==murderer){
    printf("\nI was in the kitchen with %d the entire time.", innocentsArray[0]);
    break;
  }
  else
    printf("\nI saw Mr. Peters go into the ballroom with %d earlier that night, then %d and I talked in the Dining Room", innocentsArray[2], innocentsArray[4]);
    break;
  case 3:
  if (person==murderer){
    printf("\nI was in the kitchen with %d the entire time.", innocentsArray[0]);
    break;
  }
  else
    printf("\nMr. Peters and I were in the ballroom dancing but then they left into the Conservatory");
    break;
  case 4:
  if (person==murderer){
    printf("\nI was in the kitchen with %d the entire time.", innocentsArray[0]);
    break;
  }
  else
    printf("\nI saw %d go into the Conservatory, but I never saw them leave", innocentsArray[6]);
    break; 
  case 5:
  if (person==murderer){
    printf("\nI was in the kitchen with %d the entire time.", innocentsArray[0]);
    break;
  }
  else
    printf("\n%d and I were talking in the Dining Room half the night talking about the affair between Mr. Peters and %d, we cant believe that they could do this to %d!", innocentsArray[1], innocentsArray[2], murderer);
    break;
  case 6:
  if (person==murderer){
    printf("\nI was in the kitchen with %d the entire time.", innocentsArray[0]);
    break;
  }
  else
    printf("%d, myself, and %d were in the Biliard Room playing pool, %d said they were going to go use the bathroom but they were gone for a very long time.\n", innocentsArray[6], murderer, murderer);
    break;
  case 7:
  if (person==murderer){
    printf("\nI was in the kitchen with %d the entire time.", innocentsArray[0]);
    break;
  }
  else
    printf("I think it was %d, just a gut feeling.\n", murderer);
    break;
  }
}

/*function which grabs the integer value of the murderer and runs through the .txt file of murder suspects to match the integer to the line
of the file, then it grabs that line as a string of characters and returns the string
*/
void findMurdererName(int murdererNumber, char* murdererName){
  int loopCounter, lengthLine, lengthMurdererName, numberOfSpacesInString=0;
  FILE* f1=fopen("suspects.txt","r");
  if (f1==NULL){
    printf("ERROR opening file\n");
  }
  char line[100];
 //loop which moves through lines of the file until it reaches the line that contains the murderer's name
  for (loopCounter=1; loopCounter<=murdererNumber+1; loopCounter++){
    fgets(line,100,f1);
    if (loopCounter==murdererNumber+1){
      strcpy(murdererName,line);
    }
  }
  //setting line equal to murdererName for usage in the below loop
  strcpy(line, murdererName);
  lengthLine=strlen(line);
  //another loop which will erase the first 4 characters from the string, this is so that the name does not include something like "2.) "
  for (loopCounter = 0; loopCounter<lengthLine; loopCounter++){
    murdererName[loopCounter] = line[loopCounter+4];
  }
  /*
  finding length of murdererName so that we can begin to reallocate memory to eliminate any white spaces
  after the string thus freeing up unnecessary memory
  */
  lengthMurdererName=strlen(murdererName);
  for (loopCounter =0; loopCounter<lengthMurdererName; loopCounter++){
    //running through the for loop until it reaches a space in the string
    if (isspace(murdererName[loopCounter])){
      /*
      Upon finding a space, we will reallocate the amount of memory used by the string, shortening the
      array of characters
      */
      numberOfSpacesInString++;
      //after reading in two spaces, place the null character
      if (numberOfSpacesInString == 2){
        murdererName[loopCounter]='\0';
        murdererName=realloc(murdererName, (loopCounter)*sizeof(char));
      }
    }
  }
}

void findWeaponName(int weaponNumber, char* weaponName){
  int loopCounter, lengthLine, lengthWeaponName, numberOfSpacesInString=0;
  FILE* f1=fopen("weapons.txt","r");
  if (f1==NULL){
    printf("ERROR opening file\n");
  }
  char line[100];
 //loop which moves through lines of the file until it reaches the line that contains the weapon name
  for (loopCounter=1; loopCounter<=weaponNumber+1; loopCounter++){
    fgets(line,100,f1);
    if (loopCounter==weaponNumber+1){
      strcpy(weaponName,line);
    }
  }
  //setting line equal to weaponName for usage in the below loop
  strcpy(line, weaponName);
  lengthLine=strlen(line);
  //another loop which will erase the first 4 characters from the string, this is so that the name does not include something like "2.) "
  for (loopCounter = 0; loopCounter<lengthLine; loopCounter++){
    weaponName[loopCounter] = line[loopCounter+4];
  }
  /*
  finding length of weaponName so that we can begin to reallocate memory to eliminate any white spaces
  after the string thus freeing up unnecessary memory
  */
  lengthWeaponName=strlen(weaponName);
  for (loopCounter =0; loopCounter<lengthWeaponName; loopCounter++){
    //running through the for loop until it reaches a space in the string
    if (isspace(weaponName[loopCounter])){
      /*
      Upon finding a space, we will reallocate the amount of memory used by the string, shortening the
      array of characters
      */
      numberOfSpacesInString++;
      //after reading in two spaces, place the null character
      if (numberOfSpacesInString == 2){
        weaponName[loopCounter]='\0';
        weaponName=realloc(weaponName, (loopCounter)*sizeof(char));
      }
    }
  }
}

void findRoomName(int roomNumber, char* roomName){
  int loopCounter, lengthLine, lengthRoomName, numberOfSpacesInString=0;
  FILE* f1=fopen("rooms.txt","r");
  if (f1==NULL){
    printf("ERROR opening file\n");
  }
  char line[100];
 //loop which moves through lines of the file until it reaches the line that contains the room name
  for (loopCounter=1; loopCounter<=roomNumber+1; loopCounter++){
    fgets(line,100,f1);
    if (loopCounter==roomNumber+1){
      strcpy(roomName,line);
    }
  }
  //setting line equal to weaponName for usage in the below loop
  strcpy(line, roomName);
  lengthLine=strlen(line);
  //another loop which will erase the first 4 characters from the string, this is so that the name does not include something like "2.) "
  for (loopCounter = 0; loopCounter<lengthLine; loopCounter++){
    roomName[loopCounter] = line[loopCounter+4];
  }
  /*
  finding length of roomName so that we can begin to reallocate memory to eliminate any white spaces
  after the string thus freeing up unnecessary memory
  */
  lengthRoomName=strlen(roomName);
  for (loopCounter =0; loopCounter<lengthRoomName; loopCounter++){
    //running through the for loop until it reaches a space in the string
    if (isspace(roomName[loopCounter])){
      /*
      Upon finding a space, we will reallocate the amount of memory used by the string, shortening the
      array of characters
      */
      numberOfSpacesInString++;
      //after reading in two spaces, place the null character
      if (numberOfSpacesInString == 2){
        roomName[loopCounter]='\0';
        roomName=realloc(roomName, (loopCounter)*sizeof(char));
      }
    }
  }
}

//Beginning combat functions

int criticalHitFunction(int target){
/*rolls randomly between 1-10 to find critical hits, varies based on position of attack,
the higher the attack the higher the critical strike chance. Function does not seed time as we seed time in main.
*/
  int roll, critical;
  roll=rand()%11;
  if ((target==3) && (roll <= 6))
    critical=1;
  else if ((target==2) && (roll <= 4))
    critical=1;
  else if ((target ==1) && (roll <=2))
    critical=1;
  else
    critical=0;
  return critical;
}
//hard coding the damage for weapons based on .txt file which states them. Doubling damage if it is a critical strike.
float damageFunction(int weapon, int critical){
	float weaponDamage;
    if (weapon ==1)
		weaponDamage=3;
	else if ((weapon ==2) || (weapon ==7))
		weaponDamage=4;
	else if ((weapon ==3) || (weapon ==5))
		weaponDamage=1;
	else if ((weapon ==4) || (weapon ==6))
		weaponDamage = 2;
    if (critical ==1)
        weaponDamage=weaponDamage*2;
	return weaponDamage;
}
int AItargetFunction(){
//rolls randomly to determine position of attack, it is more likely to attack higher positions due to the increased critical strike chance
  int roll, target;
  roll=rand()%13;
  if (roll <= 2)
        target=1;
  else if (roll <= 6)
        target=2;
  else if (roll <=12)
        target=3;
  return target;
}

//function which takes into account the AI's random input and prompts the user to input themselves based on if the player is blocking or attacking
Sequence AICombatFunction(int playerTurn){
  Sequence computerAttack, userAttack, computerBlock, userBlock;
  Input errorCheckTest;
  //when the AI is attacking, the player must block their attack
  if (playerTurn == 2){
    printf("The Murderer is calculating their attack... \n");
	  //calling the AI target function to determine position
    computerAttack.target=AItargetFunction();

	  printf("Player One, press 1, 2, or 3 to block their attack: ");
	  scanf("%d", &userBlock.target);
        
    //error checking
    errorCheckTest=errorCheck(userBlock.target, 3, "Please try again, press 1, 2, or 3 to block Player %d's attack: ");
    userBlock.target=errorCheckTest.userInput;
    
    //if the position of the block and the attack is the same, the attack will not succeed
	  if (computerAttack.target == userBlock.target)
	    computerAttack.success = 0;
	  else
		  computerAttack.success = 1;
	  return computerAttack;
  }
  
  else if (playerTurn == 1){
    //when the player is attacking, the AI must block their attack
    printf("Player One you are attacking now, press 1, 2, or 3 to attack: ");
	  scanf("%d", &userAttack.target);
        
    //error checking
    errorCheckTest=errorCheck(userAttack.target, 3, "Please try again, press 1, 2, or 3 to attack: ");
    userAttack.target=errorCheckTest.userInput;

    printf("The Murderer is calculating where to block... \n");
    //calling the AI target function to determine positiopn
    computerBlock.target=AItargetFunction();
        
    //if the position of the block and the attack is the same, the attack will not succeed
    if (userAttack.target == computerBlock.target)
      userAttack.success = 0;
    else
      userAttack.success = 1;
	    return userAttack;
  }
}
//calling combatFunction that accomplishes the same thing as "AICombatFunction" but is instead for multi-player
Sequence combatFunction(int attackingPlayerNumber, int blockingPlayerNumber){
  //initializing variables
	Sequence attack, block;
  Input errorCheckTest;

  //print statements which prompt the attacking user to attack
	printf("Player %d you are attacking now, press 1, 2, or 3 to attack: ", attackingPlayerNumber);
	scanf("%d", &attack.target);
    
  //error checking
  errorCheckTest=errorCheck(attack.target, 3, "Please try again, press 1, 2, or 3 to attack: ");
  attack.target=errorCheckTest.userInput;
  
  //print statements prompting the blocking user to block
	printf("Player %d, press 1, 2, or 3 to block their attack: ", blockingPlayerNumber);
	scanf("%d", &block.target);

  //error checking
  errorCheckTest=errorCheck(block.target, 3, "Please try again, press 1, 2, or 3 to block Player %d's attack: ");
  block.target=errorCheckTest.userInput;

  //if the position of the block and the attack is the same, the attack will not succeed
	if (attack.target == block.target)
		attack.success = 0;
	else
		attack.success = 1;
	return attack;
}        
        

//singleplayer fight sequence using "AI"
int singlePlayerFightSequence(int weaponOne, int weaponTwo){
  //beginning the fight
  printf("\n\n FIGHT \n\n");

  //initializing variables
  int playerNumber, critical, weaponNumber[2];
  float weaponDamage, healthPlayers[2]={10,10};

  weaponNumber[0]=weaponOne;
  weaponNumber[1]=weaponTwo;
  Sequence attack;
  
  playerNumber=1;

  //loop that continues running through the combat function until someone loses the fight
  while ((healthPlayers[0]>0) && (healthPlayers[1]>0)){ 
    //if Player One is attacking, remove health from the murderer
    if (playerNumber==1){
      attack=AICombatFunction(1);
      critical=criticalHitFunction(attack.target);
      weaponDamage=damageFunction(weaponNumber[0], critical);
		  
      /*if the attack is successful, deal full damage, if it is blocked deal half damage, if it is a critical strike deal double damage
      if a critical strike is blocked it will deal normal damage, i.e. 3 -> critical -> 6 -> block -> 3 
      */
      if ((attack.success==1) && (critical!=1)){
        printf("Successful Hit on the Murderer!\n");
        healthPlayers[1]=healthPlayers[1]-weaponDamage;
      }
      else if ((attack.success==1) && (critical==1)){
        printf("Critical Hit on the Murderer!\n");
        healthPlayers[1]=healthPlayers[1]-weaponDamage;
      }
      else if ((attack.success==0) && (critical==1)){
        printf("Critical Hit on the Murderer, though The Detective's attack was blocked, and dealt half the damage: %.1f \n", weaponDamage);
        healthPlayers[1]=healthPlayers[1]-(weaponDamage/2);
      }
      else{
        healthPlayers[1]=healthPlayers[1]-(weaponDamage/2);
	      printf("The Detective's attack was blocked, and dealt half the damage: %.1f \n", weaponDamage);
        
	    }
      //display the health of both people
      printf("\nThe Detective's health: %.1f\nThe Murderer's health: %.1f\n\n", healthPlayers[0], healthPlayers[1]);
      //give the turn to player two
      playerNumber+=1;
	  }
	  //repeat all processes above but for opposite players
    else if (playerNumber ==2){
		  attack=AICombatFunction(2);
		  critical=criticalHitFunction(attack.target);
      weaponDamage=damageFunction(weaponNumber[1], critical);
        
      if ((attack.success==1) && (critical!=1)){
        printf("Succesful Hit on the Detective!\n");
		    healthPlayers[0]=healthPlayers[0]-weaponDamage;
      }
      else if ((attack.success==1) && (critical==1)){
        printf("Critical Hit on the Detective!\n");
		    healthPlayers[0]=healthPlayers[0]-weaponDamage;
      }  
      else if ((attack.success==0) && (critical==1)){
        printf("Critical Hit on the Detective, though The Murderer's attack was blocked, and dealt half the damage: %.1f \n", weaponDamage/2);
        healthPlayers[0]=healthPlayers[0]-(weaponDamage/2);
      }
      else{
        healthPlayers[0]=healthPlayers[0]-(weaponDamage/2);
		    printf("The Murderer's attack was blocked, and dealt half the damage: %.1f \n", weaponDamage/2);
      }
      //display the health of both people
      printf("\nThe Detective's health: %.1f\nThe Murderer's health: %.1f\n\n", healthPlayers[0], healthPlayers[1]);
      //give the turn back to player one
      playerNumber-=1;
    }
  }
  //if the health of The Detective hits 0, The Murderer wins
  if (healthPlayers[0]<=0){
  printf("The Murderer wins.... \n\nGAME OVER\n\n");
  return 1;
  }
  //if the health of The Murderer hits 0, The Detective wins
  else if (healthPlayers[1]<=0){
    printf("The Detective wins, justice is served. \n\nGAME OVER\n\n");
    return 2;
  }
}

//Multiplayer fight sequence taking in inputs from two parties, identical to "singlePlayerFightSequence" except using non-AI functions.
int multiPlayerFightSequence(int weaponOne, int weaponTwo){
  //beginning the fight
  printf("\n\n FIGHT \n\n");

  int playerNumber=0, critical, weaponNumber[2];
  float weaponDamage, healthPlayers[2]={10,10};

  weaponNumber[0]=weaponOne;
  weaponNumber[1]=weaponTwo;
  Sequence attack;

  playerNumber=1;
    
  while ((healthPlayers[0]!=0) && (healthPlayers[1]!=0)){ 

	  if (playerNumber==1){
      attack=combatFunction(1,2);
	    critical=criticalHitFunction(attack.target);
      weaponDamage=damageFunction(weaponNumber[0], critical);
      if (attack.success==1){
        printf("Succesful Hit on the Murderer!\n");
		    healthPlayers[1]=healthPlayers[1]-weaponDamage;
		  }
      else if ((attack.success==0) && (critical==1)){
        printf("Critical Hit on the Murderer, though The Detective's attack was blocked, and dealt half the damage: %.1f \n", weaponDamage/2);
        healthPlayers[1]=healthPlayers[1]-(weaponDamage/2);
      }
      else if ((attack.success==1) && (critical==1)){
        printf("Critical Hit on the Murderer!\n");
		    healthPlayers[1]=healthPlayers[1]-weaponDamage;
      }
      else{
			  healthPlayers[1]=healthPlayers[1]-(weaponDamage/2);
			  printf("The Detective's attack was blocked, and dealt half the damage: %.1f\n", weaponDamage/2);
		  }
      //display the health of both people
      printf("\nThe Detective's health: %.1f\nThe Murderer's health: %.1f\n\n", healthPlayers[0], healthPlayers[1]);
      //give the turn to player two
      playerNumber+=1;
		}
	  else if (playerNumber ==2){
		  attack=combatFunction(2,1);
		  critical=criticalHitFunction(attack.target);
      weaponDamage=damageFunction(weaponNumber[1], critical);
        
      if (attack.success==1){
        printf("Succesful Hit on the Detective!\n");
		    healthPlayers[0]=healthPlayers[0]-weaponDamage;
      }
      else if ((attack.success==1) && (critical==1)){
        printf("Critical Hit on the Detective! \n");
		    healthPlayers[0]=healthPlayers[0]-weaponDamage;
      }  
      else if ((attack.success==0) && (critical==1)){
        printf("Critical Hit on the Detective, though The Murderer's attack was blocked, and dealt half the damage: %.1f \n", weaponDamage/2);
        healthPlayers[0]=healthPlayers[0]-(weaponDamage/2);
      }
      else{
        healthPlayers[0]=healthPlayers[0]-(weaponDamage/2);
		    printf("The Murderer's attack was blocked, and dealt half the damage: %.1f \n", weaponDamage/2);
      }
      //display the health of both people
      printf("\nThe Detective's health: %.1f\nThe Murderer's health: %.1f\n\n", healthPlayers[0], healthPlayers[1]);
      //gives the turn back to Player One
      playerNumber-=1;
    }
  }
  if (healthPlayers[0]==0){
    printf("The Murderer wins.... \n\nGAME OVER\n\n");
    return 1;
  }
  else if (healthPlayers[1]==0){
    printf("The Detective wins, justice is served. \n\nGAME OVER\n\n");
    return 2;
  }
}
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
  //Error checking, please delete before turning in
  printf("%d, %d, %d", murderer, weapon, room);

  //The start of searching for the room
  printf("\n");
  openRoom();
  printf("\n");

  //promting the user to find out what room they'd like to explore
  printf("\nWhat room would you like to explore? (please enter a number): ");
  fgets(line,100,stdin);
  userInput=atoi(line);
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
  printf("\nThe first one you notice is %d, then %d, then %d", weap1, weap2, weap3);

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