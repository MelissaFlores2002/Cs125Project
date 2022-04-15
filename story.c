#include <stdio.h>

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
