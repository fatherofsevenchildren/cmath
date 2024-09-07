#include "s21_math.h"

long double s21_acos(double x) {
  long double res = x;
  if (x != x || x > 1 || x < -1) {
    res = S21_NAN;
  } else {
    if (x > 0) {
      res = s21_atan(((s21_sqrt(1 - s21_pow(res, 2)) / res)));

    } else if (x < 0) {
      res = S21_PI + s21_atan(((s21_sqrt(1 - s21_pow(res, 2)) / res)));
    } else {
      res = S21_PI / 2;
    }
  }
  return res;
}
