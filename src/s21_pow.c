#include "s21_math.h"

long double s21_pow(double base, double exp) {
  long double result = 1.0;
  if (base != base && exp != exp) {
    result = S21_NAN;
  } else if (base == 0. && (exp < 0. || exp > 0.) && !(exp != exp)) {
    if (exp > 0.) {
      result = 0.0;
    } else {
      result = INF_PLUS;
    }
  } else if (base == 0. && exp == 0.) {
    result = 1.;
  } else if (base == -1. && (exp == INF_PLUS || exp == INF_MINUS)) {
    result = 1.;
  } else if (base < 0. && exp > 0. && exp < 1.) {
    result = S21_NAN;
  } else if (base == 1. && (exp != exp || exp == INF_PLUS || exp == INF_MINUS ||
                            exp == 0. || exp != 0)) {
    result = 1.;
  } else if ((base != base || base == INF_PLUS || base == INF_MINUS) &&
             exp == 0.) {
    result = 1.;
  } else if ((base < 1. && base > -1.) &&
             (exp == INF_PLUS || exp == INF_MINUS)) {
    if (exp == INF_PLUS) {
      result = 0.0;
    } else if (exp == INF_MINUS) {
      result = INF_PLUS;
    }
  } else if ((base > 1. || base < -1.) &&
             (exp == INF_PLUS || exp == INF_MINUS)) {
    if (exp == INF_MINUS) {
      result = 0.;
    } else if (exp == INF_PLUS) {
      result = INF_PLUS;
    }
  } else if ((base == INF_PLUS || base == INF_MINUS)) {
    if (exp != exp) {
      result = S21_NAN;
    } else {
      if ((exp < 1. && exp > -1.) && (base == INF_PLUS || base == INF_MINUS)) {
        if (exp > 0.) {
          result = INF_PLUS;
        } else {
          result = 0.0;
        }
      } else if ((exp > 1. || exp < -1) &&
                 (base == INF_PLUS || base == INF_MINUS)) {
        if (exp > 0.) {
          result = INF_PLUS;
        } else {
          result = 0.0;
        }
      } else if ((exp == 1 || exp == -1) &&
                 (base == INF_PLUS || base == INF_MINUS)) {
        if (base == INF_PLUS && exp == 1) {
          result = INF_PLUS;
        } else if (exp == 1 && base == INF_MINUS) {
          result = INF_MINUS;
        } else if (exp == -1 && base == INF_PLUS) {
          result = 0.0;
        } else if (exp == -1 && base == INF_MINUS) {
          result = -0.0;
        }
      }
    }
  } else if (s21_fmod(s21_fabs(exp), 1.0) < 1e-18) {
    double k = s21_fabs(exp);
    while (k > 0) {
      result *= base;
      k--;
    }
    if (exp < 0) {
      result = 1. / result;
    }
  } else {
    if (base > 0) {
      result = s21_exp(exp * s21_log(base));
    }
  }
  return result;
}

// long double proverka(double base, double exp) {
//   long double result = 2.0;
//   if (base != base && exp != exp) {
//     result = S21_NAN;
//   } else if (base == 0. && (exp < 0. || exp > 0.) && !(exp != exp)) {
//     if (exp > 0.) {
//       result = 0.0;
//     } else {
//       result = INF_PLUS;
//     }
//   } else if (base == 0. && exp == 0.) {
//     result = 1.;
//   } else if (base == -1. && (exp == INF_PLUS || exp == INF_MINUS)) {
//     result = 1.;
//   } else if (base < 0. && exp > 0. && exp < 1.) {
//     result = S21_NAN;
//   } else if (base == 1. && (exp != exp || exp == INF_PLUS || exp == INF_MINUS
//   ||
//                             exp == 0. || exp != 0)) {
//     result = 1.;
//   } else if ((base != base || base == INF_PLUS || base == INF_MINUS) &&
//              exp == 0.) {
//     result = 1.;
//   } else if ((base < 1. && base > -1.) &&
//              (exp == INF_PLUS || exp == INF_MINUS)) {
//     if (exp == INF_PLUS) {
//       result = 0.0;
//     } else if (exp == INF_MINUS) {
//       result = INF_PLUS;
//     }
//   } else if ((base > 1. || base < -1.) &&
//              (exp == INF_PLUS || exp == INF_MINUS)) {
//     if (exp == INF_MINUS) {
//       result = 0.;
//     } else if (exp == INF_PLUS) {
//       result = INF_PLUS;
//     }
//   } else if ((base == INF_PLUS || base == INF_MINUS)) {
//     result = proverka_long(base, exp);
//   }
//   return result;
// }

// long double proverka_long(double base, double exp) {
//   long double result = 2.0;
//       if (exp != exp) {
//       result = S21_NAN;
//     } else {
//       if ((exp < 1. && exp > -1.) && (base == INF_PLUS || base == INF_MINUS))
//       {
//         if (exp > 0.) {
//           result = INF_PLUS;
//         } else {
//           result = 0.0;
//         }
//       } else if ((exp > 1. || exp < -1) &&
//                  (base == INF_PLUS || base == INF_MINUS)) {
//         if (exp > 0.) {
//           result = INF_PLUS;
//         } else {
//           result = 0.0;
//         }
//       } else if ((exp == 1 || exp == -1) &&
//                  (base == INF_PLUS || base == INF_MINUS)) {
//         if (base == INF_PLUS && exp == 1) {
//           result = INF_PLUS;
//         } else if (exp == 1 && base == INF_MINUS) {
//           result = INF_MINUS;
//         } else if (exp == -1 && base == INF_PLUS) {
//           result = 0.0;
//         } else if (exp == -1 && base == INF_MINUS) {
//           result = -0.0;
//         }
//       }
//     }
//     return result;
// }
// long double s21_pow(double base, double exp) {
//   long double result = proverka(base, exp);
//   if(result == 2.0) {
//   if (s21_fmod(s21_fabs(exp), 1.0) < 1e-18) {
//     double k = s21_fabs(exp);
//     while (k > 0) {
//       result *= base;
//       k--;
//     }
//     if (exp < 0) {
//       result = 1. / result;
//     }
//   } else {
//     if (base > 0) {
//       result = s21_exp(exp * s21_log(base));
//     }
//   }
//   }
//   return result;
// }
