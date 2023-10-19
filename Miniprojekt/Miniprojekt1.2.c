#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "calculator.h"

int main(void) {
    int i = 0;
    char lastop = '?';
    char input[10];
    double result = 0.0;
    double resultNeu = 0.0;

    printf("Giv et input, resultet er: %lf >", result);
    do {
        scanf("%s", &input);
        printf("Inputet: %s \n", input);

        int lenstr = strlen(input);
        printf("Length: %d \n", lenstr);

            printf("Lasop: %c \n", lastop);
            if (input[i] < 58 && input[i] > 47) { // 0-9
                resultNeu = 10 * resultNeu + input[i] - 48;

            } else {
                switch (input[i]) {
                    case (43): // +
                        lastop = '+';
                        result = resultNeu;
                        resultNeu = 0.0;
                        break;
                    case (45): // -
                        lastop = '-';
                        result = resultNeu;
                        resultNeu = 0.0;
                        break;
                    case (42): // *
                        lastop = '*';
                        result = resultNeu;
                        resultNeu = 0.0;
                        break;
                    case (47): // /
                        lastop = '/';
                        result = resultNeu;
                        resultNeu = 0.0;
                        break;
                    case (35): // #
                        lastop = '#';
                        result = resultNeu;
                        resultNeu = 0.0;
                        break;
                    case (33): // !
                        lastop = '!';
                        result = resultNeu;
                        resultNeu = 0.0;
                        break;
                    case (37): // %
                        lastop = '%';
                        result = resultNeu;
                        resultNeu = 0.0;
                        break;
                    case (113): // q
                        lastop = 'q';
                        break;
                }// end switch
            }// end else

        result = resultNeu;
        printf("Giv et input, result er: %lf >", result);

    } // end do
    while(lastop != 'q');

    return 0;
} // end main
