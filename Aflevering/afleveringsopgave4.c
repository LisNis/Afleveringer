#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definition af kulør
enum Kuloer {
    Kloer, Ruder, Hjerter, Spar, Joker
};

// Definition af værdi
enum Vaerdi {
    Es, To, Tre, Fire, Fem, Seks, Syv, Otte, Ni, Ti, Knægt, Dame, Konge
};

// Definition af spillekort
struct Spillekort {
    enum Kuloer kuloer;
    enum Vaerdi vaerdi;
};

int sammenlign_kort(const void *a, const void *b);
void bland_kort(struct Spillekort kortstak[], int antal_kort);
void udskriv_kort(struct Spillekort kortstak[], int antal_kort);


int main() {
    // array af structs
    struct Spillekort kortstak[55];

    //  kortstakken
    for (int kuloer = Kloer; kuloer <= Spar; kuloer++) {
        for (int vaerdi = Es; vaerdi <= Konge; vaerdi++) {
            kortstak[kuloer * 13 + vaerdi].kuloer = kuloer;
            kortstak[kuloer * 13 + vaerdi].vaerdi = vaerdi;
        }
    }

    for (int i = 52; i < 55; i++) {
        kortstak[i].kuloer = Joker;
        kortstak[i].vaerdi = -1; // -1 repræsenterer jokere
    }

    srand(time(NULL));
    bland_kort(kortstak, 55);

    printf("Tilfældigt blandede kort:\n");
    udskriv_kort(kortstak, 55);

    qsort(kortstak, 55, sizeof(struct Spillekort), sammenlign_kort);

    printf("\nSorterede kort:\n");
    udskriv_kort(kortstak, 55);

    return 0;
}

// Sammenligningsfunktion til qsort
int sammenlign_kort(const void *a, const void *b) {
    struct Spillekort *kortA = (struct Spillekort *)a;
    struct Spillekort *kortB = (struct Spillekort *)b;

    // Sortér
    if (kortA->kuloer < kortB->kuloer) return -1;
    if (kortA->kuloer > kortB->kuloer) return 1;
    if (kortA->vaerdi < kortB->vaerdi) return -1;
    if (kortA->vaerdi > kortB->vaerdi) return 1;
    return 0;
}

// Blande kortene tilfældigt
void bland_kort(struct Spillekort kortstak[], int antal_kort) {
    for (int i = 0; i < antal_kort; i++) {
        int random_index = rand() % antal_kort;
        struct Spillekort midlertidigt = kortstak[i];
        kortstak[i] = kortstak[random_index];
        kortstak[random_index] = midlertidigt;
    }
}

// Udskrive kortene
void udskriv_kort(struct Spillekort kortstak[], int antal_kort) {
    for (int i = 0; i < antal_kort; i++) {
        printf("Kulør: %d, Værdi: %d\n", kortstak[i].kuloer, kortstak[i].vaerdi);
    }
}
