#include <stdio.h>

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
