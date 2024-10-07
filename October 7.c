/*

#include  <stdio.h>
#include <stdbool.h>
#include <math.h>

int main() {

int yearInput;
bool resultLeapYear;

//Initial inputs
printf("Please input the year in digits\n");
printf("to determine if it's a leap year: ");
scanf("%d", &yearInput);

//Bool logic
resultLeapYear = (yearInput % 100) ? ((yearInput % 400 ==0) ? (printf("Leap Year.\n\n")): printf("Not a leap year.\n\n")) : (printf("Not a leap year.\n"));


return 0;
}

// Next Code
#include  <stdio.h>

int main() {

    int a;
    int b;
    int c;
    int maxValue;

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

   ((a > b) && (a > c)) ? (printf("%d is the greatest integer.\n\n", a)) :
            
        ((b > a) && (b > c) ? printf("%d is the greatest integer.\n\n", b) : ("%d is the greatest integer.\n\n", c));

return 0;
}


//Need to Fix

#include  <stdio.h>

int main() {

    int a;
    int b;
    int c;
    int maxValue;

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

   (a > b) ? (a > c) ? (printf("%d is the greatest integer.\n\n", a)) : 
            
        ((b > a) ? (b > c) ? printf("%d is the greatest integer.\n\n", b) : ("%d is the greatest integer.\n\n", c));

return 0;
}

*/

#include  <stdio.h>

int main() {

    int userInput;

    //User input
    printf("Please enter a chosen value: ");
    scanf("%d", &userInput);

    switch (userInput) {

        case 1:
            printf("Case 1.\n\n");
            break;


        case 2:
            printf("Case 2.\n\n");
            break;

        default: 
            printf("No valid selection made.\n\n");
            break;
    }

return 0;
}