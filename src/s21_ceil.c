#include "s21_math.h"

long double s21_ceil(double x) {
  long double ceil_result = (long long int)x;
  if (x == INF_PLUS) {
    ceil_result = INF_PLUS;
  } else if (x == INF_MINUS) {
    ceil_result = INF_MINUS;
  } else if (x != x) {
    ceil_result = S21_NAN;
  } else if ((x - (long long int)x) == 0) {
  } else if (x > 0.0) {
    ceil_result += 1;
  }
  return ceil_result;
}