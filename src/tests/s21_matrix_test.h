#ifndef S21_MATRIX_TEST_H
#define S21_MATRIX_TEST_H

#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../s21_matrix.h"

int run_testcase(Suite *testcase);
void run_tests(void);

Suite *s21_create_matrix_test_suite();
Suite *s21_sum_matrix_test_suite();
Suite *s21_sub_matrix_test_suite();
Suite *s21_mult_number_test_suite();
Suite *s21_mult_matrix_test_suite();
Suite *s21_transpose_matrix_test_suite();
Suite *s21_eq_matrix_test_suite();
Suite *s21_determinant_test_suite();
Suite *s21_calc_complements_test_suite();
Suite *s21_inverse_matrix_test_suite();

void fill_matrix_with_random_values(matrix_t *matrix);

#endif