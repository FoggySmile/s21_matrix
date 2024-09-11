#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int err = SUCCESS;

  if (is_correct_matrix(A) == OK && is_correct_matrix(B) == OK &&
      A->rows == B->rows && A->columns == B->columns) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (round(A->matrix[i][j] * pow(10, 7)) !=
            round(B->matrix[i][j] * pow(10, 7))) {
          err = FAILURE;
        }
      }
    }
  } else {
    err = FAILURE;
  }
  return err;
}