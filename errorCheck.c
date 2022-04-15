#include <stdio.h>

/*creating a function which will take in the user's inputs, a range that the input cannot be greater than, 
and an error statement unique for each function. This contains a while loop which repeats the error statement as well as prompts the user
until they give a valid input. It accomplishes this by using recursion and has the function return a value of 1 for the "errorCheck" value
within the structure. This sets the user into the while loop, after prompting the user, the user's input is put into the "input" value within
the structure. If there is no error, which can be accomplished in the first input or after running through the while looop multiple times,
set the structure "errorCheck" to have a value of 0 for "errorCheck" and set the value of "input" to "userInput". This function is very thorough
in its error checking.
*/
Input errorCheck(int userInput, int range, char errorStatement[100]){

  Input errorCheckTest;
  char line[100];        
  if ((userInput > range) || (userInput < 1)){
    printf("\n\nInput is out of bounds, please try again. \n\n");
    errorCheckTest.errorCheck=1;
    while (errorCheckTest.errorCheck ==1){
      printf("%s", errorStatement);
      fgets(line,100,stdin);
      errorCheckTest.userInput=atoi(line);
      errorCheckTest=errorCheck(errorCheckTest.userInput, range, errorStatement);
    }
  }
  else{
    errorCheckTest.errorCheck=0;
    errorCheckTest.userInput=userInput;
  }
  return errorCheckTest;
}
