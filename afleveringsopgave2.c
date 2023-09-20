#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Et program der finder gcd af to positive tal

int main(void)
{
    int numberA, numberB, gcd;

    printf("Please enter two numbers, a and b: ");
    scanf("%d %d", &numberA, &numberB);

    // A skal være større end eller lige B, og begge skal være positive
    if (numberA >= numberB && numberB > 0){
        printf("a: %d og b: %d \n", numberA, numberB);

        for (int i = 1; i <= numberA; ++i) {
            if (numberA % i == 0 && numberB % i == 0) {
                gcd = i;
            }
        }printf("The gcd of the numbers a and b is: %d", gcd);

    }else {
        printf("A need to be greater than or equal to B and they need to be two positive numbers");
    }

    return 0;
}
