
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){

    char input[10];
    int i = 0;
    double result = 0.0;
    double resultNeu = 0.0;
    char lasop = '?';
    char currentchar;

    bool stopnow = flase;

while !stopnow
    {
        printf("Input eingeben: ");
        scanf("%s", &input);
        printf("Eingabe: %s \n", input);

        int lenstr = strlen(input);
        printf("%d \n", lenstr);

        while (i < lenstr) {
            printf("Lasop: %c \n", lasop);
            if (input[i] < 58 && input[i] > 47) { // 0-9
                resultNeu = 10 * resultNeu + input[i] - 48;
                if (lasop != '?')
                    switch (lasop) {
                        case '+':
                            lasop = '?';
                            resultNeu = result + resultNeu;
                            break;
                    } // end switch
            } else {
                switch (input[i]) {
                    case (43): // +
                        lasop = '+';
                        result = resultNeu;
                        resultNeu = 0.0;
                        break;
                    case (44): // -

                        break;
                    case (45): // *

                        break;
                    case (46): // /

                        break;
                    case (47): // #

                        break;
                    case (48): // !

                        break;
                    case (49): // %

                        break;
                    case (50): // q

                        stopnow = true;
                }  // switch
            } // else

            i = i + 1;
        }// end while
        result = resultNeu;
        printf("Das ergebnis ist: %f", result);
    } // stopnow
} // end main
