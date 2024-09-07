#include "s21_math.h"

long double s21_exp(double x) {
  long double add = 1.0;
  long double result = 1.0;
  long double copy_x = x;
  if (x == INF_MINUS) {
    result = 0.0;
  } else if (x == INF_PLUS) {
    result = 1.0 / 0.0;
  } else if (x != x) {
    result = S21_NAN;
  } else {
    if (x < 0) {
      copy_x = -copy_x;
    }
    for (long double i = 1; s21_fabs(add) > 1e-21 && result != INF_PLUS;
         i += 1) {
      add *= (copy_x / i);
      result += add;
    }
    if (x < 0 && result < MAX_DOUBLE) {
      result = 1.0 / result;
    }
  }
  return result;
}
