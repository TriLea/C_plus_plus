/*
Author: Tristan Lea
Course: CS212
Date: 5/19/22
Purpose: Implement methods, and overwrite operators to create a class for working
with complex numbers named Complex.h
*/
// #includes, NOT <complex>

#include <iostream>
#include <string>
#include <ostream>
#include <sstream>
using namespace std;

class Complex
{
public:
    //Constructors
    Complex();
    Complex(double a);
    Complex(double a, double b);

        // Member Functions
        Complex add(Complex other) const;
        Complex subtract(Complex other) const;
        Complex multiply(Complex other) const;
        Complex divide(Complex other) const;
        double abs() const;
        string to_string();
        
        double getRealPart();
        double getImaginaryPart();

    // operators
    Complex& operator+=(Complex other);
    Complex& operator-=(Complex other);
    Complex& operator*=(Complex other);
    Complex& operator/=(Complex other);
    double& operator[](int);
    Complex& operator +();
    Complex& operator-();
    Complex& operator++();
    Complex& operator++(int);
    Complex& operator--();
    Complex& operator--(int);


    // extraction and insertion
    friend std::istream& operator>>(std::istream& in, Complex& c);
    friend std::ostream& operator<<(std::ostream& out, Complex c);

private:
    double real;
    double imaginary;
};

// Implementations
Complex::Complex()
{
    this->real = 0;
    this->imaginary = 0;
}

Complex::Complex(double a)
{
    this->real = a;
    this->imaginary = 0;
}

Complex::Complex(double a, double b)
{
    this->real = a;
    this->imaginary = b;
}


double Complex::getRealPart()
{
    return this->real;
}
double Complex::getImaginaryPart()
{
    return this->imaginary;
}


// non-members
Complex operator+(Complex left, Complex right)
{
    return left.add(right);
}

Complex operator-(Complex left, Complex right)
{
    return left.subtract(right);
}

Complex operator*(Complex left, Complex right)
{
    return left.multiply(right);
}

Complex operator/(Complex left, Complex right)
{
    return left.divide(right);
}


// members of Complex
Complex& Complex::operator+=(Complex other)
{
    this->real += other.real;
    this->imaginary += other.imaginary;

    return *this;
}

Complex& Complex::operator-=(Complex other)
{
    this->real -= other.real;
    this->imaginary -= other.imaginary;

    return *this;
}

Complex& Complex::operator*=(Complex other)
{
    double rNums = (this->real * other.real) - (this->imaginary * other.imaginary);
    double iNums = (this->real * other.imaginary) + (this->imaginary * other.real);

    this->real = rNums;
    this->imaginary = iNums;

    return *this;
}

Complex& Complex::operator/=(Complex other)
{
    Complex denomMulti(other.real, -other.imaginary);
    Complex denomByDenom = other.multiply(denomMulti);
    Complex numerByDenom = this->multiply(denomMulti);

    this->real = numerByDenom.real / denomByDenom.real;
    this->imaginary = numerByDenom.imaginary / numerByDenom.real;
    
    return *this;
}

double& Complex::operator[](int nSubscript)
{
    if (nSubscript == 0 ) 
    {
        return this->real;
    }
    else if (nSubscript == 1)
    {
        return this->imaginary;
    }
    else
    {
        throw NULL;
    }
}

Complex& Complex::operator+()
{
    return *this;
}

Complex& Complex::operator-()
{
    Complex temp(-this->real, -this->imaginary);

    return temp;
}

Complex& Complex::operator++()
{
    this->real = this->real + 1;

    return *this;
}

Complex& Complex::operator++(int)
{   
    Complex temp(this->real, this->imaginary);
    this->real = this->real + 1;

    return temp;
}

Complex& Complex::operator--()
{
    this->real = this->real - 1;

    return *this;
}

Complex& Complex::operator--(int)
{
    Complex temp(this->real, this->imaginary);
    this->real = this->real - 1;

    return temp;
}


Complex Complex::add(Complex other) const
{
    return Complex(this->real + other.real, 
        this->imaginary + other.imaginary);
}

Complex Complex::subtract(Complex other) const
{
    return Complex(this->real - other.real, 
        this->imaginary - other.imaginary);
}

Complex Complex::multiply(Complex other) const
{

    double rNums = (this->real * other.real) - (this->imaginary * other.imaginary);
    double iNums = (this->real * other.imaginary) + (this->imaginary * other.real);
    
    return Complex(rNums, iNums);
}

Complex Complex::divide(Complex other) const
{

    Complex denomMulti(other.real , -other.imaginary);
    Complex denomByDenom = other.multiply(denomMulti);
    Complex numerByDenom = this->multiply(denomMulti);

    return Complex(numerByDenom.real / denomByDenom.real, numerByDenom.imaginary / denomByDenom.real);
}

double Complex::abs() const
{
    return sqrt(this->real * this->real + this->imaginary * this->imaginary);
}

string Complex::to_string()
{
    std::ostringstream out;

    if (this->imaginary != 0) 
    {
        out << real << " + " << imaginary << "i";
    }
    else
    {
        out << real;
    }

    return out.str();
}
// Operators (for cin/cout)
std::ostream& operator<<(std::ostream& out, Complex c)
{
    out << c.to_string();
    return out;
}

std::istream& operator>>(std::istream& in, Complex& c)
{
    in >> c.real;
    in >> c.imaginary;
    return in;
}