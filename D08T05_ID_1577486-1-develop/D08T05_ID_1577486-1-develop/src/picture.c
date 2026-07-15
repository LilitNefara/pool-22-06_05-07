#include <stdio.h>

#define N 15
#define M 13

void transform(int *buf, int **matr, int n, int m);
void make_picture(int **picture, int n, int m);
void reset_picture(int **picture, int n, int m);

int main(void) {
    int picture_data[N][M];
    int *picture[N];
    transform((int *)picture_data, picture, N, M);

    make_picture(picture, N, M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d", picture[i][j]);
            if (j < M - 1) {
                printf(" ");
            }
        }
        if (i < N - 1) {
            printf("\n");
        }
    }
    return 0;
}

void make_picture(int **picture, int n, int m) {
    const int frame_w[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    const int frame_h[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    const int tree_trunk[] = {7, 7, 7, 7};
    const int tree_foliage[] = {3, 3, 3, 3};
    const int sun_data[6][5] = {{0, 6, 6, 6, 6}, {0, 0, 6, 6, 6}, {0, 0, 6, 6, 6},
                                {0, 6, 0, 0, 6}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};

    reset_picture(picture, n, m);

    int length_frame_w = (int)(sizeof(frame_w) / sizeof(frame_w[0]));
    for (int i = 0; i < length_frame_w; i++) {
        picture[0][i] = frame_w[i];
        picture[n - 1][i] = frame_w[i];
    }

    for (int i = 0; i < n; i++) {
        picture[i][0] = frame_h[i];
        picture[i][m - 1] = frame_h[i];
    }

    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 5; j++) {
            if (sun_data[i - 1][j - 1] != 0) {
                picture[i][j + 6] = sun_data[i - 1][j - 1];
            }
        }
    }

    int length_tree_foliage = (int)(sizeof(tree_foliage) / sizeof(tree_foliage[0]));
    for (int i = 0; i < length_tree_foliage; i++) {
        picture[2 + i][2] = tree_foliage[i];
        picture[2 + i][3] = tree_foliage[i];
        picture[2 + i][4] = tree_foliage[i];
        picture[2 + i][5] = tree_foliage[i];
    }

    int length_tree_trunk = (int)(sizeof(tree_trunk) / sizeof(tree_trunk[0]));
    for (int i = 0; i < length_tree_trunk; i++) {
        picture[6 + i][3] = tree_trunk[i];
        picture[6 + i][4] = tree_trunk[i];
    }
}

void reset_picture(int **picture, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            picture[i][j] = 0;
        }
    }
}

void transform(int *buf, int **matr, int n, int m) {
    for (int i = 0; i < n; i++) {
        matr[i] = buf + i * m;
    }
}
