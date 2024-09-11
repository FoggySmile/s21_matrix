#include "s21_matrix_test.h"

int main(void) {
  run_tests();
  return 0;
}

int run_testcase(Suite *testcase) {
  int result = 1;
  static int counter_testcase = 1;
  if (counter_testcase > 1) counter_testcase++;
  SRunner *sr = srunner_create(testcase);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  result = srunner_ntests_failed(sr);
  srunner_free(sr);
  return result;
}

void run_tests(void) {
  Suite *list_cases[] = {s21_create_matrix_test_suite(),
                         s21_sum_matrix_test_suite(),
                         s21_sub_matrix_test_suite(),
                         s21_mult_number_test_suite(),
                         s21_mult_matrix_test_suite(),
                         s21_transpose_matrix_test_suite(),
                         s21_eq_matrix_test_suite(),
                         s21_determinant_test_suite(),
                         s21_calc_complements_test_suite(),
                         s21_inverse_matrix_test_suite(),
                         NULL};
  int number_failed = 0;
  int number_success = 0;
  for (Suite **current_testcase = list_cases; *current_testcase != NULL;
       current_testcase++) {
    if (run_testcase(*current_testcase) != 0)
      number_failed++;
    else
      number_success++;
  }
  printf("\e[32mSuccess: %d\e[0m\n\e[31mFailures: %d\e[0m\n", number_success,
         number_failed);
}

void fill_matrix_with_random_values(matrix_t *matrix) {
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++) {
      matrix->matrix[i][j] = ((double)rand() / RAND_MAX) * 200 -
                             100;  // Random double between -100 and 100
    }
  }
}
