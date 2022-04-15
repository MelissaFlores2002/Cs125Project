//Melissa Flores and Hunter Difabio
#include <stdio.h>

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
