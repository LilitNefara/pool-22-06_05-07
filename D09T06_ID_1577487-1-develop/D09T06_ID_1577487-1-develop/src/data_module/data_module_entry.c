#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "../data_libs/data_stat.h"

int normalization(double *data, int n);
int check_stream(void);

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
        if (!check_stream()) {
            fail_flag = 1;
        }
    }

    if (!fail_flag) {
        if (normalization(dataset, total_elements)) {
            output(dataset, total_elements);
        } else {
            fail_flag = 1;
        }
    }

    if (fail_flag) {
        printf("n/a");
    }

    if (dataset != NULL) {
        free(dataset);
    }

    return 0;
}

int normalization(double *data, int n) {
    int success = 1;
    double high_boundary = max(data, n);
    double low_boundary = min(data, n);

    if (high_boundary - low_boundary < 1e-9) {
        success = 0;
    } else {
        for (int idx = 0; idx < n; idx++) {
            data[idx] = (data[idx] - low_boundary) / (high_boundary - low_boundary);
        }
    }
    return success;
}

int check_stream(void) {
    char lookahead;
    int is_ok = 1;
    if (scanf("%c", &lookahead) == 1 && lookahead != ' ' && lookahead != '\n') {
        is_ok = 0;
    }
    return is_ok;
}
