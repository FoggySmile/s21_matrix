#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

// comparison
#define SUCCESS 1
#define FAILURE 0

/*
0 - OK
1 - Error, incorrect matrix
2 - Calculation error (mismatched matrix sizes; matrix for which calculations
cannot be performed, etc.)
*/

// operations
enum result_code {
  OK,
  INCORRECT_MATRIX,
  CALCULATION_ERROR,
};

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// helpers
int is_correct_matrix(matrix_t *matrix);
void s21_get_matrix_without_row_and_col(matrix_t *matrix, int row, int col,
                                        matrix_t *result);
double s21_get_determinant(matrix_t *A);
#endif