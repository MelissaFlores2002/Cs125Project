#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//rolls randomly between 1-10 to find critical hits, varies based on position of attack, the higher the attack the higher the critical strike chance
int criticalHitFunction(int target){
  int roll, critical;
  srand(time( NULL() );
  roll=rand()%11;
  if ((target==3) && (roll <= 6))
        critical=1;
  if else ((target==2) && (roll <= 4))
        critical=1;
  if else ((target ==1) && (roll <=2))
        critical=1;
  else
        critical=0;
  return critical;
}
