
/*

#include <stdio.h>

int main(void) {
   const int NUM_ELEMENTS = 8; // Number of elements in array
   int userVals[NUM_ELEMENTS]; // User numbers
   int i;                  // Loop index
   
   printf("Enter %d integer values...\n", NUM_ELEMENTS);
   for (i = 0; i < NUM_ELEMENTS; ++i) {
      printf("Value: ");
      scanf("%d", &(userVals[i]));
   }
   
   printf("You entered: ");
   for (i = 0; i < NUM_ELEMENTS; ++i) {
      printf("%d ", userVals[i]);
   }
   printf("\n");
   
   return 0;
}



#include <stdio.h>
#include <stdbool.h>

int main (void) {
   const int NUM_ELEMENTS = 14;
   // Weights in ounces
   double letterWeights[14] = {1.0, 2.0, 3.0, 3.5, 4.0, 5.0, 6.0,
                               7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0};
   // Costs in cents (usps.com 2017)
   int postageCosts[14] = {49, 70, 91, 112, 161, 182, 203,
                           224, 245, 266, 287, 308, 329, 350};
   double userLetterWeight;
   bool foundWeight;
   int i;
   
   // Prompt user to enter letter weight
   printf("Enter letter weight (in ounces): ");
   scanf("%lf", &userLetterWeight);
   
   // Postage costs is based on smallest letter weight greater than
   // or equal to mailing letter weight
   foundWeight = false;
   
   for (i = 0; (i < NUM_ELEMENTS) && (!foundWeight); ++i) {
      if( userLetterWeight <= letterWeights[i] ) {
         foundWeight = true;
         printf("Postage for USPS first class mail is %d cents\n",
                postageCosts[i]);
      }
   }
   
   if( !foundWeight ) {
      printf("Letter is too heavy for USPS first class mail.\n");
   }
   
   return 0;
}



#include <stdio.h>
#include <stdbool.h>

int main (void) {
   const int NUM_ELEMENTS = 14;
   // Weights in ounces
   double letterWeights[14] = {1.0, 2.0, 3.0, 3.5, 4.0, 5.0, 6.0,
                               7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0};
   // Costs in cents (usps.com 2017)
   int postageCosts[14] = {49, 70, 91, 112, 161, 182, 203,
                           224, 245, 266, 287, 308, 329, 350};
   double userLetterWeight;
   bool foundWeight;
   int i;
   
   // Prompt user to enter letter weight
   printf("Enter letter weight (in ounces): ");
   scanf("%lf", &userLetterWeight);
   
   // Postage costs is based on smallest letter weight greater than
   // or equal to mailing letter weight
   foundWeight = false;
   
   for (i = 0; (i < NUM_ELEMENTS) && (!foundWeight); ++i) {
      if( userLetterWeight <= letterWeights[i] ) {
         foundWeight = true;
         printf("Postage for USPS first class mail is %d cents\n",
                postageCosts[i]);
      }
   }

   printf("The next higher weight is %.01lf with a cost of %d cents", letterWeights[i], postageCosts[i]);
   
   if( !foundWeight ) {
      printf("Letter is too heavy for USPS first class mail.\n");
   }
   
   return 0;
}



#include <stdio.h>

int main(void) {
   const int NUM_ELEMENTS = 8; // Number of elements
   int userVals[NUM_ELEMENTS]; // User numbers
   int i;                      // Loop index
   int tempVal;                // Temp variable for swapping
   
   // Prompt user to input values
   printf("Enter %d integer values...\n", NUM_ELEMENTS);
   for (i = 0; i < NUM_ELEMENTS; ++i) {
      printf("Value: ");
      scanf("%d", &(userVals[i]));
   }
   
   // Reverse array's elements
   for (i = 0; i < NUM_ELEMENTS; ++i) {
      tempVal = userVals[i];                        // Temp for swap
      userVals[i] = userVals[NUM_ELEMENTS - 1 - i]; // First part of swap
      userVals[NUM_ELEMENTS - 1 - i] = tempVal;     // Second complete
   }
   
   // Print numbers
   printf("\nNew values: ");
   for (i = 0; i < NUM_ELEMENTS; ++i) {
      printf("%d ", userVals[i]);
   }
   
   return 0;
}




#include <stdio.h>

int main(void) {
   const int NUM_ELEMENTS = 20;         // Number of input integers
   int numberArray[NUM_ELEMENTS];
   int smallestA;
   int smallestB;
   int count;
   int i;

   //The first input is read, serves as the amount of intergers the user will input.
   scanf("%d", &count);

   //The subsequent intergers are read from input and stored in the array.
   for (i = 0; i < count; i++) {

      scanf("%d", &numberArray[i]);   
   }

   /* Stolen from the web, but it makes sense. Both intergers are initialized as the largest possible interger value, any user input will llikely be less than
   this value. If the user inputs 2147483647 then the if and else if conditions are not met and both smallestA and smallestB remain 2147483647.

   *//*
   smallestA = smallestB = 2147483647;

   //Conditions are checked to update the smallest input
   for (i = 0; i < count; i++) {

      //Beginning with index=0 (updated each iteration), the value is checked to see if it is less than the largest allowed input, most likely yes.
      if (numberArray[i] < smallestA) {

         /* Since the input most likely is less than that value, smallestA is set to the current array. We still have to check the other inputs, so 
         smallestB is assigned with smallestA. This is done first, we know the input is less than the current value in smallestA, but that might be the other
         smaller value--thus 'smallestB = smallestA;'. This will always store the next input (if smaller than 2147483647) into smallestA, loop will check next
         array index.
         *//*
         smallestB = smallestA;
         smallestA = numberArray[i];
      }

      //If the next input is greater than smallestA, and likely, less than 2147483647, smallestB is assigned with the current index value.
      else if (numberArray[i] < smallestB) {
         
         smallestB = numberArray[i];
      }

      /*The program checks the following index. If the subsequent index is less than smallestA or smallestB, either is updated respectively.
      If the next iputs are greater than either smallestA or smallestB no updates are made. Program exits the loop once the 'i' meets the max counter value.

      *//*
   }

   printf("%d and %d\n", smallestA, smallestB);

   return 0;
}

*/

