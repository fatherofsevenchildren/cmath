#include "s21_math.h"

long double fact(int x) {
  long double res = x;
  for (int i = 1; i < x; i++) res *= x - i;
  return res;
}
long double s21_sin(double x) {
  if (x < 2 * S21_PI || x > 2 * S21_PI) x = s21_fmod(x, 2 * S21_PI);
  long double res = 0;
  for (int i = 0; i < 100; i++) {
    res += (s21_pow(-1, i) * s21_pow(x, 2.0000 * i + 1.0000)) /
           fact(2.0000 * i + 1.0000);
  }
  return res;
}
