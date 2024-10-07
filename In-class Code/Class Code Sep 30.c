#include <stdio.h>
#include <math.h>

int main() {


/* FIRST CODE
Conditional statements...
See posted slideshow
Regard if/else statements


    int response;

    //Ask user to confirm input
    printf("Please select 'y' for yes or 'n' for no: ");
    scanf("%d", &response);

    //If-else
    if (response > 1) {

        printf("Thank you for confirming.\n");
    }
    else {
        printf("Unable to confirm, please run program again.\n");

    }

    //Else will be executed by default if "if" statement is false.

    printf("Done.\n\n");
*/

/* SECOND CODE

    int x;

    //First inputs
    printf("This program will check if an input value\n");
    printf("is even or odd.\n");

    printf("Please input a value: ");
    scanf("%d", &x);

    if (x % 2 != 1) {

        printf("This number is even.\n");
    }

    else {
        printf("This number is odd.\nn");
    }
*/

    char userInput;

    printf("This program will determine if an input character\n");
    printf("is a consonant or vowel\n");

    printf("To begin, please enter a character: ");
    scanf("%c", &userInput);

    //if-else statements
    if (userInput == 'a' || userInput == 'e' || userInput == 'i' || userInput == 'o' || userInput == 'u') {
        
        printf("User input is a vowel.\n\n");

    }

    else {

        printf("User input is a consonant.\n\n");
    }

return 0;
}

