#include <stdio.h>

int combatFunction(int attackingPlayerNumber, blockingPlayerNumber){

	int attackerChoice, blockerChoice, inputCheck;

	printf("Player %d you are attacking now, press 1, 2, or 3 to attack: ", attackingPlayerNumber);
	inputCheck=scanf("%d", attackerChoice);
	while ((inputCheck != 1)) || (attackerChoice <1) || (attackerChoice >3){
		printf("Please try again, press 1, 2, or 3 to attack: ");
		inputCheck=scanf("%d", attackerChoice);
	}

	printf("Player %d is attacking now, Player %d, press 1, 2, or 3 to block their attack: ", attackingPlayerNumber, blockingPlayerNumber);
	inputCheck=scanf("%d", blockerChoice);
	while ((inputCheck != 1)) || (blockerChoice <1) || (blockerChoice >3){
        	printf("Please try again, press 1, 2, or 3 to block Player %d's attack: ");
        	inputCheck=scanf("%d", blockerChoice);
	}

	if (attackerChoice == blockerChoice)
		return 1;
	else
		return 0;
}
