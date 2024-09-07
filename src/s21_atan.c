#include "s21_math.h"

long double s21_atan(double x) {
  long double res = 0.;
  if (x != x) {
    res = S21_NAN;
  } else if (x == INF_PLUS || x == INF_MINUS) {
    if (x == INF_PLUS) {
      res = S21_PI / 2;
    } else
      res = -S21_PI / 2;
  } else {
    if ((x == 1 || x == -1)) {
      if (x == 1) {
        res = S21_PI / 4;
      } else
        res = -S21_PI / 4;
    } else if (x < 1. && x > -1.) {
      for (int i = 0; i < 6000; i++) {
        res += (s21_pow(-1, i) * s21_pow(x, (1 + (2 * i))) / (1 + (2 * i)));
      }
    } else {
      for (int i = 0; i < 6000; i++) {
        res += (s21_pow(-1, i) * s21_pow(x, (-1 - (2 * i))) / (1 + (2 * i)));
      }
      res = (S21_PI * s21_fabs(res) / (2 * res) - res);
    }
  }

  return res;
}
