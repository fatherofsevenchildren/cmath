#include <check.h>
#include <math.h>

#include "s21_math.h"

/*
 *************************************************************************
  TEST ABS
 *************************************************************************
*/

START_TEST(s21_test_abs) {
  ck_assert_int_eq(s21_abs(22), abs(22));
  ck_assert_int_eq(s21_abs(-6), abs(-6));
  ck_assert_int_eq(s21_abs(-1000), abs(-1000));
  ck_assert_int_eq(s21_abs(600000), abs(600000));
  ck_assert_int_eq(s21_abs(-696), abs(-696));
}
END_TEST

/*
 *************************************************************************
  TEST FABS
 *************************************************************************
*/

START_TEST(s21_test_fabs) {
  ck_assert_double_eq(s21_fabs(22.005), fabs(22.005));
  ck_assert_double_eq(s21_fabs(-22.005), fabs(-22.005));
  ck_assert_double_eq(s21_fabs(22.000005), fabs(22.000005));
  ck_assert_double_eq(s21_fabs(5000043.005), fabs(5000043.005));
  ck_assert_double_eq(s21_fabs(-5000043.005), fabs(-5000043.005));
  ck_assert_double_nan(fabs(NAN));
  ck_assert_double_nan(s21_fabs(S21_NAN));
  ck_assert_double_eq(s21_fabs(INF_PLUS), fabs(INFINITY));
  ck_assert_double_eq(s21_fabs(INF_MINUS), fabs(-INFINITY));
}
END_TEST

/*
 *************************************************************************
  TEST CEIL
 *************************************************************************
 */

START_TEST(s21_test_ceil) {
  ck_assert_double_eq(s21_ceil(22.04), ceil(22.04));
  ck_assert_double_eq(s21_ceil(-22.04), ceil(-22.04));
  ck_assert_double_eq(s21_ceil(INF_PLUS), ceil(INFINITY));
  ck_assert_double_eq(s21_ceil(INF_MINUS), ceil(-INFINITY));
  ck_assert_double_eq(s21_ceil(-100002.00004), ceil(-100002.00004));
  ck_assert_double_nan(ceil(NAN));
  ck_assert_double_nan(s21_ceil(S21_NAN));
}
END_TEST

/*
 *************************************************************************
  TEST FLOOR
 *************************************************************************
*/

START_TEST(s21_test_floor) {
  ck_assert_double_eq(s21_floor(4343.04), floor(4343.04));
  ck_assert_double_eq(s21_floor(-454.0004), floor(-454.0004));
  ck_assert_double_eq(s21_floor(INF_PLUS), floor(INF_PLUS));
  ck_assert_double_eq(s21_floor(INF_MINUS), floor(INF_MINUS));
  ck_assert_double_eq(s21_floor(-1.01), floor(-1.01));
  ck_assert_double_nan(s21_floor(S21_NAN));
  ck_assert_double_nan(floor(NAN));
}
END_TEST

/*
 *************************************************************************
  TEST FMOD
 *************************************************************************
*/

START_TEST(s21_test_fmod) {
  ck_assert_double_eq(s21_fmod(2, 2), fmod(2, 2));
  ck_assert_double_eq(s21_fmod(-9.4, 8), fmod(-9.4, 8));
  ck_assert_double_eq(s21_fmod(9.4, 8), fmod(9.4, 8));
  ck_assert_double_eq(s21_fmod(-5, -2), fmod(-5, -2));
  ck_assert_double_eq(s21_fmod(-5, INF_MINUS), fmod(-5, INF_MINUS));
  ck_assert_double_nan(s21_fmod(1, 0));
  ck_assert_double_nan(s21_fmod(S21_NAN, -1));
  ck_assert_double_nan(s21_fmod(1, S21_NAN));
  ck_assert_double_nan(s21_fmod(INF_PLUS, 2));
}
END_TEST

/*
 *************************************************************************
  TEST EXP
 *************************************************************************
*/

START_TEST(s21_test_exp1) {
  double i = -42;
  while (i < 42) {
    double x = s21_exp(i);
    double y = exp(i);
    ck_assert_double_eq_tol(x, y, 1e-6);
    i += 0.5;
  }
}
END_TEST

