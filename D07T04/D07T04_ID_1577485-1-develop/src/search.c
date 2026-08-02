#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
double mean(const int *a, int n);
double variance(const int *a, int n);
int filter(const int *a, int n);

int main() {
    int n, data[NMAX];

    if (input(data, &n) == 1) {
        printf("%d", filter(data, n));
    } else
        printf("n/a");
    return 0;
}

int input(int *a, int *n) {
    int status = 1;
    if (scanf("%d", n) != 1 || *n > NMAX || *n <= 0) status = 0;
    for (int *p = a; p - a < *n && status; p++)
        if (scanf("%d", p) != 1) status = 0;
    return status;
}

double mean(const int *a, int n) {
    double sum = 0.0;
    for (const int *p = a; p - a < n; p++) sum += *p;
    return sum / n;
}

double variance(const int *a, int n) {
    double sum_squares = 0.0;
    double avg = mean(a, n);
    for (const int *p = a; p - a < n; p++) sum_squares += (*p - avg) * (*p - avg);
    return sum_squares / n;
}

int filter(const int *a, int n) {
    int counter = 0;
    int res = 0;
    double avg = mean(a, n);
    double sigma3 = 3.0 * sqrt(variance(a, n));

    for (const int *p = a; p - a < n; p++) {
        if (counter < 1 && *p % 2 == 0 && *p >= avg && fabs(*p - avg) <= sigma3 && *p != 0) {
            counter++;
            res = *p;
        }
    }
    return res;
}