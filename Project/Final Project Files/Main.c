#include <stdio.h>
#include <string.h>

// Function prototypes
int askForPackages();
int capacityFunction(char typeOfEvent);
float dayFunction(char typeOfEvent, int *dayOfEvent, char *dayString);

double BasePrice(char typeOfEvent, int numOfPeople); 

int foodOption();
double foodPrice(int foodOption, int numPeople);

int entertainmentOption();
double entertainmentPrice(int entertainmentOption, int numPeople, float dayFunction);

double totalPrice(double basePrice, double foodCost, double entertainmentCost, float dayFunction);

// Supporting Functions
int askForPackages() {
     //Prompts the user if they would like to explore available food and entertainment options for their event.
    // returns 1 for "yes" and 0 for "no". 

    char option[10];

    printf("\nWould you like to see our available options for food and entertainment for your event?\n");
    printf("Selections will be used to build custom 'packages' for your event.\n\n");
    printf("Please type 'yes' or 'no': ");
        
        // suggest removing this: 'while(getchar() != '\n');'
    
        // while loop to handle invalid outputs (not "yes" or "no").
        while(1){    
        fgets(option, sizeof(option), stdin);
        option[strcspn(option, "\n")] = '\0';
        
        if (strcmp(option, "yes") == 0){
            return 1;
        }
        else if (strcmp(option, "no") == 0){
            return 0;
            
        }
         else {
             printf("Invalid choice: please enter 'yes' or 'no':\n");
        }   
        }
    
}

int capacityFunction(char typeOfEvent) {
    //Handles expected numbers of guests.
    //Ensures that the number of guests attending is valid (1-500).
    // returns the number of guests.
    int numOfPeople = 0;
    printf("\nHow many guests do you expect to have at your event? (Max capacity: 500)\n");
    scanf("%d", &numOfPeople);
    getchar();

    //While loop to handle invalid number of guests. 
    while (numOfPeople > 500 || numOfPeople < 1) {
        
        printf("Invalid entry. Enter a number between 1 and 500: ");
        scanf("%d", &numOfPeople);
        getchar();
    }
    printf("You are expecting %d guests.\n", numOfPeople);
    return numOfPeople;
}

