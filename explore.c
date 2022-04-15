#include <stdio.h>

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