START_TEST(s21_test_exp2) {
  double i = -7;
  while (i < 7) {
    double x = s21_exp(i);
    double y = exp(i);
    ck_assert_double_eq_tol(x, y, 1e-6);
    i += 0.21;
  }
}
END_TEST

START_TEST(s21_test_exp3) {
  ck_assert_double_nan(s21_exp(S21_NAN));
  ck_assert_double_eq(exp(INFINITY), s21_exp(INF_PLUS));
  ck_assert_double_eq(exp(-INFINITY), s21_exp(INF_MINUS));
  ck_assert_double_eq(exp(-INFINITY), s21_exp(INF_MINUS));
  ck_assert_double_eq(exp(0), s21_exp(0));
}
END_TEST

/*
*************************************************************************
 TEST LOG
*************************************************************************
*/

START_TEST(s21_test_log1) {
  double edge_cases[6] = {S21_NAN, INF_PLUS, INF_MINUS, 1.0, -1.0, -1e-6};
  // double example;
  int k = 0;
  while (k < 6) {
    long double s21_result = s21_log(edge_cases[k]);
    long double result = log(edge_cases[k]);
    if (s21_result != s21_result || result != result ||
        s21_result == INF_MINUS || result == INF_MINUS) {
      ck_assert_double_nan(s21_result);
      ck_assert_double_nan(result);
    } else if (s21_result == INF_PLUS || result == INF_PLUS) {
      ck_assert_double_eq(s21_result, result);
    } else {
      ck_assert_double_eq_tol(s21_result, result, 1e-6);
    }
    k++;
  }
}
END_TEST

START_TEST(s21_test_log2) {
  for (int k = 200; k <= 5000; k += 200) {
    long double s21_result = s21_log(k);
    long double result = log(k);
    ck_assert_double_eq_tol(s21_result, result, 1e-6);
  }
}
END_TEST

START_TEST(s21_test_log3) {
  ck_assert_double_nan(log(-2.0));
  ck_assert_double_nan(s21_log(-2.0));
  ck_assert_double_eq_tol(log(16.12), s21_log(16.12), 1e-6);
  ck_assert_double_eq_tol(log(166.12), s21_log(166.12), 1e-6);
  ck_assert_double_eq_tol(log(126.12), s21_log(126.12), 1e-6);
  ck_assert_double_infinite(s21_log(0.0));
  ck_assert_double_infinite(log(0.0));
}
END_TEST

/*
 *************************************************************************
  TEST SQRT
 *************************************************************************
*/

START_TEST(s21_test_sqrt1) {
  ck_assert_double_nan(s21_sqrt(-1));
  ck_assert_double_nan(s21_sqrt(-22));
  ck_assert_double_nan(s21_sqrt(INF_MINUS));
  ck_assert_double_nan(s21_sqrt(S21_NAN));
  ck_assert_double_nan(sqrt(NAN));
  ck_assert_double_eq(s21_sqrt(INF_PLUS), sqrt(INFINITY));
  ck_assert_double_eq_tol(s21_sqrt(5231), sqrt(5231), 1e-6);
}
END_TEST

START_TEST(s21_test_sqrt2) {
  double i = 0.0;
  while (i < 20) {
    double x = s21_sqrt(i);
    double y = sqrt(i);
    ck_assert_double_eq_tol(x, y, 1e-6);
    i += 0.8;
  }
}
END_TEST

/*
 *************************************************************************
  TEST POW
 *************************************************************************
*/

