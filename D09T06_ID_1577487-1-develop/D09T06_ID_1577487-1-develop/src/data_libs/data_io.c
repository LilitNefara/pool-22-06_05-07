#include "data_io.h"

#include <stdio.h>

void input(double *data, int n) {
    for (int idx = 0; idx < n; idx++) {
        if (scanf("%lf", &data[idx]) != 1) {
            data[idx] = 0.0;
        }
    }
}

void output(double *data, int n) {
    for (int idx = 0; idx < n; idx++) {
        printf("%.2f", data[idx]);
        if (idx < n - 1) {
            printf(" ");
        }
    }
}
