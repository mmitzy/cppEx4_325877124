#include <iostream>

class Complex {
public:
    double real;
    double imag;

    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    bool operator>(const Complex& other) const {
        return (real * real + imag * imag) > (other.real * other.real + other.imag * other.imag);
    }

    bool operator<(const Complex& other) const {
        return (real * real + imag * imag) < (other.real * other.real + other.imag * other.imag);
    }

    bool operator==(const Complex& other) const {
        return (real == other.real && imag == other.imag);
    }

    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.real << " + " << c.imag << "i";
        return os;
    }
};