START_TEST(s21_test_pow1) {
  ck_assert_double_eq_tol(s21_pow(1.0, 0.0), pow(1.0, 0.0), S21_EPS);
  ck_assert_double_eq_tol(s21_pow(-1.0, 0.0), pow(-1.0, 0.0), S21_EPS);
  ck_assert_double_eq_tol(s21_pow(INF_PLUS, 0.0), pow(INF_PLUS, 0.0), S21_EPS);
  ck_assert_double_eq_tol(s21_pow(INF_MINUS, 0.0), pow(INF_MINUS, 0.0),
                          S21_EPS);
  ck_assert_double_eq_tol(s21_pow(2.0, -3.0), pow(2.0, -3.0), S21_EPS);
  ck_assert_double_eq_tol(s21_pow(2.0, 100.0), pow(2.0, 100.0), S21_EPS);
  ck_assert_double_eq_tol(s21_pow(-2.0, 101.0), pow(-2.0, 101.0), S21_EPS);
  ck_assert_double_eq_tol(s21_pow(0.50, 0.), pow(0.50, 0.), S21_EPS);
  ck_assert_double_eq_tol(s21_pow(INF_PLUS, 0.), pow(INF_PLUS, 0.), S21_EPS);
  ck_assert_double_eq_tol(s21_pow(INF_PLUS, -2.0), pow(INF_PLUS, -2.0),
                          S21_EPS);
  ck_assert_double_eq(s21_pow(0.0, -0.5), pow(0.0, -0.5));
  ck_assert_double_eq(s21_pow(-1., INF_PLUS), pow(-1., INF_PLUS));
  ck_assert_double_eq(s21_pow(-1., INF_MINUS), pow(-1., INF_MINUS));
  ck_assert_double_eq(s21_pow(-0.50, INF_PLUS), pow(-0.50, INF_PLUS));
  ck_assert_double_eq(s21_pow(0.50, INF_MINUS), pow(0.50, INF_MINUS));
  ck_assert_double_eq(s21_pow(INF_PLUS, 1.0), pow(INF_PLUS, 1.0));
  ck_assert_double_eq(s21_pow(INF_PLUS, -1.0), pow(INF_PLUS, -1.0));
  ck_assert_double_eq(s21_pow(INF_MINUS, 1.0), pow(INF_MINUS, 1.0));
  ck_assert_double_eq(s21_pow(INF_MINUS, -1.0), pow(INF_MINUS, -1.0));
  ck_assert_double_eq(s21_pow(INF_MINUS, 0.0), pow(INF_MINUS, 0.0));
  ck_assert_double_nan(s21_pow(-2.0, 0.5));
  ck_assert_double_nan(s21_pow(S21_NAN, -2.0));
  ck_assert_double_nan(s21_pow(INF_PLUS, S21_NAN));

  double edge_cases[7] = {S21_NAN, INF_PLUS, INF_MINUS, 1.0, -1.0, -1e-6, 0.0};
  long double s21_result, result;

  s21_result = s21_pow(edge_cases[0], edge_cases[0]);
  ck_assert_double_nan(s21_result);

  s21_result = s21_pow(edge_cases[1], edge_cases[1]);
  result = pow(edge_cases[1], edge_cases[1]);
  ck_assert_double_eq(s21_result, result);

  s21_result = s21_pow(edge_cases[2], edge_cases[2]);
  ck_assert_double_eq(s21_result, 0);

  s21_result = s21_pow(edge_cases[3], edge_cases[3]);
  result = pow(edge_cases[3], edge_cases[3]);
  ck_assert_double_eq_tol(s21_result, result, S21_EPS);

  s21_result = s21_pow(edge_cases[4], edge_cases[4]);
  result = pow(edge_cases[4], edge_cases[4]);
  ck_assert_double_eq_tol(s21_result, result, S21_EPS);

  s21_result = s21_pow(edge_cases[6], edge_cases[6]);
  result = pow(edge_cases[6], edge_cases[6]);
  ck_assert_double_eq(s21_result, result);
}
END_TEST

/*
 ************************************************************************************************
                                         TRIGONOMETRIC
                                         FUNCTIONS
 ************************************************************************************************
*/

/*
 *************************************************************************
  TEST SIN
 *************************************************************************
*/

START_TEST(s21_test_sin) {
  ck_assert_double_eq_tol(s21_sin(S21_PI), sin(S21_PI), 1e-6);
  ck_assert_double_eq_tol(s21_sin(S21_PI / 2), sin(S21_PI / 2), 1e-6);
  ck_assert_double_eq_tol(s21_sin(0), sin(0), 1e-6);
  ck_assert_double_eq_tol(s21_sin(S21_PI / 6), sin(S21_PI / 6), 1e-6);
  ck_assert_double_eq_tol(s21_sin(2 * S21_PI / 3), sin(2 * S21_PI / 3), 1e-6);
  ck_assert_double_eq_tol(s21_sin(2 * S21_PI), sin(2 * S21_PI), 1e-6);
  ck_assert_double_eq_tol(s21_sin(3 * S21_PI), sin(3 * S21_PI), 1e-6);
  ck_assert_double_eq_tol(s21_sin(-3 * S21_PI), sin(-3 * S21_PI), 1e-6);
  ck_assert_double_nan(s21_sin(S21_NAN));
  ck_assert_double_nan(sin(NAN));
  ck_assert_double_nan(s21_sin(INF_PLUS));
  ck_assert_double_nan(sin(INF_PLUS));
  ck_assert_double_nan(s21_sin(INF_MINUS));
  ck_assert_double_nan(sin(INF_MINUS));
}
END_TEST

