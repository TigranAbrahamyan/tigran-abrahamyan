#include <iostream>
#include "./polynomial.h"

Polynomial newPolynomial() {
  int degree;
  std::cout << "New polynomial degree: ";
  std::cin >> degree;

  double* arr = new double[degree];

  for (int i = degree; i >= 0; i--) {
    std::cout << "Enter coefficient of x^" << i << ": ";
    std::cin >> arr[i];
  }

  return Polynomial(arr, degree + 1);
}

int main() {
  Polynomial firstPolynomial = newPolynomial();
  Polynomial secondPolynomial = newPolynomial();
  Polynomial result;
  int polynomialOperator;

  std::cout << "1) Add" << std::endl << "2) Subtract" << std::endl << "3) Multiply" << std::endl << "Option: ";
  std::cin >> polynomialOperator;

  switch (polynomialOperator) {
    case 1:
      // result = firstPolynomial.add(secondPolynomial); // without overloading
      // result = firstPolynomial + secondPolynomial; // operator overloading +
      // result.print();
      firstPolynomial += secondPolynomial; // operator overloading +=
      std::cout << firstPolynomial; // operator overloading <<
      // firstPolynomial.print();
      break;
    case 2:
      // result = firstPolynomial.subtract(secondPolynomial); // without overloading
      // result = firstPolynomial - secondPolynomial; // operator overloading -
      // result.print();
      firstPolynomial -= secondPolynomial; // operator overloading -=
      std::cout << firstPolynomial; // operator overloading <<
      // firstPolynomial.print();
      break;
    case 3:
      // result = firstPolynomial.multiply(secondPolynomial); // without overloading
      // result = firstPolynomial * secondPolynomial; // operator overloading *
      // result.print();
      firstPolynomial *= secondPolynomial; // operator overloading *=
      std::cout << firstPolynomial; // operator overloading <<
      // firstPolynomial.print();
      break;
    default:
      std::cout << "Operator not found" << std::endl;
  }

  return 0;
}