#include "s21_matrix.h"

int is_correct_matrix(matrix_t *matrix) {
  int err = OK;
  if (matrix != NULL && matrix->matrix != NULL && matrix->columns > 0 &&
      matrix->rows > 0) {
    err = OK;
  } else {
    err = INCORRECT_MATRIX;
  }
  return err;
}

// Возвращает матрицу matrix без row-ой строки и col-того столбца, результат в
// result

void s21_get_matrix_without_row_and_col(matrix_t *matrix, int row, int col,
                                        matrix_t *result) {
  int offset_row = 0;
  for (int i = 0; i < matrix->rows - 1; i++) {
    if (i == row) {
      offset_row = 1;
    }
    int offset_col = 0;
    for (int j = 0; j < matrix->columns - 1; j++) {
      if (j == col) {
        offset_col = 1;
      }
      result->matrix[i][j] = matrix->matrix[i + offset_row][j + offset_col];
    }
  }
}