//Lav en areal funktion (trap) med passende parametre
//• Lav en sum funktion – som modsvarer sigma (Σ) i formlen

#include <stdio.h>
#include <math.h>

//int sum(int n, double h);

int main(void) {
    double a = -2;
    double b = 2;

    int num = 7;
    int n = 2;
    int sum = 1;

    for (int i = 0; i < num; i++) {
        sum = sum * n;
        printf("N is %d \n", sum);

        //double nummer = sum-1;
        //double summevonh = h * nummer;
        //printf("Summe von h is %lf \n\n", summevonh);
    }// end for
    double h = (b - a) / sum;
    printf("H is %lf\n", h);

    //sum(n, h);
    double final = 0;

    for (int i = 1; i <= n - 1; i++) {
        double summe = h * i;
        double resultat = sqrt(4 - pow(summe, 2));
        printf("Die %d summe ist %lf\n", i, summe);
        printf("Das %i resultat ist %lf\n", i, resultat);
        final = final + resultat;
        printf("Das finale resultat ist %lf\n", final);
    } // end for
    double funktionA = sqrt(4 - pow(a, 2));
    printf("Funktionen af A er %lf\n", funktionA);
    double funktionB = sqrt(4 - pow(b, 2));
    printf("Funktionen af B er %lf\n", funktionB);

    double T = h / 2 * (funktionA + funktionB) + 2 * final;

    //double summeFunktion = sqrt(4- pow(h, 2));
    //printf("Summen af funktionen er %lf\n", summeFunktion);
    //
    //double T = h/2 * (funktionA + funktionB) + (2 * summeFunktion);

    printf("T is %lf", T);
}// end main


//int sum(int n, double h){
//    
//    }return final;
//    
//}
