#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long long int ceil_num;
  long double result = 0.0;
  if (y == 0) {
    result = S21_NAN;
  } else if (x == INF_PLUS || x == INF_MINUS) {
    result = S21_NAN;
  } else if (x != x) {
    result = S21_NAN;
  } else if (y != y) {
    result = S21_NAN;
  } else if (y == INF_PLUS || y == INF_MINUS) {
    result = (long double)x;
  } else if (x == 0) {
    result = 0.0;
  } else {
    ceil_num = (long double)x / (long double)y;
    result = (long double)x - ((long double)y * ceil_num);
  }
  return result;
}