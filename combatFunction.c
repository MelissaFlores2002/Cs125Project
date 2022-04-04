#include <stdio.h>

int combatFunction(int attackingPlayerNumber, blockingPlayerNumber){

	int blockerChoice, inputCheck;
	struct attack{
		int attackerChoice;
		int attackSuccess;
		} userAttack;
	

	printf("Player %d you are attacking now, press 1, 2, or 3 to attack: ", attackingPlayerNumber);
	inputCheck=scanf("%d", userAttack.attackerChoice);
	while ((inputCheck != 1)) || (userAttack.attackerChoice <1) || (userAttack.attackerChoice >3){
		printf("Please try again, press 1, 2, or 3 to attack: ");
		inputCheck=scanf("%d", userAttack.attackerChoice);
	}

	printf("Player %d is attacking now, Player %d, press 1, 2, or 3 to block their attack: ", attackingPlayerNumber, blockingPlayerNumber);
	inputCheck=scanf("%d", blockerChoice);
	while ((inputCheck != 1)) || (blockerChoice <1) || (blockerChoice >3){
        	printf("Please try again, press 1, 2, or 3 to block Player %d's attack: ");
        	inputCheck=scanf("%d", blockerChoice);
	}

	if (attackerChoice == blockerChoice)
		userAttack.attackerSuccess = 1;
	else
		userAttack.attackerSuccess = 0;
	return userAttack;
}
