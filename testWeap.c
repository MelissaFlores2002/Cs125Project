//Melissa Flores and Hunter Difabio
#include <stdio.h>

//clue function for weapons, these clues do not help the user to guess as all are randomized
void testWeap(int input, int fakeWeaponOne, int fakeWeaponTwo, int realWeapon) {
  if (input == fakeWeaponOne)
    printf("\nThe blood appears to be splattered on, someone is trying to make this more difficult for me.");
  else if (input == fakeWeaponTwo)
    printf("\nThis blood looks too fresh for how long ago the murder was. ");
  else if (input == realWeapon)
    printf("\nThere seems to be the remnants of finger prints on this one, someone may have tried to clean them off.");
}
