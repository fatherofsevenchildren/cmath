#include "s21_math.h"

long double s21_sqrt(double x) {
  long double result = 0.0;
  if (x < 0.0 || x == INF_MINUS || x != x) {
    result = S21_NAN;
  } else if (x == 0.0) {
    result = 0.0;
  } else if (x == INF_PLUS) {
    result = INF_PLUS;
  } else {
    result = s21_pow(x, 0.5);
  }
  return result;
}