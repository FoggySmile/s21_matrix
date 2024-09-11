#include "../s21_matrix_test.h"

START_TEST(test1) {
  int rows = rand() % 10 + 1;
  int cols = rand() % 10 + 1;
  matrix_t A = {0}, B = {0};

  s21_create_matrix(rows, cols, &A);
  s21_create_matrix(rows, cols, &B);

  fill_matrix_with_random_values(&A);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      B.matrix[i][j] = A.matrix[i][j];
    }
  }

  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test2) {
  int rows = rand() % 10 + 1;
  int cols = rand() % 10 + 1;
  matrix_t A = {0}, B = {0};

  s21_create_matrix(rows, cols, &A);
  s21_create_matrix(rows, cols, &B);

  fill_matrix_with_random_values(&A);
  fill_matrix_with_random_values(&B);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test3) {
  matrix_t A = {0};
  matrix_t B = {0};

  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
}

Suite *s21_eq_matrix_test_suite() {
  Suite *s = suite_create("\033[42m-=s21_eq_matrix test=-\033[0m");
  TCase *t = tcase_create("main tcase");
  tcase_add_test(t, test1);
  tcase_add_test(t, test2);
  tcase_add_test(t, test3);
  suite_add_tcase(s, t);
  return s;
}