float dayFunction(char typeOfEvent, int *dayOfEvent, char *dayString) {
//Handles day selection based on type of event.
//Adds an overtime charge exceeding 4 hours.
//Returns a multiplier ( timeofEvent = 4, or 6 for overtime).
    char eventString[25];
    char overtimeResponse;

    float timeOfEvent;

    //Event string for prompts
    switch (typeOfEvent) {
        
        case 'w':
        case 'W':
            strcpy(eventString, "wedding");
            break;
        case 'q':
        case 'Q':
            strcpy(eventString, "quinceañera");
            break;
        case 'b':
        case 'B':
            strcpy(eventString, "baby shower");
            break;
        default:
            strcpy(eventString, "special event");
            break;
    }

    printf("\nWhat day would you like to host your %s?\n\n", eventString);
    
    /*Based on the type of event, the switch asks the user for what day of the week they would like to hold their event.
    It also asks if they will use the venue for more than four hours. dayString
    
    */
    
    switch (typeOfEvent) {
        
        case 'w':
        case 'W':
            printf("We can accomodate weddings on Fridays or Saturdays.\n");
            printf("What day works best for your event?\n1 - Friday\n2 - Saturday\n");
            printf("\nPlease enter your response using the corresponding numerical value (e.g., '1' for Friday): ");
            scanf("%d", dayOfEvent);
            getchar();
            printf("Do you expect to use the venue for over 4 hours? [Y/n] ");
            scanf("%c", &overtimeResponse);
            getchar();
            break;
        case 'q':
        case 'Q':
            printf("We can accomodate quinceañeras on Fridays or Saturdays.\n");
            printf("What day works best for your event?\n1 - Friday\n2 - Saturday\n");
            printf("\nPlease enter your response using the corresponding numerical value (e.g., '1' for Friday): ");
            scanf("%d", dayOfEvent);
            getchar();
            printf("Do you expect to use the venue for over 4 hours? [Y/n] ");
            scanf("%c", &overtimeResponse);
            getchar();
            break;
        case 'b':
        case 'B':
            printf("We can accomodate baby showers on Fridays, Saturdays, or Sundays.\n");
            printf("What day works best for your event?\n1 - Friday\n2 - Saturday\n3 - Sunday\n");
            printf("\nPlease enter your response using the corresponding numerical value (e.g., '1' for Friday): ");
            scanf("%d", dayOfEvent);
            getchar();
            printf("Do you expect to use the venue for over 4 hours? [Y/n] ");
            scanf("%c", &overtimeResponse);
            getchar();
            break;
        default:
            printf("We can accomodate special events on Fridays, Saturdays, or Sundays.\n");
            printf("What day works best for your event?\n1 - Friday\n2 - Saturday\n3 - Sunday\n");
            printf("\nPlease enter your response using the corresponding numerical value (e.g., '1' for Friday): ");
            scanf("%d", dayOfEvent);
            getchar();
            printf("Do you expect to use the venue for over 4 hours? [Y/n] ");
            scanf("%c", &overtimeResponse);
            getchar();
            break;
    }

    printf("\nYour %s is to be held on a ", eventString);

    //String is derrived from day of event.
    switch (*dayOfEvent) {

        case 1:
            strcpy(dayString, "Friday");
            break;
        case 2:
            strcpy(dayString, "Saturday");
            break; 
        case 3:
            strcpy(dayString, "Sunday");
            break;
        default:
            strcpy(dayString, "Invalid Day");
            break;
    }

    printf("%s.\n", dayString);

    if (overtimeResponse == 'y' || overtimeResponse == 'Y') {

        printf("You expect your event to last longer than 4 hours.\n");
    }

    else {

        printf("You expect your event to last less than 4 hours.\n");
    }

    timeOfEvent = 4.0;
        
    if (overtimeResponse == 'y' || overtimeResponse == 'Y') {

        timeOfEvent *= 1.5;
    }

return timeOfEvent;
}

double BasePrice(char typeOfEvent, int numOfPeople) {
// Calculates the base price based on the type of event and guest count.
// Returns Final base cost for the event.
// Displays initial and final cost of the event.
    
    double baseCost;
    double finalBase;
    double rate;

    char eventString[25];

    //If/else logic

    //If the clients intend to hold a small amount of guests, the rate for use of the venue is calculated accordingly.
    if (numOfPeople <= 100) {

        if (numOfPeople < 50) {
            
            rate = numOfPeople * .002;
        }

        else {

            rate = numOfPeople * .0007;
        }

    }

    //If the client intends to hold an average amount of guests the following rate is calculated
    else if ((numOfPeople > 100) && (numOfPeople < 300)) {
        
        rate = numOfPeople *.0009;
    }

    //Otherwise a large amount of guests are expected, the following rate is calculated
    else {

        rate = numOfPeople * 0.0015;
    }
    

    //Each event has a fixed base price regardless of how many people are in attendance.
    switch (typeOfEvent) {
        case 'W':
        case 'w': 
            strcpy(eventString, "wedding");
            baseCost = 9000.0;
            break;
        case 'Q':
        case 'q':
            strcpy(eventString, "quinceañera");
            baseCost = 7500.0;
            break;
        case 'B':
        case 'b':
            strcpy(eventString, "baby shower");
            baseCost = 5000.0;
            break;
        default:
            strcpy(eventString, "special event");
            baseCost = 3000.0;
            break;
    }

    //Based on the event chosen, a  base cost and a rate based on the number of people is is added and a base cost is established..
    finalBase = baseCost + (baseCost * rate);

    printf("\nThe initial cost for your %s is $%.2lf; for %d guests, you can expect a base cost of $%.02lf.\n\n", eventString, baseCost, numOfPeople, finalBase);
    
return finalBase;
}

