#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int err = OK;

  if (is_correct_matrix(A) == OK) {
    if (A->rows == A->columns) {
      if (A->rows == 1) {
        err = s21_create_matrix(A->rows, A->rows, result);
        result->matrix[0][0] = 1.0 / A->matrix[0][0];
      } else {
        double det = 0.0;
        s21_determinant(A, &det);

        if (fabs(det) < 1e-6)
          err = CALCULATION_ERROR;
        else {
          matrix_t tmp_1 = {0};
          err = s21_calc_complements(A, &tmp_1);
          matrix_t tmp_2 = {0};
          err = s21_transpose(&tmp_1, &tmp_2);
          err = s21_mult_number(&tmp_2, (1.0 / det), result);
          s21_remove_matrix(&tmp_2);
          s21_remove_matrix(&tmp_1);
        }
      }
    } else
      err = CALCULATION_ERROR;
  } else
    err = INCORRECT_MATRIX;
  return err;
}