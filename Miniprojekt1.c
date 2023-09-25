#include <stdio.h>
#include <math.h>
#include "calculator.h"


int main(void) {
    char operator;
    double inputNumber;
    double result = 0;

    printf("Resultetet er = %lf > ", result);

    do {
        scanf(" %c %lf", &operator, &inputNumber);

        if(operator == '+'){
            result = result + inputNumber;
            printf("The result is %lf > ", result);
        }else if(operator == '-'){
            result = result - inputNumber;
            printf("The result is %lf > ", result);
        }else if(operator == '*'){
            result = result * inputNumber;
            printf("The result is %lf > ", result);
        }else if(operator == '/') {
            result = result / inputNumber;
            printf("The result is %lf > ", result);
        }else if(operator == '#') {
            result = sqrt(result);
            printf("The result is %lf > ", result);
        }else if(operator == '%') {
            result = result * -1;
            printf("The result is %lf > ", result);
        }else if(operator == '!') {
            result = 1 / result;
            printf("The result is %lf > ", result);
        }

    } while (operator != 'q');
      
    return 0;  
}