/*
 *************************************************************************
  TEST COS
 *************************************************************************
*/

START_TEST(s21_test_cos) {
  ck_assert_double_eq_tol(s21_cos(S21_PI), cos(S21_PI), 1e-6);
  ck_assert_double_eq_tol(s21_cos(S21_PI / 2), cos(S21_PI / 2), 1e-6);
  ck_assert_double_eq_tol(s21_cos(0), cos(0), 1e-6);
  ck_assert_double_eq_tol(s21_cos(S21_PI / 6), cos(S21_PI / 6), 1e-6);
  ck_assert_double_eq_tol(s21_cos(2 * S21_PI / 3), cos(2 * S21_PI / 3), 1e-6);
  ck_assert_double_eq_tol(s21_cos(2 * S21_PI), cos(2 * S21_PI), 1e-6);
  ck_assert_double_eq_tol(s21_cos(3 * S21_PI), cos(3 * S21_PI), 1e-6);
  ck_assert_double_eq_tol(s21_cos(-3 * S21_PI), cos(-3 * S21_PI), 1e-6);
  ck_assert_double_nan(s21_cos(S21_NAN));
  ck_assert_double_nan(cos(NAN));
  ck_assert_double_nan(s21_cos(INF_PLUS));
  ck_assert_double_nan(cos(INF_PLUS));
  ck_assert_double_nan(s21_cos(INF_MINUS));
  ck_assert_double_nan(cos(INF_MINUS));
}
END_TEST

/*
 *************************************************************************
  TEST TAN
 *************************************************************************
*/

START_TEST(s21_test_tan) {
  ck_assert_double_eq_tol(s21_tan(S21_PI), tan(S21_PI), 1e-6);
  ck_assert_double_eq_tol(s21_tan(0), tan(0), 1e-6);
  ck_assert_double_eq_tol(s21_tan(S21_PI / 6), tan(S21_PI / 6), 1e-6);
  ck_assert_double_eq_tol(s21_tan(2 * S21_PI / 3), tan(2 * S21_PI / 3), 1e-6);
  ck_assert_double_eq_tol(s21_tan(2 * S21_PI), tan(2 * S21_PI), 1e-6);
  ck_assert_double_nan(s21_tan(S21_NAN));
  ck_assert_double_nan(tan(NAN));
  ck_assert_double_nan(s21_tan(INF_PLUS));
  ck_assert_double_nan(tan(INF_PLUS));
  ck_assert_double_nan(s21_tan(INF_MINUS));
  ck_assert_double_nan(tan(INF_MINUS));
}
END_TEST

/*
 *************************************************************************
  TEST ASIN
 *************************************************************************
*/

START_TEST(s21_test_asin) {
  ck_assert_double_nan(s21_asin(1.5));
  ck_assert_double_nan(asin(1.5));
  ck_assert_double_nan(s21_asin(-1.5));
  ck_assert_double_nan(asin(-1.5));
  ck_assert_double_nan(s21_asin(S21_NAN));
  ck_assert_double_nan(asin(NAN));
  ck_assert_double_eq_tol(s21_asin(1), asin(1), 1e-6);
  ck_assert_double_eq_tol(s21_asin(-1), asin(-1), 1e-6);
  ck_assert_double_eq_tol(s21_asin(0.15), asin(0.15), 1e-6);
  ck_assert_double_eq_tol(s21_asin(-0.15), asin(-0.15), 1e-6);
  ck_assert_double_eq_tol(s21_asin(0.5), asin(0.5), 1e-6);
  ck_assert_double_eq_tol(s21_asin(-0.5), asin(-0.5), 1e-6);
  ck_assert_double_eq_tol(s21_asin(0), asin(0), 1e-6);
}
END_TEST

/*
 *************************************************************************
  TEST ACOS
 *************************************************************************
*/

