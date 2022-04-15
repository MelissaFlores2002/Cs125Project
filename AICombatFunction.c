/*
//Melissa Flores and Hunter Difabio
#include <stdio.h>

//function which takes into account the AI's random input and prompts the user to input themselves based on if the player is blocking or attacking
Sequence AICombatFunction(int playerTurn){
  Sequence computerAttack, userAttack, computerBlock, userBlock;
  Input errorCheckTest;
  //when the AI is attacking, the player must block their attack
  if (playerTurn == 2){
    printf("The Murderer is calculating their attack... \n");
	  //calling the AI target function to determine position
    computerAttack.target=AItargetFunction();

	  printf("Player One, press 1, 2, or 3 to block their attack: ");
	  scanf("%d", &userBlock.target);
        
    //error checking
    errorCheckTest=errorCheck(userBlock.target, 3, "Please try again, press 1, 2, or 3 to block Player %d's attack: ");
    userBlock.target=errorCheckTest.userInput;
    
    //if the position of the block and the attack is the same, the attack will not succeed
	  if (computerAttack.target == userBlock.target)
	    computerAttack.success = 0;
	  else
		  computerAttack.success = 1;
	  return computerAttack;
  }
  
  else if (playerTurn == 1){
    //when the player is attacking, the AI must block their attack
    printf("Player One you are attacking now, press 1, 2, or 3 to attack: ");
	  scanf("%d", &userAttack.target);
        
    //error checking
    errorCheckTest=errorCheck(userAttack.target, 3, "Please try again, press 1, 2, or 3 to attack: ");
    userAttack.target=errorCheckTest.userInput;

    printf("The Murderer is calculating where to block... \n");
    //calling the AI target function to determine positiopn
    computerBlock.target=AItargetFunction();
        
    //if the position of the block and the attack is the same, the attack will not succeed
    if (userAttack.target == computerBlock.target)
      userAttack.success = 0;
    else
     userAttack.success = 1;
	//    return userAttack;
  //}
  }
	*/
