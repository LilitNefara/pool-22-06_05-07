#include <stdio.h>
#include <stdlib.h>

int input(int **matrix, int *n, int *m);
void output(int **matrix, int n, int m);
int sum(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int **matrix_result, int *n_result, int *m_result);
int transpose(int **matrix, int n, int m);
int mul(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int **matrix_result, int *n_result, int *m_result);
int check_buffer(void);

int main(void) {
    int op = 0, n1 = 0, m1 = 0, n2 = 0, m2 = 0, nr = 0, mr = 0, err = 0;
    int **matrix1 = NULL, **matrix2 = NULL, **result = NULL;
    int *v1 = NULL, *v2 = NULL, *vr = NULL;

    if (scanf("%d", &op) != 1 || op < 1 || op > 3) {
        err = 1;
    }

    if (!err && (op == 1 || op == 2)) {
        if (!input(matrix1, &n1, &m1)) {
            matrix1 = (int **)malloc(n1 * sizeof(int *));
            v1 = (int *)malloc(n1 * m1 * sizeof(int));
            if (matrix1 != NULL && v1 != NULL) {
                for (int i = 0; i < n1; i++) matrix1[i] = v1 + i * m1;
                for (int r = 0; r < n1 && !err; r++)
                    for (int c = 0; c < m1 && !err; c++)
                        if (scanf("%d", &matrix1[r][c]) != 1) err = 1;
            } else
                err = 1;
        } else
            err = 1;

        if (!err) {
            if (!input(matrix2, &n2, &m2)) {
                matrix2 = (int **)malloc(n2 * sizeof(int *));
                v2 = (int *)malloc(n2 * m2 * sizeof(int));
                if (matrix2 != NULL && v2 != NULL) {
                    for (int i = 0; i < n2; i++) matrix2[i] = v2 + i * m2;
                    for (int r = 0; r < n2 && !err; r++)
                        for (int c = 0; c < m2 && !err; c++)
                            if (scanf("%d", &matrix2[r][c]) != 1) err = 1;
                } else
                    err = 1;
            } else
                err = 1;
        }
        if (!err && !check_buffer()) err = 1;

        if (!err) {
            if (op == 1) {
                result = (int **)malloc(n1 * sizeof(int *));
                vr = (int *)malloc(n1 * m1 * sizeof(int));
                if (result != NULL && vr != NULL) {
                    for (int i = 0; i < n1; i++) result[i] = vr + i * m1;
                    if (sum(matrix1, n1, m1, matrix2, n2, m2, result, &nr, &mr)) {
                        output(result, nr, mr);
                    } else
                        err = 1;
                } else
                    err = 1;
            } else if (op == 2) {
                result = (int **)malloc(n1 * sizeof(int *));
                vr = (int *)malloc(n1 * m2 * sizeof(int));
                if (result != NULL && vr != NULL) {
                    for (int i = 0; i < n1; i++) result[i] = vr + i * m2;
                    if (mul(matrix1, n1, m1, matrix2, n2, m2, result, &nr, &mr)) {
                        output(result, nr, mr);
                    } else
                        err = 1;
                } else
                    err = 1;
            }
        }
    }

    if (!err && op == 3) {
        if (!input(matrix1, &n1, &m1)) {
            matrix1 = (int **)malloc(n1 * sizeof(int *));
            v1 = (int *)malloc(n1 * m1 * sizeof(int));
            if (matrix1 != NULL && v1 != NULL) {
                for (int i = 0; i < n1; i++) matrix1[i] = v1 + i * m1;
                for (int r = 0; r < n1 && !err; r++)
                    for (int c = 0; c < m1 && !err; c++)
                        if (scanf("%d", &matrix1[r][c]) != 1) err = 1;
                if (!err && !check_buffer()) err = 1;
                if (!err) {
                    if (!transpose(matrix1, n1, m1)) err = 1;
                }
            } else
                err = 1;
        } else
            err = 1;
    }

    if (err) printf("n/a");

    if (v1 != NULL) free(v1);
    if (matrix1 != NULL) free(matrix1);
    if (v2 != NULL) free(v2);
    if (matrix2 != NULL) free(matrix2);
    if (vr != NULL) free(vr);
    if (result != NULL) free(result);

    return 0;
}

int input(int **matrix, int *n, int *m) {
    int ok = 0;
    (void)matrix;
    if (scanf("%d %d", n, m) != 2 || *n <= 0 || *m <= 0) {
        ok = 1;
    }
    return ok;
}

void output(int **matrix, int n, int m) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            printf("%d", matrix[r][c]);
            if (c < m - 1) printf(" ");
        }
        if (r < n - 1) printf("\n");
    }
}

int sum(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int **matrix_result, int *n_result, int *m_result) {
    int ok = 0;
    if (n_first == n_second && m_first == m_second) {
        *n_result = n_first;
        *m_result = m_first;
        for (int r = 0; r < n_first; r++) {
            for (int c = 0; c < m_first; c++) {
                matrix_result[r][c] = matrix_first[r][c] + matrix_second[r][c];
            }
        }
        ok = 1;
    }
    return ok;
}

int transpose(int **matrix, int n, int m) {
    int **res = (int **)malloc(m * sizeof(int *));
    int *vr = (int *)malloc(m * n * sizeof(int));
    int ok = 0;
    if (res != NULL && vr != NULL) {
        for (int i = 0; i < m; i++) res[i] = vr + i * n;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                res[c][r] = matrix[r][c];
            }
        }
        output(res, m, n);
        ok = 1;
    }
    if (vr != NULL) free(vr);
    if (res != NULL) free(res);
    return ok;
}

int mul(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int **matrix_result, int *n_result, int *m_result) {
    int ok = 0;
    if (m_first == n_second) {
        *n_result = n_first;
        *m_result = m_second;
        for (int r = 0; r < n_first; r++) {
            for (int c = 0; c < m_second; c++) {
                matrix_result[r][c] = 0;
                for (int k = 0; k < m_first; k++) {
                    matrix_result[r][c] += matrix_first[r][k] * matrix_second[k][c];
                }
            }
        }
        ok = 1;
    }
    return ok;
}

int check_buffer(void) {
    char c;
    int ok = 1;
    if (scanf("%c", &c) == 1 && c != ' ' && c != '\n') {
        ok = 0;
    }
    return ok;
}
