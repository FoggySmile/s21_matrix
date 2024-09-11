#include "../s21_matrix_test.h"

START_TEST(test1) {
  matrix_t A;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 5;

  double result = 0.0;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq(result, 5.0);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test2) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  double result = 0.0;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(result, -2.0, 1e-6);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test3) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 1;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 6;
  A.matrix[2][2] = 0;

  double result = 0.0;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(result, 1.0, 1e-6);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test4) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 3;
  A.matrix[2][0] = 4;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;

  double result = 0.0;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq(result, 0.0);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test5) {
  matrix_t A = {0};
  double result = 0.0;
  ck_assert_int_eq(s21_determinant(&A, &result), INCORRECT_MATRIX);
}
END_TEST

START_TEST(test6) {
  matrix_t A;
  s21_create_matrix(3, 4, &A);

  double result = 0.0;
  ck_assert_int_eq(s21_determinant(&A, &result), CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_determinant_test_suite() {
  Suite *s = suite_create("\033[42m-=s21_determinant_test=-\033[0m");
  TCase *t = tcase_create("main tcase");
  tcase_add_test(t, test1);
  tcase_add_test(t, test2);
  tcase_add_test(t, test3);
  tcase_add_test(t, test4);
  tcase_add_test(t, test5);
  tcase_add_test(t, test6);
  suite_add_tcase(s, t);
  return s;
}
