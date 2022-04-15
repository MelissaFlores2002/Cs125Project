//Melissa Flores and Hunter Difabio
#include <stdio.h>

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
