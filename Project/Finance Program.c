#include <stdio.h>
#include <ctype.h>

int main() {

	//Initial prompts

	printf("The stock market is highly volitile. Most day traders lose money,\n");
	printf("or at best, make dismal returns of 1%% per month.\n\n");

	printf("However, you may find yourself to be an outlier, and better yet, a good trader.\n");
	printf("If this is the case, you may find the following program beneficial.\n\n");

	printf("This program will calculate possible returns from\n");
	printf("stock market investments at different rates.\n\n");


	//Program entry confirmation

	char   programConfirmation;

	printf("If you wish to continue, enter 'y',\n");
	printf("otherwise enter any other key.\n\nEntry: ");

	scanf("%c", &programConfirmation);
	printf("\n");


	//Program exit
	if (programConfirmation != 'y') {

		printf("Program will now exit; thank you for your patronage.\n\n");

	}

	else {

		double principalAmount;
		char   principalConfirmation;

		printf("Entry confrimed.\n\n");

		//Principal entry
		printf("Please enter a principal amount (initial investment amount): ");
		scanf("%lf", &principalAmount);

		printf("\nThe initial investment amount is $%.02lf.\n\n", principalAmount);

		printf("Please confirm this amount [y/n]: ");
		scanf("%c", &principalConfirmation);
		printf("\n\n");

		if (principalConfirmation != 'y') {

			printf("Program will now exit; thank you for your patronage.\n\n");

		}

		else {

			printf("Thank you for confirming.\n\n");
		}
	}


return 0;
}
