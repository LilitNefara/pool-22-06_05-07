#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(const int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 1) {
        squaring(data, n);
        output(data, n);
    } else
        printf("n/a");

    return 0;
}

int input(int *a, int *n) {
    int status = 1;
    if (scanf("%d", n) != 1 || *n <= 0 || *n > NMAX) status = 0;
    for (int *p = a; (p - a < *n) && status; p++)
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

void squaring(int *a, int n) {
    for (int *p = a; p - a < n; p++) *p *= *p;
}
