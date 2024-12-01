//Need a structure if you want to store multiple data types.

//These data types can be of different types. A user defined data type can be an 'int' type and 'char' type, or other combination, simultaiously

//Keyword struct

//Creating a structure creates a user defined data type.

//Proffesor first example...
/*
#include <stdio.h>

    //Initiate struct and assign its data types
    struct Student {
        
        int ID;
        float score;
        char Name[10];
    };

    void main() {

        struct Student s1; //Adds an 'element' 's1' to the structure.
        s1.ID = 1; //Assigns 'ID' data type
        strcpy(s1.Name, "Joe"); //Assigns 'Name' data type with string.

        s1.score = 95.5; //Assigns 'score' for s1
        
        printf("Student ID: %d.\nStudent Name: %s.\nStudent score: %.02f\n\n", s1.ID, s1.Name, s1.score); //Prints assignments to verify.
}
*/


//The code below uses loops to create, and store data in user created type
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

    //Initiate struct and assign its data types
    struct Student {
        
        int ID;
        //float score;
        char Name[10];
    };

    void main() {

        srand (time(NULL));

        char a = 0;

        struct Student s[100];

        for (int i = 0; i < 3; i++) {

            printf("Pleaese enter an ID number: ");
            scanf("%d", &s[i].ID);
            printf("Pleaese enter a name: ");
            scanf("%s", &s[i].Name); //Assigns 'Name' data type with string.

            //s[i].score = rand() % 100 + 1; //Assigns 'score' for s1            
        }

        for (int i = 0; i < 3; i++) {


            printf("\nStudent ID: %d.\nStudent Name: %s.\n", s[i].ID, s[i].Name); //, s[i].score);  //Prints assignments to verify. Student score: %.02f
        }

        printf("\n");


}
*/

//Searching through arrays
//Sequencial search
//Interval search

//Time is based on how many operations the program will execute (like engine hours)

//Sequential search looks for data one by one
//Interval search uses 'calculus' type method of cutting in half to find data. Data must be in order, otherwise interval serach will not function.

//Interval search function is refered to as 'binary search'

//Sorting data requires greater effort than searching for the data. Sorting is focus.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void main() {

    srand (time(NULL));

    int a[6];
    int find;
    int set;

    for (int i = 0; i < 6; i++) {

        a[i] = rand() % 100;
    }

    find = rand() % 50;
    set = 0;

    printf("Number to be found: %d.\n", find);
    printf("\n");

    printf("Array:\n");
    for (int i = 0; i < 6; i++) {

        printf("%d", a[i]);

        if (i < 5) {

            printf(", ");
        }
    }

    printf("\n\n");

    for (int i = 0; i < 6; i++) {

        if (a[i] == find) {

            printf("Number found at index %d.\n\n", i);
            set = 1;
            break;
        }

    }

    if (set == 0) {

        printf("Number not found.\n\n");
    }
}