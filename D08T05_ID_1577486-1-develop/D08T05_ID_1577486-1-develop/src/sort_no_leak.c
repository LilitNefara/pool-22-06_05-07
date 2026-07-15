#include <stdio.h>
#include <stdlib.h>

int input(int *a, int n);
void output(const int *a, int n);
void sorted(int *a, int n);

int main() {
    int n = 0;
    int *data = NULL;
    int error = 0;

    if (scanf("%d", &n) != 1 || n <= 0) {
        error = 1;
    }

    if (!error) {
        data = (int *)malloc(n * sizeof(int));

        if (data == NULL) {
            error = 1;
        }
    }

    if (!error) {
        if (input(data, n) != 1) {
            error = 1;
        }
    }

    if (!error) {
        sorted(data, n);
        output(data, n);
    } else {
        printf("n/a");
    }
    if (data != NULL) {
        free(data);
    }
    return 0;
}

int input(int *a, int n) {
    int status = 1;
    char c;

    for (int *p = a; p - a < n && status; p++) {
        if (scanf("%d", p) != 1) {
            status = 0;
        }
    }

    if (status) {
        if (scanf("%c", &c) == 1 && c != ' ' && c != '\n') {
            status = 0;
        }
    }

    return status;
}

void output(const int *a, int n) {
    for (const int *p = a; p - a < n; p++) {
        if (p - a == n - 1) {
            printf("%d", *p);
        } else {
            printf("%d ", *p);
        }
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
