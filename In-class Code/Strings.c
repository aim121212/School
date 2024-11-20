/*

#include <stdio.h>

void main() {

    char firstName[20];
    int counter = 0;
    int i = 0;

    printf("Please enter first name: ");
    scanf("%s", &firstName);

    printf("\nUser's first name is: %s\n\n", firstName);

    while (firstName[i] != NULL) {
        counter++;
        i++;
    }

    printf("\nThe character length in the user's first name is: %d.\n\n", counter);
}

*/

/*

#include <stdio.h>

void main() {

    char firstName[20];
    int counter = 0;
    int i = 0;

    printf("Please enter first name: ");
    scanf("%s", &firstName);

    printf("\nUser's first name is: %s\n\n", firstName);

    for (i = 0; i < sizeof(firstName); i++) {

        if (firstName[i] == '\0') {
            break;
        }
    }

    printf("\nThe character length in the user's first name is: %d.\n\n", i);
}

*/

/*

#include <stdio.h>

void main() {

    char firstName[20];
    int counter = 0;
    int i = 0;

    printf("Please enter first name: ");
    gets(firstName);

    puts("The input string is:");
    puts(firstName);

    for (i = 0; i < sizeof(firstName); i++) {

        if (firstName[i] == '\0') {
            break;
        }
    }

    printf("The string length is: %d.\n\n", i);
}

*/

/*

#include <stdio.h>

void main() {

    char firstName[20];
    int counter = 0;
    int i;

    printf("Please enter first name: ");
    scanf("%s", &firstName);

    printf("\nUser's first name is: %s\n\n", firstName);

    for (i = 0; i < firstName; i++) {

        if (firstName[i] == ('a' || 'e' || 'i' || 'o' || 'u')) {
        
            counter++;
        }
    }

    printf("\nThe amount of vowels in the string is: %d.\n\n", counter);
}

*/

/*


#include <stdio.h>
#include <string.h>

void main() {

    char str1[20];
    char str2[20];

    printf("Please enter a string of characters: ");
    scanf(" %s", &str1);
    printf("\nThe string entered is: %s\n\n", str1);

    strcpy(str2, str1);
    printf("The copied string is shown here:\n%s\n\n.", str2);

}

*/

#include <stdio.h>

void main() {

    char character;
    char string[20];
    int counter = 0;
    int i;

    printf("Please enter a character: ");
    scanf("%c", &character);

    printf("Please enter a character string: ");
    scanf(" %s", &string);

    for (i = 0; i < 20; i++) {

        if (string[i] == 'b') {

            counter++;
        }

        else if (string[i] == '\0') {

            break;
        }
    }

    printf("\nThe amount of %c's is %d.\n\n", character, counter);

}