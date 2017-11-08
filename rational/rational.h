#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <sstream>

struct Rational
{
	int num{ 0 };
	int denum{ 1 };

	Rational() {};
	Rational(const int top);
	Rational(const int top, const int bot);

	Rational& operator+=(const Rational& rhs);
	Rational& operator+=(const int integer) { return operator+=(Rational(integer)); };
	Rational& operator-=(const Rational& rhs);
	Rational& operator-=(const int integer) { return operator-=(Rational(integer)); };
	Rational& operator*=(const Rational& rhs);
	Rational& operator*=(const int integer) { return operator*=(Rational(integer)); };
	Rational& operator/=(const Rational& rhs);
	Rational& operator/=(const int integer) { return operator/=(Rational(integer)); };

	bool operator==(const Rational& rhs) const { return ((num == rhs.num) && (denum == rhs.denum)); };
	bool operator!=(const Rational& rhs) const { return ((num != rhs.num) && (denum != rhs.denum)); };

	void Euclid();

	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);

	const char slesh {'/'};

};

Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator+(const Rational& lhs, const int& rhs);
Rational operator+(const int& lhs, const Rational& rhs);

Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const int& rhs);
Rational operator-(const int& lhs, const Rational& rhs);

Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const Rational& rhs);

Rational operator/(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const int& rhs);
Rational operator/(const int& lhs, const Rational& rhs);

inline std::ostream& operator << (std::ostream& ostrm, const Rational& rhs);
inline std::istream& operator >> (std::istream& istrm, Rational& rhs);

#endif // !RATIONAL_H

