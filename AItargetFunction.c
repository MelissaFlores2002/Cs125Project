//Melissa Flores and Hunter Difabio
#include <stdio.h>

int AItargetFunction(){
//rolls randomly to determine position of attack, it is more likely to attack higher positions due to the increased critical strike chance
  int roll, target;
  roll=rand()%13;
  if (roll <= 2)
        target=1;
  else if (roll <= 6)
        target=2;
  else if (roll <=12)
        target=3;
  return target;
}
