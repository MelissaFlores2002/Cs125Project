#include <stdio.h>
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
