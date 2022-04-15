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
