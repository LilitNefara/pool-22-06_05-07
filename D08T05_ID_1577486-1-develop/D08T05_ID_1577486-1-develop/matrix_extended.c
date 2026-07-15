#include <stdio.h>
#include <stdlib.h>

#define MAX_G 100

int get_sz(int *h, int *w) {
  return (scanf("%d %d", h, w) == 2 && *h > 0 && *w > 0);
}

int check_buf(void) {
  char c;
  int ok = 1;
  if (scanf("%c", &c) == 1 && c != ' ' && c != '\n') {
    ok = 0;
  }
  return ok;
}

int **al_3(int h, int w) {
  int **m = (int **)malloc(h * sizeof(int *));
  if (m != NULL) {
    for (int i = 0; i < h; i++) {
      m[i] = (int *)malloc(w * sizeof(int));
    }
  }
  return m;
}

int **al_4(int h, int w) {
  int **m = (int **)malloc(h * sizeof(int *));
  if (m != NULL) {
    int *v = (int *)malloc(h * w * sizeof(int));
    for (int i = 0; i < h; i++) {
      m[i] = v + i * w;
    }
  }
  return m;
}

void process_and_print(int **m, int h, int w) {
  for (int r = 0; r < h; r++) {
    for (int c = 0; c < w; c++) {
      printf("%d", m[r][c]);
      if (c < w - 1)
        printf(" ");
    }
    printf("\n");
  }

  for (int r = 0; r < h; r++) {
    int max = m[r][0];
    for (int c = 1; c < w; c++) {
      if (m[r][c] > max)
        max = m[r][c];
    }
    printf("%d", max);
    if (r < h - 1)
      printf(" ");
  }
  printf("\n");

  for (int c = 0; c < w; c++) {
    int min = m[0][c];
    for (int r = 1; r < h; r++) {
      if (m[r][c] < min)
        min = m[r][c];
    }
    printf("%d", min);
    if (c < w - 1)
      printf(" ");
  }
}

int main(void) {
  int mode = 0, h = 0, w = 0, err = 0;
  int st_m[MAX_G][MAX_G] = {{0}};
  int *flat = NULL;
  int **dyn = NULL;
  st_m[0][0] = 0;

  if (scanf("%d", &mode) != 1 || mode < 1 || mode > 4)
    err = 1;
  if (!err && !get_sz(&h, &w))
    err = 1;
  if (!err && mode == 1 && (h > MAX_G || w > MAX_G))
    err = 1;

  if (!err) {
    if (mode == 1) {
      int *ptrs[MAX_G];
      for (int i = 0; i < h; i++)
        ptrs[i] = st_m[i];

      // Заполняем статическую матрицу
      for (int r = 0; r < h && !err; r++)
        for (int c = 0; c < w && !err; c++)
          if (scanf("%d", &ptrs[r][c]) != 1)
            err = 1;

      if (!err && check_buf())
        process_and_print(ptrs, h, w);
      else
        err = 1;

    } else if (mode == 2) {
      flat = (int *)malloc(h * w * sizeof(int));
      if (flat == NULL)
        err = 1;

      for (int i = 0; i < h * w && !err; i++)
        if (scanf("%d", &flat[i]) != 1)
          err = 1;

      if (!err && check_buf()) {
        int *ptrs[MAX_G];
        for (int i = 0; i < h; i++)
          ptrs[i] = flat + i * w;
        process_and_print(ptrs, h, w);
      } else
        err = 1;

    } else if (mode == 3 || mode == 4) {
      dyn = (mode == 3) ? al_3(h, w) : al_4(h, w);
      if (dyn == NULL || dyn[0] == NULL)
        err = 1;

      for (int r = 0; r < h && !err; r++)
        for (int c = 0; c < w && !err; c++)
          if (scanf("%d", &dyn[r][c]) != 1)
            err = 1;

      if (!err && check_buf())
        process_and_print(dyn, h, w);
      else
        err = 1;
    }
  }

  if (err)
    printf("n/a");

  if (flat != NULL)
    free(flat);
  if (dyn != NULL) {
    if (mode == 3) {
      for (int i = 0; i < h; i++)
        free(dyn[i]);
    }
    if (mode == 4) {
      free(dyn[0]);
    }
    free(dyn);
  }
  return 0;
}
