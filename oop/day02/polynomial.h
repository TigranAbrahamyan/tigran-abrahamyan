
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

class Polynomial {
  private:
    double* _coefficents;
    int _degree;

  public:
    Polynomial(double*, int);
    Polynomial();
    ~Polynomial();

    Polynomial add(Polynomial);
    Polynomial operator+(Polynomial);
    Polynomial operator+=(Polynomial);

    Polynomial subtract(Polynomial);
    Polynomial operator-(Polynomial);
    Polynomial operator-=(Polynomial);

    Polynomial multiply(Polynomial);
    Polynomial operator*(Polynomial);
    Polynomial operator*=(Polynomial);

    friend std::ostream &operator<<(std::ostream&, const Polynomial&);

    void print();
};

#endif
