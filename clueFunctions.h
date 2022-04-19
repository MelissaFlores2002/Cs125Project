#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "clueStruct.h"

void openRoom();
void openFightRulesFile();
void openWeapons();
void openSuspects();
void story(int y, int z);
int userGuessCheck(int guess, int real);
int randomNumber(int range);
Input errorCheck(int userInput, int range, char errorStatement[100]);
bool beenInRoomCheck(int room, int* roomsExplored, int* numberOfRooms);
int explore(int room, int roomreal, int* roomsExploredStored, int* roomsExplored);
void testWeap(int input, int fakeWeaponOne, int fakeWeaponTwo, int realWeapon);
void investigate(int person, int murderer, int* innocentsArray);
void findMurdererName(int murdererNumber, char* murdererName);
void findWeaponName(int weaponNumber, char* weaponName);
void findRoomName(int roomNumber, char* roomName);
int criticalHitFunction(int target);
float damageFunction(int weapon, int critical);
int AItargetFunction();
Sequence AICombatFunction(int playerTurn);
Sequence combatFunction(int attackingPlayerNumber, int blockingPlayerNumber);
int singlePlayerFightSequence(int weaponOne, int weaponTwo);
int multiPlayerFightSequence(int weaponOne, int weaponTwo);
