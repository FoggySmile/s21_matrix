#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int err = OK;
  if (is_correct_matrix(A) == OK) {
    if (A->rows == A->columns) {
      err = s21_create_matrix(A->rows, A->columns, result);
      if (A->rows != 1) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            matrix_t minor = {0};
            double det = 0.0;
            s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
            s21_get_matrix_without_row_and_col(A, i, j, &minor);
            s21_determinant(&minor, &det);
            result->matrix[i][j] = pow(-1, (i + j)) * det;
            s21_remove_matrix(&minor);
          }
        }
      } else {
        result->matrix[0][0] = 1.0;
      }
    } else {
      err = CALCULATION_ERROR;
    }
  } else {
    err = INCORRECT_MATRIX;
  }
  return err;
}