int foodOption() {
// Function that asks the user to choose a catering option.
// Returns selected catering option.
    int foodOption;
    
    //Prompts to user
    printf("\nYou have the option to secure catering from our venue's trusted partners or you may select to provide your own.\n");
    printf("Our venue typically works with two prominent catering services in the area, both are of equal quality, but have different menus.\n");
    printf("Please review their menus, or select your own service and let us know your decision by making a selection in the following prompts.\n\n");
    printf("Please make a selection from the list below:\n");
    
    printf("1 - Italian Based Cater\n");
    printf("2 - Mexican Based Cater\n");
    printf("3 - Client-Sourced Cater\n\n");
    printf("Enter your choice: ");
    scanf("%d", &foodOption);
    getchar();

    //While loop to ensure valid food option input from the user.
    while (foodOption < 1 || foodOption > 3) {
        
        printf("Invalid choice. Enter 1, 2, or 3: ");
        scanf("%d", &foodOption);
        getchar();
    }

    printf("You chose option %d.\n\n", foodOption);
    return foodOption;
}

double foodPrice(int foodOption, int numPeople) {
// Calculates food price based on food option, menu choice, and number of people attending. 
// Returns total cost and details of chosen menu.
    
    int menuChoice; 
    double price;
    double pricePerPlate;

 //If/else if ladder to deterine menu based on caterer.
    if (foodOption == 1) {
        
        printf("Italian Caterer Menu Options:\n");
        printf("1 - Meat Eater's: Spaghetti and Meatballs, Lasagna, Chicken Parmesean ($25/plate)\n");
        printf("2 - Vegeterian Friendly: Fettuccine Alfredo, Pasta Primavera, Stuffed Raviolli ($20/plate)\n");
        printf("3 - Italian Buffet: Various all you can eat options starting at ($45/plate)\n");
        printf("Enter your choice of menu: ");
        scanf("%d", &menuChoice);
        getchar();

        while (menuChoice < 1 || menuChoice > 3){
            
            printf("Invalid choice. Enter 1, 2, or 3: ");
            scanf("%d", &menuChoice);
            getchar();
        }

        if (menuChoice == 1) {

            pricePerPlate = 25.00;
        }

        else if (menuChoice == 2) {
             
             pricePerPlate = 20.00;
        }

        else {

            pricePerPlate = 45.00;
        }
    }

    else if (foodOption == 2) {

        printf("Mexican Caterer Menu Options:\n");
        printf("1 - Street Fest: Flautas, Tacos, Burritos y Mas ($20/plate)\n");
        printf("2 - Traditional: Mole, Chile Relleno, Posole ($30/plate)\n");
        printf("3 - Mexican Buffet ($45/plate)\n");
        printf("Enter your choice of menu: ");
        scanf("%d", &menuChoice);
        getchar();

        while (menuChoice < 1 || menuChoice > 3) {
            
            printf("Invalid choice. Enter 1, 2, or 3: ");
            scanf("%d", &menuChoice);
            getchar();
        }

        if (menuChoice == 1) {
        
            pricePerPlate = 20;
        }
        
        else if (menuChoice == 2) {
        
            pricePerPlate = 30;
        }

        else {
             
             pricePerPlate = 45;
        }
    }

    else {

        pricePerPlate = 7.5;
        printf("You have selected to provide your own catering. A minor fee is assesed for use of the venue's kitchen and other amenities.\n");
        printf("The fee is based on the number of expected guests; the fee per guest is in the amount of $%.02lf.", pricePerPlate);
    }

    switch (foodOption) {
    case 1:
        
        printf("\nYou chose the Italian Catering service.\n");

        if (menuChoice == 1) {

            printf("Your chosen menu includes: Spaghetti and Meatballs, Lasagna, and Chicken Parmesean");
        }
        
        else if (menuChoice == 2) {

            printf("Your chosen menu includes: Fettuccine Alfredo, Pasta Primavera, and Stuffed Raviolli");
        }

        else {

            printf("You selected the buffet option, one of our representatives will reach out to you to select and confirm your options.");
        }
        break;
    case 2:

        printf("\nYou chose the Mexican Catering service.\n");

        if (menuChoice == 1) {

            printf("Your chosen menu includes: Flautas, Tacos, Burritos y Mas");
        }
        
        else if (menuChoice == 2) {

            printf("Your chosen menu includes: Mole, Chile Relleno, and Posole");
        }

        else {

            printf("You selected the buffet option, one of our representatives will reach out to you to select and confirm your options.");
        }
        break;
    }

    price = numPeople * pricePerPlate;
    printf("\nThe total estimated cost for food for you and your %d guests is: $%.02lf.\n", numPeople, price);

return price;
}

