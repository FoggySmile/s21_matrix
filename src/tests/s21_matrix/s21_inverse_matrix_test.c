#include "../s21_matrix_test.h"

START_TEST(test1) {
  matrix_t A = {0}, result = {0};
  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  int err = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(err, OK);

  ck_assert_double_eq_tol(result.matrix[0][0], -2.0, 1e-6);
  ck_assert_double_eq_tol(result.matrix[0][1], 1.0, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][0], 1.5, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][1], -0.5, 1e-6);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test2) {
  matrix_t A = {0}, result = {0};
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

  int err = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(err, OK);

  ck_assert_double_eq_tol(result.matrix[0][0], -24.0, 1e-6);
  ck_assert_double_eq_tol(result.matrix[0][1], 18.0, 1e-6);
  ck_assert_double_eq_tol(result.matrix[0][2], 5.0, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][0], 20.0, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][1], -15.0, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][2], -4.0, 1e-6);
  ck_assert_double_eq_tol(result.matrix[2][0], -5.0, 1e-6);
  ck_assert_double_eq_tol(result.matrix[2][1], 4.0, 1e-6);
  ck_assert_double_eq_tol(result.matrix[2][2], 1.0, 1e-6);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test3) {
  matrix_t A = {0}, result = {0};
  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 4;  // Матрица сингулярная, определитель 0

  int err = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(err, CALCULATION_ERROR);  // Обратная матрица невозможна

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test4) {
  matrix_t A = {0}, result = {0};
  s21_create_matrix(2, 3, &A);  // Неквадратная матрица

  int err = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(
      err, CALCULATION_ERROR);  // Обратная невозможна для неквадратных матриц

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test5) {
  matrix_t A = {0}, result = {0};

  int err = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(err, INCORRECT_MATRIX);  // Ошибка из-за некорректной матрицы
}
END_TEST

START_TEST(test6) {
  matrix_t A = {0}, result = {0};
  s21_create_matrix(1, 1, &A);

  A.matrix[0][0] = 1;

  int err = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(err, OK);

  ck_assert_double_eq_tol(result.matrix[0][0], 1.0, 1e-6);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_inverse_matrix_test_suite() {
  Suite *s = suite_create("\033[42m-=s21_inverse_matrix test=-\033[0m");
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