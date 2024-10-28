#include <stdio.h>
#include <math.h>

int main() {

    //Initial user inputs
    float principalAmount;
    int periodAmounts;
    //Rates in decimal
    float lowRoR;
    float midRoR;
    float highRoR;
    //Low calculations
    float lowPeriodCalculation;
    float totalLowCalculation;
    //Mid calculations
    float midPeriodCalculation;
    float totalMidCalculation;
    //High calculations
    float highPeriodCalculation;
    float totalHighCalculation;
    //Totals
    float lowTotal;
    float midTotal;
    float highTotal;

    lowRoR = 00.04;
    midRoR = 00.07;
    highRoR = 00.10;

    //Initial Message
    printf("The following program will calculate a range of returns given\n");
    printf("values for a principal amount and number of periods by the user.\n\n");

    //Principal Entry
    printf("Enter the initial investment amount: ");
    scanf("%f", &principalAmount);
    printf("The initial investment amount entered is $%.02f.\n\n", principalAmount);

    //Period Amounts
    printf("Enter amount of periods: ");
    scanf("%d", &periodAmounts);
    printf("The amount of periods entered is: %d.\n\n", periodAmounts);

    //Low retrun calculations
    lowPeriodCalculation = pow((1 + lowRoR), periodAmounts);
    totalLowCalculation = (principalAmount * lowPeriodCalculation);

    //Mid retrun calculations
    midPeriodCalculation = pow((1 + midRoR), periodAmounts);
    totalMidCalculation = (principalAmount * midPeriodCalculation);

    //High retrun calculations
    highPeriodCalculation = pow((1 + highRoR), periodAmounts);
    totalHighCalculation = (principalAmount * highPeriodCalculation);

    //Conversion of RoRs to percentages
    lowRoR *= 100;
    midRoR *= 100;
    highRoR *= 100;

    //Interest rate presentation
    printf("A range of rates of return is shown below:\n");
    printf("Low rate of return: %.02f%%.\n", lowRoR);
    printf("Mid rate of return: %.02f%%.\n", midRoR);
    printf("High rate of return: %.02f%%.\n\n", highRoR);

    //Final return presentation
    printf("The estimated final return for an investment in the\n");
    printf("amount of $%.02f over %d periods is shown below:\n\n", principalAmount, periodAmounts);
    printf("A return at a rate of %.02f%% amounts to $%.02f.\n", lowRoR, totalLowCalculation);
    printf("A return at a rate of %.02f%% amounts to $%.02f.\n", midRoR, totalMidCalculation);
    printf("A return at a rate of %.02f%% amounts to $%.02f.\n\n", highRoR, totalHighCalculation);

    printf("Invest, it's your future!!!\n\n");

return 0;
}