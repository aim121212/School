#include <stdio.h>
#include <math.h>

int main() {

    float principalAmount;
    float targetRateOfReturn;
    float decimalRateofReturn;
    float interestTotal;
    float newPeriodBalance;

    //Initial prompt    
    printf("The following program will calculate the amount of interest in dollars\n");
    printf("neccessary to achieve a desired rate of return per period.\n\n");

    //Principal amount input
    printf("To begin, please enter the principal amount: ");
    scanf("%f", &principalAmount);
    printf("The amount entered is: $%.02f.\n\n", principalAmount);

    //Target rate of retrun input
    printf("Using only digits, please enter the desired rate of return: ");
    scanf("%f", &targetRateOfReturn);
    printf("The desired rate of return entered is: %.02f%%.\n\n", targetRateOfReturn);

    //Percentage conversion
    decimalRateofReturn = targetRateOfReturn / 100;

    //Calculations
    interestTotal = principalAmount * decimalRateofReturn;
    newPeriodBalance = principalAmount + interestTotal;

    //Output
    printf("To acheive a rate of return of %.02f%%, you must earn $%.02f in interest.\n\n", targetRateOfReturn, interestTotal);
    printf("In other words, your balance at the end of the period\n");
    printf("should be greater than $%.02f.\n\n", newPeriodBalance, targetRateOfReturn);

return 0;
}