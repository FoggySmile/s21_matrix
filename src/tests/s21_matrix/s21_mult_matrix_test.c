#include "../s21_matrix_test.h"

START_TEST(test1) {
  int rows = rand() % 10 + 1;
  int cols = rand() % 10 + 1;
  matrix_t A = {0}, B = {0}, expected = {0}, result = {0};

  s21_create_matrix(rows, cols, &A);
  s21_create_matrix(cols, rows, &B);

  fill_matrix_with_random_values(&A);
  fill_matrix_with_random_values(&B);

  s21_create_matrix(A.rows, B.columns, &expected);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      for (int k = 0; k < B.rows; k++) {
        expected.matrix[i][j] += A.matrix[i][k] * B.matrix[k][j];
      }
    }
  }

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&expected, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test2) {
  int rows_A = 5;
  int cols_A = 6;
  int rows_B = 7;
  int cols_B = 8;
  matrix_t A = {0}, B = {0}, result = {0};

  s21_create_matrix(rows_A, cols_A, &A);
  s21_create_matrix(rows_B, cols_B, &B);

  fill_matrix_with_random_values(&A);
  fill_matrix_with_random_values(&B);

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test3) {
  int rows = rand() % 10 + 1;
  int cols = rand() % 10 + 1;
  rows = -rows;
  cols = -cols;
  matrix_t A = {0}, B = {0}, expected = {0}, result = {0};

  s21_create_matrix(rows, cols, &A);
  s21_create_matrix(rows, cols, &B);
  s21_create_matrix(rows, cols, &expected);
  s21_create_matrix(rows, cols, &result);

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

Suite *s21_mult_matrix_test_suite() {
  Suite *s = suite_create("\033[42m-=s21_mult_matrix test=-\033[0m");
  TCase *t = tcase_create("main tcase");
  tcase_add_test(t, test1);
  tcase_add_test(t, test2);
  tcase_add_test(t, test3);
  suite_add_tcase(s, t);
  return s;
}
