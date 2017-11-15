#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <sstream>

struct Complex
{
 Complex() = default;
	explicit Complex(const double real);
	Complex(const double real, const double imaginary);
	bool operator== (const Complex& rhs) const { return (abs(re - rhs.re)<0.0001) && (abs(im - rhs.im)<0.0001); }
	bool operator!= (const Complex& rhs) const { return (!operator== (rhs)); }
	Complex& operator+=(const Complex& rhs);
	Complex& operator+=(const double rhs) { return operator+=(Complex(rhs)); }
	Complex& operator*=(const Complex& rhs);
	Complex& operator*=(const double rhs) { return operator*=(Complex(rhs)); }
	Complex& operator-=(const Complex& rhs);
	Complex& operator-=(const double rhs) { return operator-=(Complex(rhs)); }
	Complex& operator/=(const Complex& rhs);
	Complex& operator/=(const double rhs) { return operator/=(Complex(rhs)); }

	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);

	static const char leftBrace{ '{' };
	static const char seporator{ ',' };
	static const char rightBrace{ '}' };

	double re{ 0.0 };
	double im{ 0.0 };

};

Complex operator+ (const Complex& lhs, const Complex& rhs);
Complex operator- (const Complex& lhs, const Complex& rhs);
Complex operator* (const Complex& lhs, const Complex& rhs);
Complex operator/ (const Complex& lhs, const Complex& rhs);

inline std::ostream& operator << (std::ostream& ostrm, const Complex& rhs);
inline std::istream& operator >> (std::istream& istrm, Complex& rhs);

bool testParse(const std::string& rhs);


#endif