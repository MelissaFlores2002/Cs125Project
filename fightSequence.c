int playerNumber, result, weaponNumber, damage, healthPlayer[1,2]=10,10;
playerNumber=1;
while ((health[1]!=0) && (health[2]!=0)){
	
	if (playerNumber==1){
		result=combatFunction(1);
		damage=damageFunction(weaponNumber)
		criticalHitFunction(userChoice)
		if result=1
			healthPlayer[1]=healthPlayer[1]-damage;
		else
			healthPlayer[1]=healthPlayer[1]-(damage/2);
		playerNumber+=1;
		}
	if else (playerNumber ==2){
		result=combatFunction(2);
		damage=damageFunction(weaponNumber)
        	criticalHitFunction(userChoice)
        	if result=1
                	healthPlayer[2]=healthPlayer[2]-damage;
        	else
                	healthPlayer[2]=healthPlayer[2]-(damage/2);
}
