/*  Today's class will cover while and do while loops

-
-
-

*/

// First code of the day


/*
#include <stdio.h>

int main() {

    int c; //counter

    printf("Please enter a value: ");
    scanf("%d", &c);

    while (c < 5) {

        printf("%d ", (c + 1));
        c++;

    
    }

    printf("\n\n");

return 0;
}

*/

//Second Code

/*
#include <stdio.h>

int main() {

    int firstInput;
    int secondInput;

    printf("Pleae input a value: ");
    scanf("%d", &firstInput);

    printf("Once again, please: ");
    scanf("%d", &secondInput);

    while (firstInput <= secondInput) {

        printf("%d ", firstInput);
        firstInput++;

    }

    printf("\n\n");

}

*/


#include <stdio.h>

int main() {

    int userInput;
    int counter;
    int maxCounter;

    printf("Please input a value you wish to factor: ");
    scanf("%d", &userInput);

    maxCounter = userInput;
    counter = 1;

    while (counter < maxCounter) {

        userInput *= counter; 
        counter++;

       
    }

    printf("%d\n\n", userInput);

return 0;
}



//Third code, exit controlled loop (aka, do-while-loop)

/*
#include <stdio.h>

int main() {

    int userValue;
    int maxCounter = 1;
    int counter = 1;

    printf("Please enter a value: ");
    scanf("%d", &userValue);

    maxCounter = userValue;

    do {

        userValue *= counter;
        counter++;


    }   while (counter < maxCounter);

    printf("%d\n\n", userValue);

return 0;
}

*/