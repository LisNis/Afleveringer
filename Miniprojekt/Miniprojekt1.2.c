/*
# for kvadratroden af akkumulatoren
% for at vende fortegnet af akkumulatoren
! for at dividere 1 med akkumulatoren
q for at afslutte regnemaskinen med slutresultatet
*/


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    double result = 0.0;
    char operator;
    double tal;

    printf("Result er: %.2lf\n", result);

    while (1) {
        printf("Indtast en operator (q, #, procenttegn, !) eller en operator (+, -, *, /) med et tal: ");
        scanf(" %c", &operator);

        if (operator == 'q' || operator == 'Q') {
            printf("Programmet blev afsluttet.\n");
            break;
        }

        if (operator == 33 || operator == 35 || operator == 37){
            switch (operator) {
                case '!':
                    result = 1 / result;
                    break;
                case '%':
                    result = result * -1;
                    break;
                case '#':
                    result = sqrt(result);
                    break;
            }
        } else if (operator == 43 || operator == 45 || operator == 42 || operator == 92 || operator == 94) {
            scanf("%lf", &tal);

            switch (operator) {
                case '+':
                    result = result + tal;
                    break;
                case '-':
                    result = result - tal;
                    break;
                case '*':
                    result = result * tal;
                    break;
                case '^':
                    result = pow(result, tal);
                    break;
                case '/':
                    if (tal != 0) {
                        result = result / tal;
                    } else {
                        printf("Man kan ikke dividere med 0.\n");
                    }
                    break;
            }// end switch
        } else {
            printf("Operatoren findes ikke, indtast +, -, *, /, eller q for at afslutte programmet.\n");
        } // end if/else

        printf("Det nye resultat: %.2lf\n", result);
    }// end while

    return 0;
} // end main
