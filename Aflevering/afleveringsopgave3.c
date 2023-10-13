//Lav en areal funktion (trap) med passende parametre
//• Lav en sum funktion – som modsvarer sigma (Σ) i formlen

#include <stdio.h>
#include <math.h>

double f(double x);
double sum(int n, double x, double a, double b);

int main() {
    double a, b, x, result;
    int n;

    printf("Enter a: ");
    scanf("%lf", &a);
    printf("Enter b: ");
    scanf("%lf", &b);
    printf("Enter n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("n need to be a positive number.\n");
        return 1;
    }
    
    result = sum(n, x, a, b);
    printf("The areal of the integral is: %lf", result);

    return 0;
}


double f(double x) {
    return sqrt(4 - pow(x, 2));
}

double sum(int n, double x, double a, double b){
    double h = (b - a) / n;
    double sum = 0;
    for (int i = 1; i < n; i++){
        x = a + i * h;
        sum = sum + f(x);
    }
    double areal = h/2*(f(a) + 2 * sum + f(b));
    return areal;
}
