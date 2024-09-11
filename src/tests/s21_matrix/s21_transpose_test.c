#include "../s21_matrix_test.h"

START_TEST(test1) {
  int rows = rand() % 10 + 1;
  int cols = rand() % 10 + 1;
  matrix_t A = {0}, expected = {0}, result = {0};

  s21_create_matrix(rows, cols, &A);
  s21_create_matrix(cols, rows, &expected);

  fill_matrix_with_random_values(&A);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      expected.matrix[j][i] = A.matrix[i][j];
    }
  }

  ck_assert_int_eq(s21_transpose(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&expected, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test2) {
  matrix_t A = {0}, result = {0};
  ck_assert_int_eq(s21_transpose(&A, &result), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_transpose_matrix_test_suite() {
  Suite *s = suite_create("\033[42m-=s21_transpose_matrix test=-\033[0m");
  TCase *t = tcase_create("main tcase");
  tcase_add_test(t, test1);
  tcase_add_test(t, test2);
  suite_add_tcase(s, t);
  return s;
}
