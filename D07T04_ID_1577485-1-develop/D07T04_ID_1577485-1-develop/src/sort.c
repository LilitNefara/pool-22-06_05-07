#include <stdio.h>

int input(int *a, int n);
void output(const int *a, int n);
void sorted(int *a, int n);

int main() {
    int n = 10, data[10];
    if (input(data, n) != 1) {
        printf("n/a");
    } else {
        sorted(data, n);
        output(data, n);
    }
    return 0;
}

int input(int *a, int n) {
    int status = 1;

    for (int *p = a; p - a < n && status; p++)
        if (scanf("%d", p) != 1) status = 0;
    return status;
}

void output(const int *a, int n) {
    for (const int *p = a; p - a < n; p++) {
        if (p - a == n - 1)
            printf("%d", *p);
        else
            printf("%d ", *p);
    }
}

void sorted(int *a, int n) {
    for (int i = 0; i < n; i++) {
        for (int *p = a; p - a < n - 1 - i; p++) {
            if (*p > *(p + 1)) {
                int temp;
                temp = *(p + 1);
                *(p + 1) = *p;
                *p = temp;
            }
        }
    }
}
