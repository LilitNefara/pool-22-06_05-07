#include <stdio.h>
#include <stdlib.h>

#define GRID_MAX 100

int get_grid_sizes(int *h, int *w);
int fill_2d_grid(int **grid, int h, int w);
int fill_flat_grid(int *grid, int h, int w);
void print_2d_grid(const int *const *grid, int h, int w);
void print_flat_grid(const int *grid, int h, int w);
int is_stream_clean(void);

int **create_split_matrix(int h, int w);
int **create_solid_matrix(int h, int w);
void delete_split_matrix(int **grid, int h);
void delete_solid_matrix(int **grid);

int main(void) {
    int mode = 0, h = 0, w = 0, fail_flag = 0;

    int fixed_array[GRID_MAX][GRID_MAX] = {{0}};
    int *linear_cache = NULL;
    int **dynamic_table = NULL;
    fixed_array[0][0] = 0;

    if (scanf("%d", &mode) != 1 || mode < 1 || mode > 4) {
        fail_flag = 1;
    }

    if (!fail_flag) {
        if (!get_grid_sizes(&h, &w)) {
            fail_flag = 1;
        }

        if (mode == 1 && (h > GRID_MAX || w > GRID_MAX)) {
            fail_flag = 1;
        }
    }

    if (!fail_flag) {
        if (mode == 1) {
            int *row_pointers[GRID_MAX];
            for (int idx = 0; idx < h; idx++) {
                row_pointers[idx] = fixed_array[idx];
            }
            if (fill_2d_grid(row_pointers, h, w) != 1 || !is_stream_clean()) {
                fail_flag = 1;
            }
            if (!fail_flag) {
                print_2d_grid((const int *const *)row_pointers, h, w);
            }

        } else if (mode == 2) {
            linear_cache = (int *)malloc(h * w * sizeof(int));
            if (linear_cache == NULL) {
                fail_flag = 1;
            }
            if (!fail_flag && (fill_flat_grid(linear_cache, h, w) != 1 || !is_stream_clean())) {
                fail_flag = 1;
            }
            if (!fail_flag) {
                print_flat_grid(linear_cache, h, w);
            }

        } else if (mode == 3) {
            dynamic_table = create_split_matrix(h, w);
            if (dynamic_table == NULL) {
                fail_flag = 1;
            }
            if (!fail_flag && (fill_2d_grid(dynamic_table, h, w) != 1 || !is_stream_clean())) {
                fail_flag = 1;
            }
            if (!fail_flag) {
                print_2d_grid((const int *const *)dynamic_table, h, w);
            }

        } else if (mode == 4) {
            dynamic_table = create_solid_matrix(h, w);
            if (dynamic_table == NULL) {
                fail_flag = 1;
            }
            if (!fail_flag && (fill_2d_grid(dynamic_table, h, w) != 1 || !is_stream_clean())) {
                fail_flag = 1;
            }
            if (!fail_flag) {
                print_2d_grid((const int *const *)dynamic_table, h, w);
            }
        }
    }

    if (fail_flag) {
        printf("n/a");
    }

    if (linear_cache != NULL) {
        free(linear_cache);
    }
    if (dynamic_table != NULL) {
        if (mode == 3) {
            delete_split_matrix(dynamic_table, h);
        }
        if (mode == 4) {
            delete_solid_matrix(dynamic_table);
        }
    }
    return 0;
}

int **create_split_matrix(int h, int w) {
    int **grid = (int **)malloc(h * sizeof(int *));
    if (grid != NULL) {
        int alloc_fail = 0;
        for (int i = 0; i < h && !alloc_fail; i++) {
            grid[i] = (int *)malloc(w * sizeof(int));
            if (grid[i] == NULL) {
                for (int j = 0; j < i; j++) {
                    free(grid[j]);
                }
                free(grid);
                grid = NULL;
                alloc_fail = 1;
            }
        }
    }
    return grid;
}

int **create_solid_matrix(int h, int w) {
    int **grid = (int **)malloc(h * sizeof(int *));
    if (grid != NULL) {
        int *const continuous_buffer = (int *)malloc(h * w * sizeof(int));
        if (continuous_buffer == NULL) {
            free(grid);
            grid = NULL;
        } else {
            for (int i = 0; i < h; i++) {
                grid[i] = continuous_buffer + i * w;
            }
        }
    }
    return grid;
}

void delete_split_matrix(int **grid, int h) {
    for (int i = 0; i < h; i++) {
        free(grid[i]);
    }
    free(grid);
}

void delete_solid_matrix(int **grid) {
    if (grid != NULL) {
        if (grid[0] != NULL) {
            free(grid[0]);
        }
        free(grid);
    }
}

int get_grid_sizes(int *h, int *w) { return (scanf("%d %d", h, w) == 2 && *h > 0 && *w > 0); }

int fill_2d_grid(int **grid, int h, int w) {
    int active = 1;
    for (int r = 0; r < h && active; r++) {
        for (int c = 0; c < w && active; c++) {
            if (scanf("%d", &grid[r][c]) != 1) {
                active = 0;
            }
        }
    }
    return active;
}

int fill_flat_grid(int *grid, int h, int w) {
    int active = 1;
    const int total_cells = h * w;
    for (int idx = 0; idx < total_cells && active; idx++) {
        if (scanf("%d", &grid[idx]) != 1) {
            active = 0;
        }
    }
    return active;
}

void print_2d_grid(const int *const *grid, int h, int w) {
    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            printf("%d", grid[r][c]);
            if (c < w - 1) {
                printf(" ");
            }
        }
        if (r < h - 1) {
            printf("\n");
        }
    }
}

void print_flat_grid(const int *grid, int h, int w) {
    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            printf("%d", grid[r * w + c]);
            if (c < w - 1) {
                printf(" ");
            }
        }
        if (r < h - 1) {
            printf("\n");
        }
    }
}

int is_stream_clean(void) {
    int is_ok = 1;
    char lookahead;
    if (scanf("%c", &lookahead) == 1 && lookahead != ' ' && lookahead != '\n') {
        is_ok = 0;
    }
    return is_ok;
}
