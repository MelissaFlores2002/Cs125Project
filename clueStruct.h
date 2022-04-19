#pragma once
#include <stdio.h>
//defining a structure which contains the user's guess for the murderer, weapon, and room
typedef struct guesses {
  int murderer;
  int weapon;
  int room;
} userGuess;

//defining a structure which contains the user's inputs for usage in the errorCheck function
typedef struct inputs {
    int errorCheck;
    int userInput;
} Input;

//defining a structure which takes into account location and success of the attack
typedef struct combatInputs{
		int target;
		int success;
} Sequence;
