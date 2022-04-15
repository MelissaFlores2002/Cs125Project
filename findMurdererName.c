#include <stdio.h>
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
