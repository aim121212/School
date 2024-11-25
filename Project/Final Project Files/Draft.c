    #include <stdio.h>
    #include <string.h>

        //Function prototypes

        // Alicia's task
        int askForPackages (); //Defined, prompts user to show package options
        void venuePackages(char typeOfEvent, int numOfPeople); // add calls for functions below
        int foodOption(); //Needs to be defined, will give user 3 food package options or will allow for catering from an outside entity at a competitive fee
            //double foodPrice(int foodOption, int numOfPeople);
        int entertainmentOption(); //Needs to be defined
            // double entertainmentPrice (int entertainmentOption);

        //Kevin's task
        double BasePrice(char typeOfEvent); //Defined, depending on the event the price will change *removed from main function, changed to double to show decimals*
        int capacityFunction ();  // Defined, as the function to validate number of people

        //Daniels
        double totalPrice(double basePrice, double foodPrice, double entertainmentPrice); //Need to define as the sum of base price, expected atendee rate, food otion selection, and additional rates
        // make the day function: 
            /* quinces and weddings are only allowed on fridays and saturdays.
                The rest of the events are allowed on friday saturday and sundays.
                the days can be determined by numbers: 1 for friday, 2 saturday etc (or whatever works)
                
                

        //Functions
        
        int askForPackages() {
            
            char option[10];

            printf("Would you like to see our available packages for your event?\n");
            printf("Type yes or no:\n");

            // Read user input
            while (1) {

                fgets(option, sizeof(option), stdin);
                option[strcspn(option, "\n")] = '\0';

                if (strcmp(option, "yes") == 0) {
                    return 1;
                }
            
                else if (strcmp(option, "no") == 0) {
                    return 0;
                }
            
                else {
                    printf("Invalid choice: please enter yes or no:\n");
                }
            }
        }

        int capacityFunction() {

            int numOfPeople = 0;

            printf("How many guests do you expect to have at your event?.\n");
            printf("Please note, the capacity of this venue is limited to 500 attendees.\n\n");

            printf("Please enter the a value for the number of people you expect to attend: ");
            scanf("%d", &numOfPeople);
        

            if ((numOfPeople > 500) || (numOfPeople < 1)) {
                printf("Sorry, we can only accommodate up to 500 people.\n");
                printf("Please enter a valid entry: ");
                scanf("%d", &numOfPeople);
            }
            
            else {

                printf("Thank you, you are expecting about %d guests at your event.\n\n", numOfPeople);
            }
        
        return numOfPeople;
        }

        int foodOption() {
            
            int foodOption;

            printf("\nYou have the option to secure catering from our venue's trusted partners or you may select to provide your own.\n");
            printf("Our venue typically works with two prominent catering services in the area, both are of equal quality, but have different menus.\n");
            printf("Please review their menus, or select your own service and let us know your decision by making a selection in the following prompts.\n\n");
            printf("Please make a selection from the list below, using the corresponding number (e.g., '1' for option one)");

            printf("\n0 - Review Menus\n1 - Select venue caterer 1\n2 - Select venue caterer 2\n3 - Catering to be provided by client");

            printf("\nEnter selection: ");
            scanf(" %d", &foodOption);

            while (foodOption == 0) {

                printf("Menu 'A' and 'B' for your review...\n\nPlease enter your selection for catering, if you are unsure, please select option '3' for now.\n");
                printf("Catering selection: ");
                scanf("%d", &foodOption);
            }

            printf("\nThank you from making your selection, you chose option %d.\n\n", foodOption);

        return foodOption;            
        }
    

        int entertainmentOption() {
            
            int entertainmentOption;

            printf("\nYou have the option to secure entertainment (a D.J.) from one of our venue's trusted partners or you may select to provide your own.\n");
            printf("Our venue typically works with two prominent D.J.'s in the area, both are of equal quality, but play different generes.\n");
            printf("Please review their song lists, or select your own service and let us know your decision by making a selection in the following prompts.\n\n");
            printf("Please make a selection from the list below, using the corresponding number (e.g., '1' for option one)");

            printf("\n0 - Song Lists\n1 - Select D.J. 1\n2 - Select D.J. 2\n3 - Entertainment to be provided by client");

            printf("\nEnter selection: ");
            scanf(" %d", &entertainmentOption);

            while (entertainmentOption == 0) {

                printf("Song lists from D.J. '1' and '2' for your review...\n\nPlease enter your selection for catering, if you are unsure, please select option '3' for now.\n");
                printf("Entertainment selection: ");
                scanf("%d", &entertainmentOption);
            }

            printf("\nThank you from making your selection, you chose option %d.\n\n", entertainmentOption);

        return entertainmentOption;            
        }

        double BasePrice(char typeOfEvent) { //Base price is executed based on typeOfEvent selection

            double basePrice;

            switch (typeOfEvent) {

                case 'w':
                case 'W':
                    basePrice = 3000.00; // Wedding base price
                    break;
                case 'q':
                case 'Q':
                    basePrice = 1500.00; // Quinceañera base price
                    break;
                case 'b':
                case 'B':
                    basePrice = 1000.00; // Baby Shower base price
                    break;
                case 's':
                case 'S':
                    basePrice = 2000.00; // Special Event base price
                    break;
                default:
                    basePrice = 1000.00; // Default
                    printf("Invalid event type entered. Using default base pricing for 'Special Event'.");
                }
            
            return (basePrice);
        }

        double foodPrice(int foodOption, int numOfPeople);
        
        double entertainmentPrice (int entertainmentOption);
        
        double totalPrice(double basePrice, double foodPrice, double entertainmentPrice);

        void venuePackages(char typeOfEvent, int numOfPeople) {
            printf("Packages for the event will be displayed here.\n");
        }



        int main() {

            int day = 1; //need to incorporate, usingg '1' for now.
            int foodSelection;
            int entertainmentSelection;
            int numOfPeople;
            char typeOfEvent;
            char TypeOfEvent[20];
            double basePrice;

            // Home page of the venue website
            printf("Welcome User!\n");
            printf("Thank you for choosing ADK for your event's venue.\n\n");
            printf("The following program will help you plan and book your event with us.\n");
            printf("You will be asked to provide various information. Once finalized, a detailed summary\n");
            printf("of your event and corresponding quote will be generated for your review.\n\n");

            
            // Ask user for event type
            printf("Please choose an option for the type of event you are hosting from the list below:\n");
            printf("\tW - Wedding\n");
            printf("\tQ - Quinceañera\n");
            printf("\tB - Baby Shower\n");
            printf("\tS - Special Event\n");
            printf("\n");

            // Read user's choice for event type
            printf("Enter event type (letter only): ");
            scanf(" %c", &typeOfEvent);
            getchar();

            switch (typeOfEvent) {

                case 'w':
                case 'W':
                    strcpy(TypeOfEvent, "Wedding");
                    break;
                case 'q':
                case 'Q':
                    strcpy(TypeOfEvent, "Quinceañera");
                    break;
                case 'b':
                case 'B':
                    strcpy(TypeOfEvent, "Baby Shower");
                    break;
                case 's':
                case 'S':
                    strcpy(TypeOfEvent, "Special Event");
                    break;
                default:
                    strcpy(TypeOfEvent, "Special Event");;
                    printf("Invalid event type entered. Using default 'Special Event' type.\n");
                    break; 
            }
            
            printf("\nThe selected type of event is a, %s.\n\n", TypeOfEvent);
            
            // Call capacity function to get number of people attending
            numOfPeople = capacityFunction();

            // Call the BasePrice function based on the event type
            basePrice = BasePrice(typeOfEvent); // Get base price for selected event

            foodSelection = foodOption();

            entertainmentSelection = entertainmentOption(); //Need use entertainment function.

            // Ask if the user wants to see packages
            int result = askForPackages();

            if (result == 1) {
                printf("\nYou chose to see the packages.\n");
                venuePackages(typeOfEvent, numOfPeople);

                // Prints a summary of the event, according to the number of people, food selection and 
                printf("\nYour event is for a %s, you expect %d people to attend.\n", TypeOfEvent, numOfPeople);
                printf("Your event is going to occur on day %d.\n\n", day); //Need to implement this part from other file.
                printf("You selected option %d for your catering, and option %d for your entertainment.\n", foodSelection, entertainmentSelection);
                printf("The estimated cost for this event is: %.02lf.\n", BasePrice(typeOfEvent));

                // Calculate and show total price (implement pricing logic)
                // You would need to add logic to calculate total price here based on `basePrice`, packages, and number of people.

            }
            
            else {
                
                printf("You chose not to see the packages.\nProgram will now end.");
            }

        return 0;
        }

