//Lav en areal funktion (trap) med passende parametre
//• Lav en sum funktion – som modsvarer sigma (Σ) i formlen

#include <stdio.h>
#include <math.h>

double f(double x);
double sigma(int n, double a, double b);
double trap(int n, double a, double b);


int main() {
    double a, b;
    int n;

    printf("Enter the interval a, b: ");
    scanf("%lf %lf", &a, &b);

    printf("Enter the value of n (2,4,8,16,32,64,128): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("N must be greater than 0.\n");
        return 1;
    }

    double result = trap(n, a, b);

    printf("Arealet er: %.6lf\n", result);

    return 0;
} // end main


// functionen f
double f(double x) {
    if (x >= -2 && x <= 2) {
        return sqrt(4 - pow(x, 2));
    } else {
        return 0;
    } // a:-2, b:2, ellers nan
}


// beregner summen af funktionen
double sigma(int n, double a, double b){
    double h = (b - a) / n;
    printf("H er %lf\n", h);
    double sum = 0;
    for (int i = 1; i < n; i++){
        double x = a + i * h;
        sum = sum + f(x);
    }
    printf("Summen er: %lf\n", sum);
    return sum;
}

// beregner arealet
double trap(int n, double a, double b) {
    double h = (b - a) / n;
    double sum = sigma(n, a, b);
    double areal = h / 2 * (f(a) + 2 * sum + f(b));
    return areal;
}
