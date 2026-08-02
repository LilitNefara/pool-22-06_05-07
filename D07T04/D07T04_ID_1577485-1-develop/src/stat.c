#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(const int *a, int n);
int max(const int *a, const int *n);
int min(const int *a, const int *n);
double mean(const int *a, int n);
double variance(const int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];

    if (input(data, &n) == 1) {
        output(data, n);
        printf("\n");
        output_result(max(data, &n), min(data, &n), mean(data, n), variance(data, n));
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

void output(const int *a, int n) {
    for (const int *p = a; p - a < n; p++) {
        if ((p - a) == n - 1)
            printf("%d", *p);
        else
            printf("%d ", *p);
    }
}

int max(const int *a, const int *n) {
    int maximum = *a;
    for (const int *p = a; p - a < *n; p++)
        if (*p > maximum) maximum = *p;
    return maximum;
}

int min(const int *a, const int *n) {
    int minimum = *a;
    for (const int *p = a; p - a < *n; p++)
        if (*p < minimum) minimum = *p;
    return minimum;
}

double mean(const int *a, int n) {
    double sum = 0.0;
    for (const int *p = a; p - a < n; p++) sum += *p;
    return sum / n;
}

double variance(const int *a, int n) {
    double sum_squares = 0.0;
    double average = mean(a, n);
    for (const int *p = a; p - a < n; p++) sum_squares += (*p - average) * (*p - average);
    return sum_squares / n;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6f %.6f", max_v, min_v, mean_v, variance_v);
}