#include "s21_math.h"

long double s21_fabs(double x) {
  long double x_last = (long double)x;
  if (x != x) {
    x_last = S21_NAN;
  } else if (x_last < 0) {
    x_last = -x_last;
  }
  return x_last;
}