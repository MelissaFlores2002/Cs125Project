#include <stdio.h>

/*
function which takes in the input of the roomsExplored array as well as the input of the room
with the purpose of discovering if the user has been in the room already
*/
bool beenInRoomCheck(int room, int* roomsExplored, int* numberOfRooms){
  //loop counter
  int loopCounter;
  bool check;
  if (numberOfRooms==NULL){
    check=false;
  }
  else{
    for (loopCounter=0; loopCounter<=*numberOfRooms; loopCounter++){
      if (roomsExplored[loopCounter]==room){
        check=true;
        printf("Check is %d", check);
      }
      else{
        check=false;
        printf("Check is %d", check);
      }
    }
  }
  return check;
}
