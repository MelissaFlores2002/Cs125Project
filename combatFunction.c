#include <stdio.h>

//calling combatFunction that accomplishes the same thing as "AICombatFunction" but is instead for multi-player
Sequence combatFunction(int attackingPlayerNumber, int blockingPlayerNumber){
  //initializing variables
	Sequence attack, block;
  Input errorCheckTest;

  //print statements which prompt the attacking user to attack
	printf("Player %d you are attacking now, press 1, 2, or 3 to attack: ", attackingPlayerNumber);
	scanf("%d", &attack.target);
    
  //error checking
  errorCheckTest=errorCheck(attack.target, 3, "Please try again, press 1, 2, or 3 to attack: ");
  attack.target=errorCheckTest.userInput;
  
  //print statements prompting the blocking user to block
	printf("Player %d, press 1, 2, or 3 to block their attack: ", blockingPlayerNumber);
	scanf("%d", &block.target);

  //error checking
  errorCheckTest=errorCheck(block.target, 3, "Please try again, press 1, 2, or 3 to block Player %d's attack: ");
  block.target=errorCheckTest.userInput;

  //if the position of the block and the attack is the same, the attack will not succeed
	if (attack.target == block.target)
		attack.success = 0;
	else
		attack.success = 1;
	return attack;
}        
