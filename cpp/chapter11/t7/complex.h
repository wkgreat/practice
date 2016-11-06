#ifndef COMPLEX_H_
#define COMPLEX_H_
#include<iostream>

class Complex
{
	private:
		double a;
		double b;
	public:
		Complex() { a=0, b=0; }
		Complex(double n);
		Complex(double a_, double b_);
		~Complex() {};
		friend Complex operator+(const Complex n1, const Complex n2);
		friend Complex operator-(const Complex n1, const Complex n2);
		friend Complex operator*(const Complex n1, const Complex n2);
		friend Complex operator~(const Complex n);
		friend std::istream & operator>>(std::istream & is, Complex & n);
		friend std::ostream & operator<<(std::ostream & os, const Complex n);
};

#endif
