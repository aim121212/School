#include <stdio.h>

int main () {

    int a;
    int out = 5;
    
    printf("Please enter a number: ");
    scanf("%d", &a);
    
    for (a; a <= 10; (a = a + 1)) {

        printf("%d\n", out);
        out++;
    }

return 0;
}