#include <iostream>
#include <math.h>
#include "./polynomial.h"

Polynomial::Polynomial(double* coefficents, int degree) {
  _degree = degree;
  _coefficents = new double[degree];
  for (int i = 0; i < degree; i++) {
    _coefficents[i] = coefficents[i];
  }
}

Polynomial::Polynomial() {
  _degree = 0;
  _coefficents = NULL;
}

Polynomial::~Polynomial() {
  delete[] _coefficents;
}

/* ---Add--- */
Polynomial Polynomial::add(Polynomial second) {
  int maxDegree = std::max(_degree, second._degree);
  double* result = new double[maxDegree];

  for (int i = 0; i < maxDegree; i++) {
    result[i] = _coefficents[i] + second._coefficents[i];
  }

  return Polynomial(result, maxDegree);
}

Polynomial Polynomial::operator+(Polynomial second) {
  int maxDegree = std::max(this->_degree, second._degree);
  double* result = new double[maxDegree];

  for (int i = 0; i < maxDegree; i++) {
    result[i] = this->_coefficents[i] + second._coefficents[i];
  }

  return Polynomial(result, maxDegree);
}

Polynomial Polynomial::operator+=(Polynomial second) {
  *this = *this + second;
  return *this;
}
/* ---Add--- */

/* ---Subtract--- */
Polynomial Polynomial::subtract(Polynomial second) {
  int maxDegree = std::max(_degree, second._degree);
  double* result = new double[maxDegree];

  for (int i = 0; i < maxDegree; i++) {
    result[i] = _coefficents[i] - second._coefficents[i];
  }

  return Polynomial(result, maxDegree);
}

Polynomial Polynomial::operator-(Polynomial second) {
  int maxDegree = std::max(this->_degree, second._degree);
  double* result = new double[maxDegree];

  for (int i = 0; i < maxDegree; i++) {
    result[i] = this->_coefficents[i] - second._coefficents[i];
  }

  return Polynomial(result, maxDegree);
}

Polynomial Polynomial::operator-=(Polynomial second) {
  *this = *this - second;
  return *this;
}
/* ---Subtract--- */

/* ---Multiply--- */
Polynomial Polynomial::multiply(Polynomial second) {
  int maxDegree = std::max(_degree, second._degree);
  double* result = new double[maxDegree];

  for (int i = 0; i < maxDegree; i++) {
    result[i] = _coefficents[i] * second._coefficents[i];
  }

  return Polynomial(result, maxDegree);
}

Polynomial Polynomial::operator*(Polynomial second) {
  int maxDegree = std::max(this->_degree, second._degree);
  double* result = new double[maxDegree];

  for (int i = 0; i < maxDegree; i++) {
    result[i] = this->_coefficents[i] * second._coefficents[i];
  }

  return Polynomial(result, maxDegree);
}

Polynomial Polynomial::operator*=(Polynomial second) {
  *this = *this * second;
  return *this;
}
/* ---Multiply--- */

/* ---print--- */
std::ostream &operator<<(std::ostream &out, const Polynomial &polynomial) {
  for (int i = polynomial._degree - 1; i >= 0; i--) {
    out << "(" << polynomial._coefficents[i];
    if (i != 0) {
      out << "x^" << i << ")+";
    }
  }

  out << ")";

  return out;
}

void Polynomial::print() {
  for (int i = _degree - 1; i >= 0; i--) {
    std::cout << "(" << _coefficents[i];
    if (i != 0) {
      std::cout << "x^" << i << ")+";
    }
  }

  std::cout << ")";
}
/* ---print--- */
