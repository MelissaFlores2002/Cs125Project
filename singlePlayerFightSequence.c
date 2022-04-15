//Melissa Flores and Hunter Difabio
#include <stdio.h>

//singleplayer fight sequence using "AI"
int singlePlayerFightSequence(int weaponOne, int weaponTwo){
  //beginning the fight
  printf("\n\n FIGHT \n\n");

  //initializing variables
  int playerNumber, critical, weaponNumber[2];
  float weaponDamage, healthPlayers[2]={10,10};

  weaponNumber[0]=weaponOne;
  weaponNumber[1]=weaponTwo;
  Sequence attack;
  
  playerNumber=1;

  //loop that continues running through the combat function until someone loses the fight
  while ((healthPlayers[0]>0) && (healthPlayers[1]>0)){ 
    //if Player One is attacking, remove health from the murderer
    if (playerNumber==1){
      attack=AICombatFunction(1);
      critical=criticalHitFunction(attack.target);
      weaponDamage=damageFunction(weaponNumber[0], critical);
		  
      /*if the attack is successful, deal full damage, if it is blocked deal half damage, if it is a critical strike deal double damage
      if a critical strike is blocked it will deal normal damage, i.e. 3 -> critical -> 6 -> block -> 3 
      */
      if ((attack.success==1) && (critical!=1)){
        printf("Successful Hit on the Murderer!\n");
        healthPlayers[1]=healthPlayers[1]-weaponDamage;
      }
      else if ((attack.success==1) && (critical==1)){
        printf("Critical Hit on the Murderer!\n");
        healthPlayers[1]=healthPlayers[1]-weaponDamage;
      }
      else if ((attack.success==0) && (critical==1)){
        printf("Critical Hit on the Murderer, though The Detective's attack was blocked, and dealt half the damage: %.1f \n", weaponDamage);
        healthPlayers[1]=healthPlayers[1]-(weaponDamage/2);
      }
      else{
        healthPlayers[1]=healthPlayers[1]-(weaponDamage/2);
	      printf("The Detective's attack was blocked, and dealt half the damage: %.1f \n", weaponDamage);
        
	    }
      //display the health of both people
      printf("\nThe Detective's health: %.1f\nThe Murderer's health: %.1f\n\n", healthPlayers[0], healthPlayers[1]);
      //give the turn to player two
      playerNumber+=1;
	  }
	  //repeat all processes above but for opposite players
    else if (playerNumber ==2){
		  attack=AICombatFunction(2);
		  critical=criticalHitFunction(attack.target);
      weaponDamage=damageFunction(weaponNumber[1], critical);
        
      if ((attack.success==1) && (critical!=1)){
        printf("Succesful Hit on the Detective!\n");
		    healthPlayers[0]=healthPlayers[0]-weaponDamage;
      }
      else if ((attack.success==1) && (critical==1)){
        printf("Critical Hit on the Detective!\n");
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
      //give the turn back to player one
      playerNumber-=1;
    }
  }
  //if the health of The Detective hits 0, The Murderer wins
  if (healthPlayers[0]<=0){
  printf("The Murderer wins.... \n\nGAME OVER\n\n");
  return 1;
  }
  //if the health of The Murderer hits 0, The Detective wins
  else if (healthPlayers[1]<=0){
    printf("The Detective wins, justice is served. \n\nGAME OVER\n\n");
    return 2;
  }
}
