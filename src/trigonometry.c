#include "trigonometry.h"
#include "constants.h"
#include <stdbool.h>

/*
 * Return the remainder of the Euclidean division of the numerator by the
 * modulus.
 */
double modulo(double numerator, double modulus) {
  // Modulo by zero is undefined.
  if (modulus == 0.0) {
    return 0.0 / 0.0; // returns NaN.
  }

  // Compute quotient and truncate towards 0.
  int quotient = (int)(numerator / modulus);

  // Compute and return the remainder.
  return numerator - (quotient * modulus);
}

double get_tessela_sin(double x) {
  // Find the coterminal angle of x over [0, 2pi).
  x = modulo(x, (2 * PI));
  // If the coterminal is negative, add 2pi to make it positive.
  if (x < 0) {
    x += (2 * PI);
  }

  double result = x;
  double term = x;
  int sign = -1;

  // Get result of the Maclaurin series of sin(x) to an accuracy of 20 terms.
  for (int i = 3; i < 40; i++) {
    term *= x * x / (i * (i - 1)); // Equivalent to x^i / i!.
    result +=
        (term *
         sign);   // Apply the sign to the term and add the term to the result.
    sign = -sign; // Flip sign.
  }
  return result;
}
