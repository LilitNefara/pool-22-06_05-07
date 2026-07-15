#include "data_stat.h"

double max(const double *data, int n) {
    double res = data[0];
    for (int idx = 1; idx < n; idx++) {
        if (data[idx] > res) {
            res = data[idx];
        }
    }
    return res;
}

double min(const double *data, int n) {
    double res = data[0];
    for (int idx = 1; idx < n; idx++) {
        if (data[idx] < res) {
            res = data[idx];
        }
    }
    return res;
}

double mean(const double *data, int n) {
    double sum_val = 0.0;
    for (int idx = 0; idx < n; idx++) {
        sum_val += data[idx];
    }
    return sum_val / n;
}

double variance(double *data, int n) {
    double avg = mean(data, n);
    double sum_sq = 0.0;
    for (int idx = 0; idx < n; idx++) {
        sum_sq += (data[idx] - avg) * (data[idx] - avg);
    }
    return sum_sq / n;
}
