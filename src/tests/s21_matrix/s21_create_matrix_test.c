#include "../s21_matrix_test.h"

START_TEST(test1) {
  matrix_t result = {0};
  int err = s21_create_matrix(3, 3, &result);
  ck_assert_int_eq(err, OK);
  ck_assert_int_eq(result.rows, 3);
  ck_assert_int_eq(result.columns, 3);

  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test2) {
  matrix_t result = {0};
  int err = s21_create_matrix(3, 5, &result);
  ck_assert_int_eq(err, OK);
  ck_assert_int_eq(result.rows, 3);
  ck_assert_int_eq(result.columns, 5);

  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test3) {
  matrix_t result = {0};
  int err = s21_create_matrix(-3, 3, &result);
  ck_assert_int_eq(err, INCORRECT_MATRIX);
}
END_TEST

START_TEST(test4) {
  matrix_t result = {0};
  int err = s21_create_matrix(3, 0, &result);
  ck_assert_int_eq(err, INCORRECT_MATRIX);
}
END_TEST

START_TEST(test5) {
  int err = s21_create_matrix(3, 3, NULL);
  ck_assert_int_eq(err, INCORRECT_MATRIX);
}
END_TEST

Suite *s21_create_matrix_test_suite() {
  Suite *s = suite_create("\033[42m-=s21_create_matrix test=-\033[0m");
  TCase *t = tcase_create("main tcase");

  tcase_add_test(t, test1);
  tcase_add_test(t, test2);
  tcase_add_test(t, test3);
  tcase_add_test(t, test4);
  tcase_add_test(t, test5);

  suite_add_tcase(s, t);
  return s;
}