#include <stdio.h>

// Switch function to determine price based on the type of event
// User enters one of the character value
// Switch statement checks input and outputs the choosen event with its price
// If input is invalid it returns -1
int eventType(char userInput) {
    switch (userInput) {
        case 'W': // Wedding
            return 10000;
        case 'Q': // Quinceanera
            return 8000;
        case 'B': // Special Birthday
            return 6000;
        case 'S': // Baby Shower
            return 5000;
        default:
            return -1; // Invalid event
    }
}

// Function checks the capacity from input does not exceed max capacity
// Compares people attending from input with max capacity
// Error is printed if input exceeds, returns 0
// If capacity is valid it returns 1
int verifyCapacity(int inputsAttendees, int maxCapacity) {
    if (inputsAttendees > maxCapacity) {
        printf("The number of attendees surpasses the max capacity of %d.\n", maxCapacity);
        printf("Venue Unavailable. \n");
        return 0; // Indicating capacity is surpassed max capacity
    }
    return 1; // Input capacity is valid
}
int main() {
    char userInput;                 // Input's event type
    int inputsAttendees;            // Input's attendees attending
    const int maxCapacity = 500;    // Max capacity limit
    int price;                      // Pirce stored based on event type


// Introduction to venue choosing
// input selects venue event type
// Scans input's event type
    printf("Welcome to the Venue Event Options!\n");
    printf("Please select the type of Event for the venue: \n");
    printf("W - Wedding\nQ - Quinceanera\nB - Special Birthday\nS - Baby Shower\n");
    printf("Enter your choice: ");
    scanf(" %c", &userInput);

    // Recalls event type's price
    // If event type is invalid the program exits
    // Else, prints out events price
        price = eventType(userInput);

    if (price == -1) {
        printf("Event type is invalid.\n");
        printf("Exiting program.\n");
        return 1;
    }

    printf("Price for desired event is $%d.\n", price);

    // Asks user to input total attendees for the event
    // Scans user's input of attendees
    // while loop to force user to input a valid number of attendees to suit the capacity
    while (1) {
        printf("Enter the number of people attending: ");
        scanf("%d", &inputsAttendees);

        if (verifyCapacity(inputsAttendees, maxCapacity)) {
            break;
        } else {
            printf("The number of attendees surpasses the max capacity. Please enter a valid number of attendees.\n");
        }
    }

// Concluding message to indicate program succeeded and user's venue is booked
    printf("Venue event has been book with %d attendees. \n",inputsAttendees);
    printf("Total price is $%d.\n", price);

    return 0;
}