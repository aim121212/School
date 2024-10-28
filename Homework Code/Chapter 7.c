
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

   printf("Checking...\n");
   printf("Yee, she definitely a hoe.\n\n");

return 0;
}