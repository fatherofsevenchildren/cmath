#include "s21_math.h"

long double s21_log(double x) {
  int e_count = 0;
  double compare;
  double result = 0;
  if (x == (INF_PLUS)) {
    result = INF_PLUS;
  } else if (x == 0.0) {
    result = INF_MINUS;
  } else if (x < 0.0) {
    result = S21_NAN;
  } else {
    while (x >= S21_E) {
      x = x / S21_E;
      e_count += 1;
    }
    int i = 0;
    while (i < 100) {
      compare = result;
      result = compare + 2 * (x - s21_exp(compare)) / (x + s21_exp(compare));
      i++;
    }
  }
  return (result + e_count);
}