#include <iostream>
#include <sstream>
#include "complex.h"


Complex::Complex(const double real)
	: Complex(real, 0.0)
{
}
Complex::Complex(const double real, const double imaginary)
	: re(real), im(imaginary)
{
}


Complex& Complex::operator+=(const Complex& rhs)
{
	re += rhs.re;
	im += rhs.im;
	return *this;
}
Complex& Complex::operator*=(const Complex& rhs)
{
	re *= rhs.re;
	im *= rhs.re;
	return *this;
}
Complex& Complex::operator-=(const Complex& rhs)
{
	re -= rhs.re;
	im -= rhs.im;
	return *this; //результатом работы будет сам экземпл€р, на который ссылает€ метод
}
Complex& Complex::operator/=(const Complex& rhs)
{
	re /= rhs.re;
	im /= rhs.re;
	return *this;
}


Complex operator+ (const Complex& lhs, const Complex& rhs)
{
	Complex sum(lhs);
	sum += rhs;
	return sum;
}
Complex operator- (const Complex& lhs, const Complex& rhs)
{
	Complex dif(lhs);
	dif -= rhs;
	return dif;
}
Complex operator* (const Complex& lhs, const Complex& rhs)
{
	Complex mul(lhs);
	mul *= rhs;
	return mul;
}
Complex operator/ (const Complex& lhs, const Complex& rhs)
{
	Complex div(lhs);
	div /= rhs;
	return div;
}


std::ostream& Complex::writeTo(std::ostream& ostrm) const
{
	ostrm << leftBrace << re << seporator << im << rightBrace;
	return ostrm;
}
std::istream& Complex::readFrom(std::istream& istrm)
{
	char leftBrace(0);
	double real(0.0);
	char comma(0);
	double imaginary(0.0);
	char rightBrace(0);
	istrm >> leftBrace >> real >> comma >> imaginary >> rightBrace;
	if (istrm.good()) 
	{
		if ((Complex::leftBrace == leftBrace) && (Complex::seporator == comma) && (Complex::rightBrace == rightBrace)) {
			re = real;
			im = imaginary;
		}
		else 
		{
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}
inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs)
{
	return rhs.writeTo(ostrm);
}
inline std::istream& operator>>(std::istream& istrm, Complex& rhs)
{
	return rhs.readFrom(istrm);
}
bool testParse(const std::string& str)
{
	using namespace std;
	istringstream istrm(str);
	Complex z;
	istrm >> z;
	if (istrm.good())
	{
		cout << "Read success: " << str << " -> " << z << endl;
	}
	else
	{
		cout << "Read error: " << str << " -> " << z << endl;
	}
	return istrm.good();
}