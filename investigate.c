//Melissa Flores and Hunter Difabio
#include <stdio.h>

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
