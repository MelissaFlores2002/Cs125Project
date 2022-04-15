//Melissa Flores and Hunter Difabio
#include <stdio.h>
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
