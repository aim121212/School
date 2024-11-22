#include <stdio.h>
#include <string.h>

// Function prototypes
int askForPackages(); //ALicia
void venuePackages(char typeOfEvent, int numOfPeople); //Alicia
int foodOption(); //Alicia
int foodPrice(int foodOption, int numPeople); //ALicia
int entertainmentOption(); //Alicia 
double entertainmentPrice(int entertainmentOption);//Alicia
double BasePrice(char typeOfEvent); 
double totalPrice(double basePrice, double foodCost, double entertainmentCost);

// Functions

int askForPackages() {
    char option[10];
    printf("Would you like to see our available packages for your event?\n");
    printf("You can enhance your experience with food and entertainment packages.\n\n");
    printf("Please type 'yes' or 'no':\n");

        
        
        while(getchar() != '\n');
        
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

int capacityFunction() {
    int numOfPeople = 0;
    printf("How many guests do you expect to have at your event? (Max capacity: 500)\n");
    scanf("%d", &numOfPeople);

    while (numOfPeople > 500 || numOfPeople < 1) {
        printf("Invalid entry. Enter a number between 1 and 500: ");
        scanf("%d", &numOfPeople);
    }
    printf("You are expecting %d guests.\n", numOfPeople);
    return numOfPeople;
}


int foodOption() {
    int foodOption;
    printf("\nYou have the option to secure catering from our venue's trusted partners or you may select to provide your own.\n");
            printf("Our venue typically works with two prominent catering services in the area, both are of equal quality, but have different menus.\n");
            printf("Please review their menus, or select your own service and let us know your decision by making a selection in the following prompts.\n\n");
            printf("Please make a selection from the list below:\n");

    printf("\nSelect a catering option:\n");
    
    printf("1 - Venue Caterer 1: Italian Food\n");
    printf("2 - Venue Caterer 2: Mexican Food\n");
    printf("3 - Client-provided catering\n");
    printf("Enter your choice: ");
    scanf("%d", &foodOption);

    while (foodOption < 1 || foodOption > 3) {
        printf("Invalid choice. Enter 1, 2, or 3: ");
        scanf("%d", &foodOption);
    }
    printf("You chose option %d.\n", foodOption);
    return foodOption;
}

int foodPrice(int foodOption, int numPeople) {
    int menuChoice, pricePerPlate = 0;
    if (foodOption == 1) {
        printf("Caterer 1 Menu:\n");
        printf("1 - Spaghetti and Meatballs ($20/plate)\n");
        printf("2 - Fettuccine Alfredo ($20/plate)\n");
        printf("3 - Italian Buffet ($30/plate)\n");
        printf("Enter your choice: ");
        scanf("%d", &menuChoice);

        if (menuChoice >= 1 && menuChoice <= 2){
            pricePerPlate = 20;
        }
        else if (menuChoice == 3){
             pricePerPlate = 30;
        }
        else {
            return -1; // Invalid choice
        }
    } else if (foodOption == 2) {
        printf("Caterer 2 Menu:\n");
        printf("1 - Flautas ($20/plate)\n");
        printf("2 - Tacos ($20/plate)\n");
        printf("3 - Mexican Buffet ($30/plate)\n");
        printf("Enter your choice: ");
        scanf("%d", &menuChoice);

        if (menuChoice >= 1 && menuChoice <= 2){
        pricePerPlate = 20;
        }
        else if (menuChoice == 3){
             pricePerPlate = 30;
        }
        else {
            return -1; // Invalid choice
        }
    }
    return numPeople * pricePerPlate;
}

int entertainmentOption() {
    int entertainmentOption;
    printf("\nEntertainment Options:\n");
    printf("1 - DJ 1\n");
    printf("2 - DJ 2\n");
    printf("3 - Client-provided entertainment\n");
    printf("Enter your choice: ");
    scanf("%d", &entertainmentOption);

    while (entertainmentOption < 1 || entertainmentOption > 3) {
        printf("Invalid choice. Enter 1, 2, or 3: ");
        scanf("%d", &entertainmentOption);
    }
    printf("You chose option %d.\n", entertainmentOption);
    return entertainmentOption;
}

double entertainmentPrice(int entertainmentOption) {
    return (entertainmentOption == 1 || entertainmentOption == 2) ? 500.0 : 0.0;
}

double BasePrice(char typeOfEvent) {
    switch (typeOfEvent) {
        case 'W': case 'w': return 3000.0;
        case 'Q': case 'q': return 1500.0;
        case 'B': case 'b': return 1000.0;
        case 'S': case 's': return 2000.0;
        default: return 2000.0;
    }
}

double totalPrice(double basePrice, double foodCost, double entertainmentCost) {
    return basePrice + foodCost + entertainmentCost;
}

int main() {
    char typeOfEvent;
    int numOfPeople;
    int foodOptionChoice;
    int entertainmentOptionChoice;
    double baseCost;
    double foodCost;
    double entertainmentCost;
    double totalCost;

    printf("Welcome User!\n");
    printf("Thank you for choosing ADK for your event's venue.\n\n");
    printf("The following program wil help you plan and book your event with us.\n");
    printf("You will be asked to provide various information.\nOnce finalized, a detailed summary");
    printf(" of your event and corresponding quote will be generated for your review.\n\n");
    printf("Our venue has a capacity of 500 attendees.\n\n");

    //ask user for event type
    printf("Please choose an option for the type of event you are hosting from the \nlist below:\n\n");
    printf("Enter event type:\n");
    printf("W - Wedding\nQ - Quinceañera\nB - Baby Shower\nS - Special Event\n ");
    printf("\n");
    scanf(" %c", &typeOfEvent);
    getchar();

    baseCost = BasePrice(typeOfEvent);

    numOfPeople = capacityFunction();
    printf("\n");

    if (askForPackages()) {
       
        foodOptionChoice = foodOption();
        foodCost = foodPrice(foodOptionChoice, numOfPeople);
        entertainmentOptionChoice = entertainmentOption();
        entertainmentCost = entertainmentPrice(entertainmentOptionChoice);
    } else {
        foodCost = entertainmentCost = 0.0;
    }

    totalCost = totalPrice(baseCost, foodCost, entertainmentCost);
    printf("\nEvent Summary:\n");
    printf("Base Price: $%.2lf\nFood Cost: $%.2lf\nEntertainment Cost: $%.2lf\n", baseCost, foodCost, entertainmentCost);
    printf("Total Estimated Cost: $%.2lf\n", totalCost);

    return 0;
}
