#include <stdio.h>
#include <math.h>

double f(double x);
double g(double x);
void sigma(int n, double a, double b, double *sum_f, double *sum_g);
double trap(int n, double a, double b, double *sum_f, double *sum_g);


int main() {
    double a, b;
    int n;

    printf("Enter the interval [a, b]: ");
    scanf("%lf %lf", &a, &b);

    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid value of n. It must be greater than 0.\n");
        return 1;
    }

    double sum_f, sum_g;
    trap(n, a, b, &sum_f, &sum_g);

    printf("Approximate area under the curve (f(x)): %.6lf\n", sum_f);
    printf("Approximate area under the curve (g(x)): %.6lf\n", sum_g);

    return 0;
}

// Funktion f(x)
double f(double x) {
    if (x >= -2 && x <= 2) {
        return sqrt(4 - pow(x, 2));
    } else {
        return 0.0;
    }
}

// Funktion g(x)
double g(double x) {
   return pow(x, 2) * sin(x);
}

// beregner summen af funktionerne
void sigma(int n, double a, double b, double *sum_f, double *sum_g) {
    double h = (b - a) / n;
    *sum_f = 0;
    *sum_g = 0;
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        *sum_f += f(x);
        *sum_g += g(x);
    }
}

// beregner arealet
double trap(int n, double a, double b, double *sum_f, double *sum_g) {
    double h = (b - a) / n;
    sigma(n, a, b, sum_f, sum_g);
    double areal_f = h / 2 * (f(a) + 2 * (*sum_f) + f(b));
    double areal_g = h / 2 * (g(a) + 2 * (*sum_g) + g(b));
    return areal_f + areal_g;
}
