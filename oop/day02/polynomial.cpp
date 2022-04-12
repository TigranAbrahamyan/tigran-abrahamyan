#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Polynomial {
  private:
    int _numberOfPolynomials;
    int _x;

  public:
    Polynomial(int numberOfPolynomials, int x) {
      _numberOfPolynomials = numberOfPolynomials;
      _x = x;
    }

    int add() {
      cout << endl << "Add.." << endl;
      int numberOfPolynomials = _numberOfPolynomials;
      int result = 0;
      string polynomialExpression;

      while (numberOfPolynomials > -1) {
        int n;
        cout << "a[" << numberOfPolynomials << "] = ";
        cin >> n;

        result += (n * pow(_x, numberOfPolynomials));
        polynomialExpression += ("(" + to_string(n) + "*x^" + to_string(numberOfPolynomials) + ")" + "+");
        numberOfPolynomials--;
      }

      cout << polynomialExpression.substr(0, polynomialExpression.length() - 1) << " = ";

      return result;
    }

    int subtract() {
      cout << endl << "Subtract.." << endl;
      int numberOfPolynomials = _numberOfPolynomials;
      int result = 0;
      string polynomialExpression;

      while (numberOfPolynomials > -1) {
        int n;
        cout << "a[" << numberOfPolynomials << "] = ";
        cin >> n;

        result -= (n * pow(_x, numberOfPolynomials));
        polynomialExpression += ("(" + to_string(n) + "*x^" + to_string(numberOfPolynomials) + ")" + "-");
        numberOfPolynomials--;
      }

      cout << polynomialExpression.substr(0, polynomialExpression.length() - 1) << " = ";

      return result;
    }

    int multiply() {
      cout << endl << "Multiply.." << endl;
      int numberOfPolynomials = _numberOfPolynomials;
      int result = 1;
      string polynomialExpression;

      while (numberOfPolynomials > -1) {
        int n;
        cout << "a[" << numberOfPolynomials << "] = ";
        cin >> n;

        result *= (n * pow(_x, numberOfPolynomials));
        polynomialExpression += ("(" + to_string(n) + "*x^" + to_string(numberOfPolynomials) + ")" + "*");
        numberOfPolynomials--;
      }

      cout << polynomialExpression.substr(0, polynomialExpression.length() - 1) << " = ";

      return result;
    }
};

int main() {
  int numberOfPolynomials;
  int x;

  cout << "Input number of polynomials: ";
  cin >> numberOfPolynomials;

  cout << "Input x: ";
  cin >> x;

  Polynomial* polynomial = new Polynomial(numberOfPolynomials, x);
  cout << polynomial->add() << endl;
  cout << polynomial->subtract() << endl;
  cout << polynomial->multiply() << endl;

  return 0;
}
