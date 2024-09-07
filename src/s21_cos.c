#include "s21_math.h"

long double s21_cos(double x) {
  long double result;
  if (x < 2 * S21_PI || x > 2 * S21_PI) x = s21_fmod(x, 2 * S21_PI);
  result = s21_sqrt(1.0 - s21_pow(s21_sin(x), 2));
  if ((x < -S21_PI * 0.5 && x > -S21_PI * 1.5) ||
      (x > S21_PI * 0.5 && x < S21_PI * 1.5))
    result = -result;
  if (s21_fabs(x) == 1.5 * S21_PI) result = -0.0;
  return result;
}