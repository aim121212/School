//Default Template
#include <stdio.h>

int main () {

    int x=5;
    int y;
    int product;

    //Function to print on the screen.
    printf("Please enter an integer value: ");

    //Function to receive user input.
    scanf("%d", &y);

    //Function to add x and y values.
    product=x*y;

    //Function to print sum.
    printf("The product of x and y is: %d.", product);

return 0;
}