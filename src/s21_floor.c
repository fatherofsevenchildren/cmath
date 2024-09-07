#include "s21_math.h"

long double s21_floor(double x) {
  long long int buff = (long double)x;
  long double x_last = (long double)x;
  if (x == INF_PLUS) {
    x_last = INF_PLUS;
  } else if (x == INF_MINUS) {
    x_last = INF_MINUS;
  } else if (x != x) {
    x_last = S21_NAN;
  } else {
    if (x > 0.) {
      x_last = buff;
    } else if (x_last < 0. && x_last != (long long int)x) {
      x_last -= 1.;
      x_last = (long long int)x_last;
    }
  }
  return x_last;
}