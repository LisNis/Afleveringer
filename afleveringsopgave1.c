#include<stdio.h>
#include<math.h>

/*Input fra User i sekunter, omregnet til uger, dage, timer, minuter og sekunter.*/
/*Jeg faar negative tal, hvis tallene er for stort? Er der en vej at ungaar det, har jeg gjort en fejl?
 * Eller er det bare ved c saadan? Nu da jeg har tilføjet et if statment, hvis tallet bliver for stort,
 * saa ser min code det ikke som et tal mere?*/

int main(void) {
    int sekunterUserInput;
    printf("Skriv et antal af sekunder: ");
    scanf("%d", &sekunterUserInput);

    // beregningen for programmet
    int sekunterIMinutet = 60;
    int sekunterITimen = sekunterIMinutet * 60;
    int sekunterIDagen = sekunterITimen * 24;
    int sekunterIUgen = sekunterIDagen * 7;

    if (sekunterUserInput > 0) {

        int uger = sekunterUserInput / sekunterIUgen;
        int sekunterRest = sekunterUserInput % sekunterIUgen;
        int dage = sekunterRest / sekunterIDagen;
        sekunterRest %= sekunterIDagen;
        int timer = sekunterRest / sekunterITimen;
        sekunterRest %= sekunterITimen;
        int minuter = sekunterRest / sekunterIMinutet;
        sekunterRest %= sekunterIMinutet;

        printf("Det svarer til %d uger, %d dage, %d timer, "
               "%d minuter og %d sekunter", uger, dage, timer, minuter, sekunterRest);

    // For at ungaar at programmet bryder sammen, hvis man intaster noget forkert
    } else { printf("Det input skal være et positivt tal");}
return 0;
}