START_TEST(s21_test_acos) {
  ck_assert_double_eq_tol(s21_acos(1), acos(1), 1e-6);
  ck_assert_double_eq_tol(s21_acos(-1), acos(-1), 1e-6);
  ck_assert_double_eq_tol(s21_acos(0.4), acos(0.4), 1e-6);
  ck_assert_double_eq_tol(s21_acos(-0.4), acos(-0.4), 1e-6);
  ck_assert_double_nan(s21_acos(1.4));
  ck_assert_double_nan(acos(1.4));
  ck_assert_double_nan(s21_acos(-1.4));
  ck_assert_double_nan(acos(-1.4));
  ck_assert_double_nan(s21_acos(S21_NAN));
  ck_assert_double_nan(acos(NAN));
  ck_assert_double_eq_tol(s21_acos(0), acos(0), 1e-6);
}
END_TEST

/*
 *************************************************************************
  TEST ATAN
 *************************************************************************
*/

START_TEST(s21_test_atan) {
  ck_assert_double_nan(s21_atan(S21_NAN));
  ck_assert_double_nan(atan(NAN));
  ck_assert_double_eq_tol(s21_atan(INF_PLUS), atan(INF_PLUS), 1e-6);
  ck_assert_double_eq_tol(s21_atan(INF_MINUS), atan(INF_MINUS), 1e-6);
  ck_assert_double_eq_tol(s21_atan(0), atan(0), 1e-6);
  ck_assert_double_eq_tol(s21_atan(1), atan(1), 1e-6);
  ck_assert_double_eq_tol(s21_atan(-1), atan(-1), 1e-6);
  ck_assert_double_eq_tol(s21_atan(-0.5), atan(-0.5), 1e-6);
  ck_assert_double_eq_tol(s21_atan(0.5), atan(0.5), 1e-6);
  ck_assert_double_eq_tol(s21_atan(-1.5), atan(-1.5), 1e-6);
  ck_assert_double_eq_tol(s21_atan(1.5), atan(1.5), 1e-6);
}
END_TEST

/*
 *************************************************************************
  TEST CASES
 *************************************************************************
*/

TCase *s21_math_tcases_create() {
  TCase *tcase_math_main = tcase_create("main test for s21_math");
  tcase_add_test(tcase_math_main, s21_test_abs);
  tcase_add_test(tcase_math_main, s21_test_fabs);
  tcase_add_test(tcase_math_main, s21_test_ceil);
  tcase_add_test(tcase_math_main, s21_test_floor);
  tcase_add_test(tcase_math_main, s21_test_fmod);
  tcase_add_test(tcase_math_main, s21_test_exp1);
  tcase_add_test(tcase_math_main, s21_test_exp2);
  tcase_add_test(tcase_math_main, s21_test_exp3);
  tcase_add_test(tcase_math_main, s21_test_sqrt1);
  tcase_add_test(tcase_math_main, s21_test_sqrt2);
  tcase_add_test(tcase_math_main, s21_test_pow1);
  tcase_add_test(tcase_math_main, s21_test_log1);
  tcase_add_test(tcase_math_main, s21_test_log2);
  tcase_add_test(tcase_math_main, s21_test_log3);
  tcase_add_test(tcase_math_main, s21_test_sin);
  tcase_add_test(tcase_math_main, s21_test_cos);
  tcase_add_test(tcase_math_main, s21_test_tan);
  tcase_add_test(tcase_math_main, s21_test_asin);
  tcase_add_test(tcase_math_main, s21_test_acos);
  tcase_add_test(tcase_math_main, s21_test_atan);
  return tcase_math_main;
}

/*
 *************************************************************************
  TEST SUIT
 *************************************************************************
*/

Suite *s21_math_suite_create() {
  Suite *s21_math_test_suite = suite_create("s21_math");
  suite_add_tcase(s21_math_test_suite, s21_math_tcases_create());
  return s21_math_test_suite;
}

/*
 *************************************************************************
  MAIN
 *************************************************************************
*/

int main() {
  Suite *test_suite = s21_math_suite_create();
  SRunner *suite_runner = srunner_create(test_suite);

  srunner_run_all(suite_runner, CK_NORMAL);

  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  if (failed_count != 0) {
    return 1;
  }
  return 0;
}
