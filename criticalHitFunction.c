//Melissa Flores and Hunter Difabio
#include <stdio.h>
int criticalHitFunction(int target){
/*rolls randomly between 1-10 to find critical hits, varies based on position of attack,
the higher the attack the higher the critical strike chance. Function does not seed time as we seed time in main.
*/
  int roll, critical;
  roll=rand()%11;
  if ((target==3) && (roll <= 6))
    critical=1;
  else if ((target==2) && (roll <= 4))
    critical=1;
  else if ((target ==1) && (roll <=2))
    critical=1;
  else
    critical=0;
  return critical;
}