/*

#include <stdio.h>

int main(void) {

   char momsHoe;

   printf("Check if your mom's a hoe [y/n]? ");
   scanf(" %c", &momsHoe);
   printf("\n");

  while (momsHoe != 'y') {

      printf("Are you sure [y/n]? ");

      scanf(" %c", &momsHoe);
  }

   printf("\n");

   char ready;

   printf("Checking...\nResults ready.\nAre you ready [y/n]?\n");
   scanf(" %c", &ready);
   printf("\nYee, she definitely a hoe.\n\n");

return 0;
}

*/
/*

#include <stdio.h>

int main(void) {

   double userWeights[5];
   int i;

   for (i = 0; i < 5; i++) {

      printf("Enter weight %d:\n", (i+1));
      scanf("%lf", &userWeights[i]);
   }

   printf("You entered: ");
   for (i = 0; i < 5; i++) {

      printf("%.02lf ", userWeights[i]);
   }

   printf("\n");
   /*double totalWeight = 0;

   for (i = 0; i < 5; i++) {

      totalWeight += userWeights[i];
   }

   double maxWeight = userWeights[0];

   for (i = 1; i < 5; i++) {

      if (userWeights[i] > maxWeight) {
         maxWeight = userWeights[i];
      }
   }

   printf("Total weight: %.02lf\n", totalWeight);
   printf("Average weight: %.02lf\n", (totalWeight/5));
   printf("Max weight: %.02lf\n", maxWeight);
   
   return 0;
}
*/

#include <stdio.h>

int main(void) {

   const int arrayMax = 5;

   int player[arrayMax];
   int jersey[arrayMax];
   int rating[arrayMax];
   int i;

   int jerseyCheck;
   int ratingCheck;
   int replacementJersey;

   for (i = 0; i < arrayMax; i++) {

      player[i] = (i + 1);
   }

   /* Enter player 1's jersey number:
      84
      Enter player 1's rating:
      7 
   */
   for (i = 0; i < arrayMax; i++) {

      printf("Enter player %d's jersey number:\n", player[i]);
      scanf("%d", &jersey[i]);
      printf("Enter player %d's rating:\n", player[i]);
      scanf("%d", &rating[i]);
      printf("\n");
   }

   printf("ROSTER\n");

   for (i = 0; i < arrayMax; i++) {

      printf("Player %d -- Jersey number: %d, Rating: %d\n", player[i], jersey[i], rating[i]);
   }

   char option = 'z';

   while (option != 'q') {

      printf("\nMENU\n");
      printf("u - Update player rating\na - Output players above a rating\nr - Replace player\no - Output roster\nq - Quit\n\n");
      printf("Choose an option:\n");
      scanf(" %c", &option);


             
         switch (option) {
      
         // Update player rating
         /* Implement the "Update player rating" menu option. Prompt the user for a player's jersey number.
         Prompt again for a new rating for the player, and then change that player's rating.
         */
         case 'u':

            printf("Enter a jersey number:\n");
            scanf(" %d", &jerseyCheck);

            for (i = 0; i < arrayMax; i++) {
            
               if (jerseyCheck == jersey[i]) {

                  printf("Enter a new rating for player:\n");
                  scanf("%d", &rating[i]);
               }
            }
         break;

         // Output players above a rating
         /* Implement the "Output players above a rating" menu option. Prompt the user for a rating.
         Print the jersey number and rating for all players with ratings above the entered value.
         */
         case 'a':

            printf("Enter a rating:\n");
            scanf("%d", &ratingCheck);

            printf("\nABOVE %d\n", ratingCheck);

            for (i = 0; i < arrayMax; i++) {
            
               if (rating[i] > ratingCheck) {

                  printf("Player %d -- Jersey number: %d, Rating: %d\n", player[i], jersey[i], rating[i]);
               }
            }
         break;
      
         // Replace player
         /* Implement the "Replace player" menu option. Prompt the user for the jersey number of the player to replace.
         If the player is in the roster, then prompt again for a new jersey number and rating. Update the replaced player's jersey number and rating. 
         */
         case 'r':

            printf("Enter a jersey number:\n");
            scanf("%d", &replacementJersey);

            for (i = 0; i < arrayMax; i++) {
         
               if (replacementJersey == jersey[i]) {

                  printf("Enter a new jersey number:\n");
                  scanf("%d", &jersey[i]);
                  printf("Enter a rating for the new player:\n");
                  scanf("%d", &rating[i]);
                  printf("\n");
               }
            }
         break;
      
         // Output roster
         case 'o':

            printf("ROSTER\n");
         
            for (i = 0; i < arrayMax; i++) {

               printf("Player %d -- Jersey number: %d, Rating: %d\n", player[i], jersey[i], rating[i]);
            }
         break;
      
         // Quit
         case 'q':
            option = 'q';
            break;
   
         default:
            break;
      }
   }

   //Numbers to use 84 7 23 4 4 5 30 2 66 9
   return 0;
}

/* 84 7
   23 4
   4 5
   30 2
   66 9
   r 12
   o
   q
*/