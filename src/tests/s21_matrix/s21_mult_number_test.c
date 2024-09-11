#include "../s21_matrix_test.h"

START_TEST(test1) {
  int rows = rand() % 10 + 1;  // Using fixed size for deterministic tests
  int cols = rand() % 10 + 1;
  double mult_num = (double)rand() / RAND_MAX;
  matrix_t A = {0}, expected = {0}, result = {0};

  s21_create_matrix(rows, cols, &A);
  s21_create_matrix(rows, cols, &expected);

  fill_matrix_with_random_values(&A);

  // Compute expected results
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      expected.matrix[i][j] = A.matrix[i][j] * mult_num;
    }
  }

  ck_assert_int_eq(s21_mult_number(&A, mult_num, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&expected, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test2) {
  int rows = rand() % 10 + 1;
  int cols = rand() % 10 + 1;
  rows = -rows;
  cols = -cols;
  double mult_num = (double)rand() / RAND_MAX;
  matrix_t A = {0}, result = {0};

  s21_create_matrix(rows, cols, &A);

  ck_assert_int_eq(s21_mult_number(&A, mult_num, &result), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_mult_number_test_suite() {
  Suite *s = suite_create("\033[42m-=s21_mult_number_matrix test=-\033[0m");
  TCase *t = tcase_create("main tcase");
  tcase_add_test(t, test1);
  tcase_add_test(t, test2);
  suite_add_tcase(s, t);
  return s;
}
