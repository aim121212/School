/*
#include <stdio.h>

void main() {

    int x; //Variable
    int *p; //Creates the pointer
    p = &x; //Assigns address

    scanf("%d", &x);

    printf("The address is: %x\n", p);
    printf("The value at this address is: %d", *p);

}
*/

/*
//p++ will increase pointer depending on the type of pointer

#include    <stdio.h>

void main() {

    int
    int
    int


}
*/

/*

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {

    srand (time(NULL));

    int *p;
    int *q;
    int a;
    int b;
    int sum;

   /* 
    scanf("%d", &a);
    scanf("%d", &b);
    *//*

    a = rand() % 100 + 1;
    b = rand() % 100 + 1;

    p = &a;
    q = &b;

    // sum = *p + *q;

    printf("The addresses of the pointers are: %x and %x.\n", p, q);
    printf("The values at these addresses are: %d and %d.\n", *p, *q);
    // printf("The sum of the values is: %d.\n\n", sum);
    printf("The sum of the values is: %d.\n\n", (*p + *q));

}

*/

/*

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {

    int *p;
    int *q;
    
    int a;
    int b;

    srand (time(NULL));

    //a = rand() % 10 + 1;
    //b = rand() % 10 + 1;

    a = 2;
    b = 3;

    p = &a;
    q = &b;

    printf("The addresses of the pointers are: %x and %x.\n", p, q);
    printf("The values at these addresses are: %d and %d.\n", *p, *q);
    
    char response;

    printf("Swap the values? [Y/n]: ");
    scanf("%c", &response);

    if (response == 'Y' || 'y') {

        int temp;

        b = temp;
        a = b;        

        printf("The swapped values are: %d and %d.\n\n", (*p + *q));
    }

    else {
        printf("Program will now exit.\n");
    }
}

*/

//November 20th

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {

    srand (time(NULL));

    int a[5];
    int * pointer;

    for (int i = 0; i < 5; i++) {
    a[i] = rand() % 7 + 1;
    }

    printf("Values:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d\n", a[i]);
    }

    printf("\nResult using &a is %d.\n", &a);
    printf("Result using a is %d.\n", a);
    printf("Result using &a[0] is %d.\n", &a[0]);

    printf("\nResult using &a + 1 is %d.\n", &a + 1);
    printf("Result using a + 1 is %d.\n", a + 1);
    printf("Result using &a[0] + 1 is %d.\n", &a[0] + 1);

    printf("\nUsiing pointers:\n");
    for (int i = 0; i < 5; i++) {

    pointer = &a[i];

        printf("\nCurrent index is %d.\n", i);
        printf("Result using value is %d.\n", a[i]);
        printf("Result using pointer is %d.\n", *pointer);
        printf("Address: %x\n", pointer);
    }

    printf("\nProfessor's version:");
    for (int i = 0; i < 5; i++) {

        pointer = &a[i];

        printf("\nThe index %d, value is %d, the address in hexadecimal is %x, the address in decimal is %d.", i, *pointer, pointer, pointer);
    }
}