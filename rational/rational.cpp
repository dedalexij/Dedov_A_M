#include <iostream>
#include <sstream>
#include "rational.h"

Rational::Rational(const int top) : num(top)
{}
Rational::Rational(const int top, const int bot) : num(top), denum(bot) {
	Euclid();
}

void Rational::Euclid() {
	int a = std::abs(num);
	int b = std::abs(denum);
		while (a != 0 && b != 0)
		{
			if (a > b)
				a = a % b;
			else
				b = b % a;
		}
	num /= a + b;
	denum /= a + b;
}

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs)
{
	return rhs.writeTo(ostrm);
}
inline std::istream& operator>>(std::istream& istrm, Rational& rhs)
{
	return rhs.readFrom(istrm);
}

std::ostream& Rational::writeTo(std::ostream& ostrm) const
{
	ostrm << num << slesh << denum;
	return ostrm;
}
std::istream& Rational::readFrom(std::istream& istrm)
{
	int top(0.0);
	char comma(0);
	int bot(0.0);
	istrm >> top >> comma >> bot;
	if (istrm.good())
	{
		if (Rational::slesh == slesh) {
			num = top;
			denum = bot;
		}
		else
		{
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}

Rational& Rational::operator+=(const Rational& rhs)
{
	num = num * rhs.denum + rhs.num*denum;
	denum *= rhs.denum;
	Euclid();
	return *this;
}
Rational& Rational::operator-=(const Rational& rhs)
{
	num = num * rhs.denum - rhs.num*denum;
	denum *= rhs.denum;
	Euclid();
	return *this;
}
Rational& Rational::operator*=(const Rational& rhs)
{
	num *= rhs.num;
	denum *= rhs.denum;
	Euclid();
	return *this;
}
Rational& Rational::operator/=(const Rational& rhs)
{
	num *= rhs.denum;
	denum *= rhs.num;
	Euclid();
	return *this;
}

Rational operator+(const Rational& lhs, const Rational& rhs)
{
	Rational sum(lhs);
	sum += rhs;
	return sum;
}
Rational operator+(const Rational& lhs, const int& rhs)
{
	Rational sum(lhs);
	sum += Rational(rhs);
	return sum;
}
Rational operator+(const int& lhs, const Rational& rhs)
{
	Rational sum(rhs);
	sum += Rational(lhs);
	return sum;
}

Rational operator-(const Rational& lhs, const Rational& rhs)
{
	Rational dif(lhs);
	dif -= rhs;
	return dif;
}
Rational operator-(const Rational& lhs, const int& rhs)
{
	Rational dif(lhs);
	dif -= Rational(rhs);
	return dif;
}
Rational operator-(const int& lhs, const Rational& rhs)
{
	Rational dif(lhs);
	dif -= rhs;
	return dif;
}

Rational operator*(const Rational& lhs, const Rational& rhs)
{
	Rational mul(lhs);
	mul *= rhs;
	return mul;
}
Rational operator*(const Rational& lhs, const int& rhs)
{
	Rational mul(lhs);
	mul *= Rational(rhs);
	return mul;
}
Rational operator*(const int& lhs, const Rational& rhs)
{
	Rational mul(lhs);
	mul *= rhs;
	return mul;
}

Rational operator/(const Rational& lhs, const Rational& rhs)
{
	Rational div(lhs);
	div /= rhs;
	return div;
}
Rational operator/(const Rational& lhs, const int& rhs)
{
	Rational div(lhs);
	div /= Rational(rhs);
	return div;
}
Rational operator/(const int& lhs, const Rational& rhs)
{
	Rational div(lhs);
	div /= rhs;
	return div;
}