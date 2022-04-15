//Melissa Flores and Hunter Difabio
#include <stdio.h>

//Multiplayer fight sequence taking in inputs from two parties, identical to "singlePlayerFightSequence" except using non-AI functions.
int multiPlayerFightSequence(int weaponOne, int weaponTwo){
  //beginning the fight
  printf("\n\n FIGHT \n\n");

  int playerNumber=0, critical, weaponNumber[2];
  float weaponDamage, healthPlayers[2]={10,10};

  weaponNumber[0]=weaponOne;
  weaponNumber[1]=weaponTwo;
  Sequence attack;

  playerNumber=1;
    
  while ((healthPlayers[0]!=0) && (healthPlayers[1]!=0)){ 

	  if (playerNumber==1){
      attack=combatFunction(1,2);
	    critical=criticalHitFunction(attack.target);
      weaponDamage=damageFunction(weaponNumber[0], critical);
      if (attack.success==1){
        printf("Succesful Hit on the Murderer!\n");
		    healthPlayers[1]=healthPlayers[1]-weaponDamage;
		  }
      else if ((attack.success==0) && (critical==1)){
        printf("Critical Hit on the Murderer, though The Detective's attack was blocked, and dealt half the damage: %.1f \n", weaponDamage/2);
        healthPlayers[1]=healthPlayers[1]-(weaponDamage/2);
      }
      else if ((attack.success==1) && (critical==1)){
        printf("Critical Hit on the Murderer!\n");
		    healthPlayers[1]=healthPlayers[1]-weaponDamage;
      }
      else{
			  healthPlayers[1]=healthPlayers[1]-(weaponDamage/2);
			  printf("The Detective's attack was blocked, and dealt half the damage: %.1f\n", weaponDamage/2);
		  }
      //display the health of both people
      printf("\nThe Detective's health: %.1f\nThe Murderer's health: %.1f\n\n", healthPlayers[0], healthPlayers[1]);
      //give the turn to player two
      playerNumber+=1;
		}
	  else if (playerNumber ==2){
		  attack=combatFunction(2,1);
		  critical=criticalHitFunction(attack.target);
      weaponDamage=damageFunction(weaponNumber[1], critical);
        
      if (attack.success==1){
        printf("Succesful Hit on the Detective!\n");
		    healthPlayers[0]=healthPlayers[0]-weaponDamage;
      }
      else if ((attack.success==1) && (critical==1)){
        printf("Critical Hit on the Detective! \n");
		    healthPlayers[0]=healthPlayers[0]-weaponDamage;
      }  
      else if ((attack.success==0) && (critical==1)){
        printf("Critical Hit on the Detective, though The Murderer's attack was blocked, and dealt half the damage: %.1f \n", weaponDamage/2);
        healthPlayers[0]=healthPlayers[0]-(weaponDamage/2);
      }
      else{
        healthPlayers[0]=healthPlayers[0]-(weaponDamage/2);
		    printf("The Murderer's attack was blocked, and dealt half the damage: %.1f \n", weaponDamage/2);
      }
      //display the health of both people
      printf("\nThe Detective's health: %.1f\nThe Murderer's health: %.1f\n\n", healthPlayers[0], healthPlayers[1]);
      //gives the turn back to Player One
      playerNumber-=1;
    }
  }
  if (healthPlayers[0]==0){
    printf("The Murderer wins.... \n\nGAME OVER\n\n");
    return 1;
  }
  else if (healthPlayers[1]==0){
    printf("The Detective wins, justice is served. \n\nGAME OVER\n\n");
    return 2;
  }
}
