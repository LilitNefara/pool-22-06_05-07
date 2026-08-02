#include <stdio.h>
#include <stdlib.h>
#include "../data_libs/data_io.h"
#include "decision.h"

int check_buffer(void);

int main(void) {
    int total_elements = 0, fail_flag = 0;
    double *dataset = NULL;

    if (scanf("%d", &total_elements) != 1 || total_elements <= 0) {
        fail_flag = 1;
    }

    if (!fail_flag) {
        dataset = (double *)malloc(total_elements * sizeof(double));
        if (dataset == NULL) {
            fail_flag = 1;
        }
    }

    if (!fail_flag) {
        input(dataset, total_elements);
        if (!check_buffer()) {
            fail_flag = 1;
        }
    }

    if (!fail_flag) {
        if (make_decision(dataset, total_elements)) {
            printf("YES");
        } else {
            printf("NO");
        }
    } else {
        printf("n/a");
    }

    if (dataset != NULL) {
        free(dataset);
    }

    return 0;
}

int check_buffer(void) {
    char c;
    int ok = 1;
    if (scanf("%c", &c) == 1 && c != ' ' && c != '\n') {
        ok = 0;
    }
    return ok;
}
