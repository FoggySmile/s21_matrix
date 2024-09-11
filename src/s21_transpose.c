#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int err = OK;
  if (is_correct_matrix(A) == OK) {
    err = s21_create_matrix(A->columns, A->rows, result);
    if (result->matrix) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[j][i] = A->matrix[i][j];
        }
      }
    } else {
      err = INCORRECT_MATRIX;
    }
  } else {
    err = INCORRECT_MATRIX;
  }
  return err;
}