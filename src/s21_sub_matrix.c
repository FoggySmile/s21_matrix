#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int err = OK;

  if (is_correct_matrix(A) == OK && is_correct_matrix(B) == OK) {
    if (A->rows == B->rows && A->columns == B->columns) {
      err = s21_create_matrix(A->rows, A->columns, result);

      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
      }
    } else {
      err = CALCULATION_ERROR;
    }
  } else {
    err = INCORRECT_MATRIX;
  }
  return err;
}