int entertainmentOption() {
// Handles entertainment options.
// Prompts user to choose base option which is then followed with a selection of an extra option.
//Returns sum price for base and extra option.
    
    int entertainmentOption;
    int baseOption;
    int extraOption;

    //Initial prompts
    printf("\nThe following will help build an entertainment package for your event.");
    printf("\nWe offer entertainment options from Music to Performances.\nPlease review and select an option(s) from the list(s) below:\n");

    //Base entertainment selections
    printf("\nEntertainment Options:\n\n");
    printf("1 - DJ of all genres\n"); //500
    printf("2 - Mariachi (mexican music group)\n"); //800
    printf("3 - Classical Orchestra\n"); //900
    printf("4 - Zippy the Clown\n"); //500
    printf("5 - Client-provided entertainment\n"); //100
    printf("6 - No entertainment required\n\n");  //0
    printf("Enter your choice: ");
    scanf("%d", &baseOption);
    getchar();

    //While loop for valid entry
    while (baseOption < 1 || baseOption > 7) {
        printf("Invalid choice. Enter 1, 2, 3, 4, 5, or 6: ");
        scanf("%d", &baseOption);
        getchar();
    }

    if (baseOption == 6) {

        printf("No entertainment required for event.\n");
    }

    else {

        printf("\nThank you for your selection. ");

        //Extras prompts
        printf("Would you like to add an extra from the list below? (choose one)\n\n");
        printf("Extras:\n");
        printf("1 - Kids Room (playtime room)\n");  //400
        printf("2 - Jumping Balloon\n");  //300
        printf("3 - Candy Bar (sweets and deserts)\n"); //200
        printf("4 - No extra required\n\n");
        printf("Enter your choice: ");
        scanf("%d", &extraOption);
        getchar();

        //While loop for valid entry
        while (extraOption < 1 || extraOption > 4) {

            printf("Invalid choice. Enter 1, 2, 3, or 4: ");
            scanf("%d", &extraOption);
            getchar();
        }

        if (extraOption == 4) {
            
            printf("No extra entertainment chosen.\n");
        }
    }

    entertainmentOption = (baseOption * 10) + extraOption;

return entertainmentOption;
}

