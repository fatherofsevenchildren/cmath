// #include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define S21_IS_NAN(x) __builtin_isnan(x)
#define S21_IS_INF(x) __builtin_isinf_sign(x)
#define S21_IS_mINF(x) -__builtin_isinf_sign(x)
#define S21_PI 3.14159265358979323846264338
#define S21_E 2.71828182845904523536028747
#define MAX_DOUBLE 1.7976931348623157E+308
#define S21_EPS 1e-6
#define INF_PLUS 1.0 / 0.0
#define INF_MINUS -1.0 / 0.0
#define S21_NAN -0.0 / 0.0

int s21_abs(int x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_floor(double x);
long double s21_fabs(double x);
long double s21_sin(double x);
long double s21_log(double x);
long double s21_exp(double x);
long double s21_sqrt(double x);
long double s21_fmod(double x, double y);
long double s21_pow(double base, double exp);
long double s21_tan(double x);
long double s21_atan(double x);
long double s21_acos(double x);
long double s21_asin(double x);
// long double reduction_sin_cos(double x);
