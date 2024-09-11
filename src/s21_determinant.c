#include "s21_matrix.h"

// Вычисление определителя матрицы разложение по первой строке
int s21_determinant(matrix_t *A, double *result) {
  int err = OK;
  *result = 0.0;
  if (is_correct_matrix(A) == OK) {
    if (A->rows == A->columns) {
      *result = s21_get_determinant(A);
    } else {
      err = CALCULATION_ERROR;
    }
  } else {
    err = INCORRECT_MATRIX;
  }
  return err;
}

double s21_get_determinant(matrix_t *A) {
  double det = 0.0;
  int degree = 1;  // (-1)^(1+j)

  if (A->rows == 1) {
    det = A->matrix[0][0];
  } else if (A->rows == 2) {
    det = A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else {
    matrix_t tmp = {0};
    s21_create_matrix(A->rows - 1, A->columns - 1, &tmp);
    for (int j = 0; j < A->rows; j++) {
      s21_get_matrix_without_row_and_col(A, 0, j, &tmp);
      det += (degree * A->matrix[0][j] * s21_get_determinant(&tmp));
      degree = -degree;
    }
    s21_remove_matrix(&tmp);
  }
  return det;
}