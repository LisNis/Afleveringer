/*
# for kvadratroden af akkumulatoren
% for at vende fortegnet af akkumulatoren
! for at dividere 1 med akkumulatoren
q for at afslutte regnemaskinen med slutresultatet
*/


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double calculator(double result, char operator,double tal);
double calculateUnaereOperationer(double result, char operator);
double calculateBinaereOperationer(double result, char operator, double tal);

int main() {
    double result = 0.0;
    char operator;
    double tal;

    calculator(result, operator, tal);

    return 0;
} // end main


double calculator(double result, char operator, double tal){
    printf("Result er: %.2lf\n", result);

    while (1) {
        printf("Indtast en operator (q, #, procenttegn, !) eller en operator (+, -, *, /) med et tal: ");
        scanf(" %c", &operator);

        if (operator == 'q' || operator == 'Q') {
            printf("Programmet blev afsluttet.\n");
            break;
        }
        
        if (operator == 33 || operator == 35 || operator == 37){
            result = calculateUnaereOperationer(result, operator);
        } else if (operator == 43 || operator == 45 || operator == 42 || operator == 92 || operator == 94) {
            scanf("%lf", &tal);
            result = calculateBinaereOperationer(result, operator, tal);
        } else {
            printf("Operatoren findes ikke, indtast +, -, *, /, eller q for at afslutte programmet.\n");
        } // end if/else

        printf("Det nye resultat: %.2lf\n", result);
    }// end while
} // end function

double calculateUnaereOperationer(double result, char operator) {
    switch (operator) {
        case '!':
            return 1 / result;
        case '%':
            return result * -1;
        case '#':
            return sqrt(result);
        default:
            return result;
    } // end switch
} // end function

double calculateBinaereOperationer(double result, char operator, double tal) {
    switch (operator) {
        case '+':
            return result + tal;
        case '-':
            return result - tal;
        case '*':
            return result * tal;
        case '^':
            return pow(result, tal);
        case '/':
            if (tal != 0) {
                return result / tal;
            } else {
                printf("Man kan ikke dividere med 0.\n");
                return result;
            }
        default:
            return result;
    }// end switch
} // end function
