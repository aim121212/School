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

double totalPrice(double basePrice, double foodCost, double entertainmentCost);

// Supporting Functions
int askForPackages() {

    char option[10];

    printf("\nWould you like to see our available options for food and entertainment for your event?\n");
    printf("Selections will be used to build custom 'packages' for your event.\n\n");
    printf("Please type 'yes' or 'no': ");
        
        // suggest removing this: 'while(getchar() != '\n');'
        
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
    int numOfPeople = 0;
    printf("\nHow many guests do you expect to have at your event? (Max capacity: 500)\n");
    scanf("%d", &numOfPeople);
    getchar();

    while (numOfPeople > 500 || numOfPeople < 1) {
        
        printf("Invalid entry. Enter a number between 1 and 500: ");
        scanf("%d", &numOfPeople);
        getchar();
    }
    printf("You are expecting %d guests.\n", numOfPeople);
    return numOfPeople;
}

float dayFunction(char typeOfEvent, int *dayOfEvent, char *dayString) {

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

    double baseCost;
    double finalBase;
    double rate;

    char eventString[25];

    int i = 0;

    while (i == 0) {

        if (numOfPeople <= 100) {

            if (numOfPeople < 50) {
                
                rate = numOfPeople * .002;
            }

            else {

                rate = numOfPeople * .0007;
            }

        }

        else if ((numOfPeople > 100) && (numOfPeople < 300)) {
            
            rate = numOfPeople *.0009;
        }

        else {

            rate = numOfPeople * 0.0015;
        }
        

        i++;
    }

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

    finalBase = baseCost + (baseCost * rate);

    printf("\nThe initial cost for your %s is $%.2lf; for %d guests, you can expect a base cost of $%.02lf.\n\n", eventString, baseCost, numOfPeople, finalBase);
    
return finalBase;
}

int foodOption() {
    
    int foodOption;
    
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

    while (foodOption < 1 || foodOption > 3) {
        
        printf("Invalid choice. Enter 1, 2, or 3: ");
        scanf("%d", &foodOption);
        getchar();
    }

    printf("You chose option %d.\n\n", foodOption);
    return foodOption;
}

double foodPrice(int foodOption, int numPeople) {

    int menuChoice; 
    double price;
    double pricePerPlate;

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

double totalPrice(double basePrice, double foodCost, double entertainmentCost) {
    return basePrice + foodCost + entertainmentCost;
}

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

    //User is asked for event type.    
    printf("Please choose an option for the type of event you are hosting from the list below:\n\n");
    printf("W - Wedding\nQ - Quinceañera\nB - Baby Shower\nS - Special Event\n ");
    printf("\n");
    printf("Enter event type: ");
    scanf("%c", &typeOfEvent);
    getchar();

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

    printf("Event type selected: %s.\n", eventString);



    //Main function calls capacityFunction and stores return in numOfPeople.
    numOfPeople = capacityFunction(typeOfEvent);
    printf("\n");

    //Main function stores return of BasePrice function in baseCost.
    baseCost = BasePrice(typeOfEvent, numOfPeople);

    //Update to initial responses
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

    char responseB;

    //Day function is prompted to user
    do {
    
        dayFactor = dayFunction(typeOfEvent, &dayOfEvent, dayString);
        printf("\nIs this correct? [Y/n]\n\nIf not, or if you would like\nto ammend your response type 'n'.\nResponse: ");
        scanf("%c", &responseB);
        getchar();
    } while (responseB != 'y' && responseB != 'Y');

    //Package logic
    char packageUpdate = 'y';
    
    if (askForPackages()) {

            while (packageUpdate != 'n' && packageUpdate != 'n') {
        
            printf("\nThank you...\n");

            foodOptionChoice = foodOption(); //Calling foodOption function to select food options
            foodCost = foodPrice(foodOptionChoice, numOfPeople);
            entertainmentOptionChoice = entertainmentOption();
            entertainmentCost = entertainmentPrice(entertainmentOptionChoice, numOfPeople, dayFactor);

            printf("Would you like to make any changes to your packages? [Y/n] ");
            scanf("%c", &packageUpdate);
            getchar();
        } 
    }
        
        else {
            foodCost = entertainmentCost = 0.0;
        }


    
    //Final Prompts
    totalCost = totalPrice(baseCost, foodCost, entertainmentCost);



    printf("\nFINAL EVENT SUMMARY:\n\n");

    printf("You are planning on hosting a %s.\n", eventString);
    printf("You are expecting %d guests at your event.\n", numOfPeople);
    printf("Your event is to be held on a %s.\n\n", dayString);

    printf("The base cost for your event is $%.2lf\nTotal food cost: $%.2lf\nTotal base entertainment cost: $%.2lf\n", baseCost, foodCost, entertainmentCost);
    printf("\nThe total estimated cost for %d guests amounts to: $%.2lf\n\n", numOfPeople, totalCost);
}