#include"complex.h"

Complex::Complex(double a_, double b_)
{
	a = a_;
	b = b_;
}
Complex::Complex(double n)
{
	a = n;
	b = 0;
}

Complex operator+(const Complex n1, const Complex n2)
{
	return Complex(n1.a+n2.a, n1.b+n2.b);
}
Complex operator-(const Complex n1, const Complex n2)
{
	return Complex(n1.a-n2.a, n1.b-n2.b);
}
Complex operator*(const Complex n1, const Complex n2)
{	
	return Complex(n1.a*n2.a-n1.b*n2.b, n1.a*n2.b+n1.b*n2.a);
}
Complex operator~(const Complex n)
{
	return Complex(n.a,-(n.b));
}
std::istream & operator>>(std::istream & is, Complex & n)
{
	char theInput[20];
	is.get(theInput, 19, '+');
	n.a = std::atof(theInput);
	is.get(theInput, 19, 'i');
	n.b = std::atof(theInput);
	return is;
}
std::ostream & operator<<(std::ostream & os, const Complex n)
{
	return os << "Complex(" << n.a << "+" << n.b << "i)";
}
