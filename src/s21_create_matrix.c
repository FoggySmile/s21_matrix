#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int err = OK;
  if (rows <= 0 || columns <= 0 || result == NULL) {
    return INCORRECT_MATRIX;
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double *));
    err = OK;
  }
  if (result->matrix != NULL) {
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
      if (result->matrix[i] == NULL) {
        for (int j = 0; j < i; j++) free(result->matrix[j]);
        free(result->matrix);
      }
    }
    err = OK;
  }
  return err;
}
