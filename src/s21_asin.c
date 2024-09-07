#include "s21_math.h"

long double s21_asin(double x) {
  long double res = x;
  if (x != x || x > 1 || x < -1) {
    res = S21_NAN;
  } else {
    if (x == 1) {
      res = S21_PI / 2;
    } else if (x == -1) {
      res = -S21_PI / 2;
    } else if (s21_fabs(x) == 0.5) {
      res = s21_atan(s21_sqrt(1 - s21_pow(res, 2)) / res) / 2;
    } else {
      res = s21_atan(res / s21_sqrt(1 - s21_pow(res, 2)));
    }
  }
  return res;
}
