//Melissa Flores and Hunter Difabio
#include <stdio.h>

//hard coding the damage for weapons based on .txt file which states them. Doubling damage if it is a critical strike.
float damageFunction(int weapon, int critical){
	float weaponDamage;
    if (weapon ==1)
		weaponDamage=3;
	else if ((weapon ==2) || (weapon ==7))
		weaponDamage=4;
	else if ((weapon ==3) || (weapon ==5))
		weaponDamage=1;
	else if ((weapon ==4) || (weapon ==6))
		weaponDamage = 2;
    if (critical ==1)
        weaponDamage=weaponDamage*2;
	return weaponDamage;
}