double entertainmentPrice(int entertainmentOption, int numPeople, float dayFunction) {
//Function for entertainment package
    double price;
    double rate = numPeople * .1;

    double djPrice = 1000;
    double mariachiPrice = 1750;
    double orchestraPrice = 2100;
    double clownPrice = 500;
    double clientPrice = 100;

    double kidsRoomPrice = 800;
    double jumpingBallonPrice = 400;
    double candyBarPrice = 600;

    printf("\nYou have selected the following entertainment option(s):\n");
    
// Switch statements for Base + extra option.
// Ten's place is reserved for number of base option and one's place is reserved for extra option.
    switch (entertainmentOption) {

        case 60:
        case 61:
        case 62:
        case 63:
        case 64:
            printf("NONE.");
            break;
        case 50:
        case 51:
        case 52:
        case 53:
        case 54:
            printf("Client will provide their own entertainment for the rate below.\n");
            break;
        case 11:
            printf("DJ and kid's room\n");
            price = djPrice + kidsRoomPrice;
            price += rate;
            break;
        case 12:
            printf("DJ and jumping ballon\n");
            price = djPrice + jumpingBallonPrice;
            price += rate;
            break;
        case 13:
            printf("DJ and candy bar\n");
            price = djPrice + candyBarPrice;
            price += rate;
            break;
        case 14:
            printf("DJ\n");
            price = djPrice;
            price += rate;
            break;
        case 21:
            printf("Mariachi and kid's room\n");
            price = mariachiPrice + kidsRoomPrice;
            price += rate;
            break;
        case 22:
            printf("Mariachi and jumping ballon\n");
            price = mariachiPrice + jumpingBallonPrice;
            price += rate;
            break;
        case 23:
            printf("Mariachi and candy bar\n");
            price = mariachiPrice + candyBarPrice;
            price += rate;
            break;
        case 24:
            printf("Mariachi\n");
            price = mariachiPrice;
            price += rate;
            break;
        case 31:
            printf("Orchestra and kid's room\n");
            price = orchestraPrice + kidsRoomPrice;
            price += rate;
            break;
        case 32:
            printf("Orchestra and jumping ballon\n");
            price = orchestraPrice + jumpingBallonPrice;
            price += rate;
            break;
        case 33:
            printf("Orchestra and candy bar\n");
            price = orchestraPrice + candyBarPrice;
            price += rate;
            break;
        case 34:
            printf("Orchestra\n");
            price = orchestraPrice;
            price += rate;
            break;
        case 41:
            printf("Zippy the Clown and kid's room\n");
            price = clownPrice + kidsRoomPrice;
            price += rate;
            break;
        case 42:
            printf("Zippy the Clown and jumping ballon\n");
            price = clownPrice + jumpingBallonPrice;
            price += rate;
            break;
        case 43:
            printf("Zippy the Clown and candy bar\n");
            price = clownPrice+ candyBarPrice;
            price += rate;
            break;
        case 44:
            printf("Zippy the Clown\n");
            price = clownPrice;
            price += rate;
            break;
        default:
        price = 0.00; //For events like business meetings where entertainment is may not be required.
    }

return (price * dayFunction);
}

double totalPrice(double basePrice, double foodCost, double entertainmentCost, float dayFunction) {
 //Sum of base price, food cost, and entertainment cost.
    return basePrice + foodCost + entertainmentCost + dayFunction;
} //Simple calculation comprimising of previous price/cost functions.

