#include <stdio.h>
#include <math.h>

int main() {

/*Nested "if-else" code

    int input;

    printf("Please enter a number: ");
    scanf("%d", &input);

    //nested if-else statement
    if(input > 10) {

        if (input < 20) {
            printf("This value is between 10 and 20\n\n");
        }

        else {
            
            printf("This value is greater than 20\n\n");
        }
    }

    else {

        printf("The number is less than 10\n\n");


    }
return 0;
*/

/* LEAP YEAR

    int yearInput;

    //User input
    printf("Please enter the year: ");
    scanf("%d", &yearInput);
    printf("The year input is: %d.\n\n", yearInput);

    //nested statements
    if ((yearInput % 100) == 0) {
        
        if (yearInput % 400 == 0) {
            
            printf("Input is a leap year.\n\n");
        }

        else {
            
            printf("Input is not a leap year.\n\n");
        }
    }

    else {
        if (yearInput % 4 ==0) {
        
            printf("Input is a leap year.\n\n");
        }

        else {
            printf("Input is not a leap year.\n\n");
        }
    }

return 0;
*/

    int finalNumberGrade;
    int convertedNumberGrade;

    printf("Please input the grade number you wish to convert: ");
    scanf("%d", &finalNumberGrade);
    printf("The input number grade is: %d.\n\n", finalNumberGrade);

    //ceiling conversion
    convertedNumberGrade = ceil(finalNumberGrade);

    if (finalNumberGrade >= 90) {

        printf("Final letter grade is: A.\n\n");
    }

    else if (finalNumberGrade >= 80) {

        printf("Final letter grade is: B.\n\n");
    }

    else if (finalNumberGrade >= 70) {

        printf("Final letter grade is: C.\n\n");
    }

    else if (finalNumberGrade >= 60) {

        printf("Final letter grade is: D.\n\n");
    }

    else {
        printf("Final letter grade is: F.\n\n");
    }

}