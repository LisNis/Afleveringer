#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

int main(){

    char input[10];
    int i = 0;
    double result = 0.0;
    double resultNeu = 0.0;
    char lasop = '?';
    char currentchar;

    bool stopnow = false;

//while !stopnow
   // {
        printf("Input eingeben: ");
        scanf("%s", &input);
        printf("Eingabe: %s \n", input);

        int lenstr = strlen(input);
        printf("Length: %d \n", lenstr);
        while (i < lenstr) {
            printf("Lasop: %c \n", lasop);
            if (input[i] < 58 && input[i] > 47) { // 0-9
                resultNeu = 10 * resultNeu + input[i] - 48;
                if (lasop != '?')
                    switch (lasop) {
                        case '+': //+
                            lasop = '?';
                            resultNeu = result + resultNeu;
                            break;
                        case '-': // -
                            lasop = '?';
                            resultNeu = result - resultNeu;
                            break;
                        case '*': // *
                            lasop = '?';
                            resultNeu = result * resultNeu;
                            break;
                        case '/': // /
                            lasop = '?';
                            resultNeu = result / resultNeu;
                            break;

                    } // end switch
            } else {
                switch (input[i]) {
                    case (43): // +
                        lasop = '+';
                        result = resultNeu;
                        resultNeu = 0.0;
                        break;
                    case (45): // -
                        lasop = '-';
                        result = resultNeu;
                        resultNeu = 0.0;
                        break;
                    case (42): // *
                        lasop = '*';
                        result = resultNeu;
                        resultNeu = 0.0;
                        break;
                    case (47): // /
                        lasop = '/';
                        result = resultNeu;
                        resultNeu = 0.0;
                        break;
                    case (35): // #
                        lasop = '#';
                        result = resultNeu;
                        resultNeu = 0.0;
                        break;
                    case (33): // !
                        lasop = '!';
                        result = resultNeu;
                        resultNeu = 0.0;
                        break;
                    case (37): // %
                        lasop = '%';
                        result = resultNeu;
                        resultNeu = 0.0;
                        break;
                    case (113): // q
                        lasop = 'q';
                        stopnow = true;
                        break;

                        //stopnow = true;
                }  // switch
            } // else

            i = i + 1;
        }// end while
        //if (lasop = '?') { if funktioniert nicht
    //            result = resultNeu;
    //        }
        printf("Das ergebnis ist: %f", result);
        // } // stopnow


} // end main