//Main Function
void main() {

    //Initial declarations
    char typeOfEvent;
    char dayString[12];
    char eventString[25];
    char foodString[25];
    char entertainmentString[25];

    int numOfPeople;
    int dayOfEvent;
    int foodOptionChoice;
    int entertainmentOptionChoice;

    float dayFactor;

    double timeOfEvent;
    double baseCost;
    double foodCost;
    double entertainmentCost;
    double totalCost;



    //Inital prompts to user
    printf("Welcome User!\n");
    printf("Thank you for choosing ADK as your choice of venue for your next event!\n\n");
    printf("The following program wil help you plan and book your event with us.\n");
    printf("You will be asked to provide various information.\nOnce finalized, a detailed summary ");
    printf("of your event and corresponding quote will be generated for your review.\n\n");

    //User is asked for event type and selection is stored in typeOfEvent variable. 
    printf("Please choose an option for the type of event you are hosting from the list below:\n\n");
    printf("W - Wedding\nQ - Quinceañera\nB - Baby Shower\nS - Special Event\n ");
    printf("\n");
    printf("Enter event type: ");
    scanf("%c", &typeOfEvent);
    getchar();

    //Event string for prompts; primarily for interaction with user.
    switch (typeOfEvent) { 
        
        case 'w':
        case 'W':
            strcpy(eventString, "wedding");
            break;
        case 'q':
        case 'Q':
            strcpy(eventString, "quinceañera");
            break;
        case 'b':
        case 'B':
            strcpy(eventString, "baby shower");
            break;
        default:
            strcpy(eventString, "special event");
            break;
    }
    printf("Event type selected is %s.\n", eventString);



    //Main function calls capacityFunction and stores return in numOfPeople.
    numOfPeople = capacityFunction(typeOfEvent);
    printf("\n");

    //Main function stores return of BasePrice function in baseCost.
    baseCost = BasePrice(typeOfEvent, numOfPeople);

    /*These first two assignments call the respective functions for use in the following functions. Prompts to user to update/change any of these initial responses 
    immidiately follows this comment section.
    */

            //Update to amount of event type and guests is prompted and executed if required.
            printf("Would you like to make any changes to your selections [Y/n]? ");
            
            char responseA;
            char peopleAmountUpdate;
            char eventUpdate;

            scanf("%c", &responseA);
            getchar();

            if (responseA == 'y' || responseA == 'Y') {

                printf("\nChange event type [Y/n]? ");
                scanf("%c", &eventUpdate);
                getchar();

                if (eventUpdate == 'y' || eventUpdate == 'Y') {

                    printf("Enter the correct event type from the list above: ");
                    scanf("%c", &typeOfEvent);
                    getchar();

                    //String update
                    switch (typeOfEvent) {
                
                        case 'w':
                        case 'W':
                            strcpy(eventString, "wedding");
                            break;
                        case 'q':
                        case 'Q':
                            strcpy(eventString, "quinceañera");
                            break;
                        case 'b':
                        case 'B':
                            strcpy(eventString, "baby shower");
                            break;
                        default:
                            strcpy(eventString, "special event");
                            break;
                    }
                
                printf("The event has been updated to: %s.\n", eventString);
                }
                
                printf("\nUpdate guest amount [Y/n]? ");
                scanf("%c", &peopleAmountUpdate);
                getchar();

                if (peopleAmountUpdate == 'y' || peopleAmountUpdate == 'Y') {            

                    numOfPeople = capacityFunction(typeOfEvent);
                }

                printf("\nUPDATE:");
                baseCost = BasePrice(typeOfEvent, numOfPeople);
            }


            //This next section of code assigns the day factor float variable with the result from day function.
            char responseB; //Will loop if user enters anything other than 'y' or 'Y', indicating that their responses are incorrect.

            //Day function is prompted to user
            do {
            
                dayFactor = dayFunction(typeOfEvent, &dayOfEvent, &dayString);
                printf("\nIs this correct? [Y/n]\n\nIf not, or if you would like\nto ammend your response type 'n'.\nResponse: ");
                scanf("%c", &responseB);
                getchar();
            } while (responseB != 'y' && responseB != 'Y');



    //Package logic
    char packageUpdate = 'y'; //Initialization to enter while loop in the following section of code.
    
    if (askForPackages()) {

            //While loop always executes and only exits when the user selects 'n' indicating they would not like to make upates.
            while (packageUpdate != 'n' && packageUpdate != 'n') {
        
            printf("\nThank you...\n");

            foodOptionChoice = foodOption(); //Calling foodOption function to select food options
            foodCost = foodPrice(foodOptionChoice, numOfPeople); //Food cost is calculated by calling foodPrice function.
            entertainmentOptionChoice = entertainmentOption(); //Calls entertainmentOption to select entertainment options.
            entertainmentCost = entertainmentPrice(entertainmentOptionChoice, numOfPeople, dayFactor); //Entertainment cost is calculated by calling entertainmentPrice function.

            //User is asked if they would like to make any changes to their previous selections. Only when user enters 'n' or 'N' will the loop exit.
            printf("Would you like to make any changes to your packages? [Y/n] ");
            scanf("%c", &packageUpdate);
            getchar();
        } 
    }

    //No cost associated for entertainment or food. Posibly for mafia types...    
    else {
        foodCost = entertainmentCost = 0.0;
    }

    //A total cost is calculated usining the totalPrice function.
    totalCost = totalPrice(baseCost, foodCost, entertainmentCost, dayFactor);
    //Final Prompts
    printf("\nFINAL EVENT SUMMARY:\n\n");

    printf("You are planning on hosting a %s.\n", eventString);
    printf("You are expecting %d guests at your event.\n", numOfPeople);
    printf("Your event is to be held on a %s.\n\n", dayString);

    printf("The base cost for your event is $%.2lf\nTotal food cost: $%.2lf\nTotal base entertainment cost: $%.2lf\n", baseCost, foodCost, entertainmentCost);
    printf("\nThe total estimated cost for %d guests amounts to: $%.2lf\n\n", numOfPeople, totalCost);
}
