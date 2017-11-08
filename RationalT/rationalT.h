#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <sstream>

template <typename T>
struct RationalT
{
 T num{ 0 };
 T denum{ 1 };

 RationalT() {}
 RationalT(const T& top);
 RationalT(const T& top, const T& bot);

 RationalT<T>& operator+=(const RationalT<T>& rhs);
 RationalT<T>& operator+=(const T& integer) { return operator+=(RationalT(integer)); };
 RationalT<T>& operator-=(const RationalT<T>& rhs);
 RationalT<T>& operator-=(const T& integer) { return operator-=(RationalT(integer)); };
 RationalT<T>& operator*=(const RationalT<T>& rhs);
 RationalT<T>& operator*=(const T& integer) { return operator*=(RationalT(integer)); };
 RationalT<T>& operator/=(const RationalT<T>& rhs);
 RationalT<T>& operator/=(const T& integer) { return operator/=(RationalT(integer)); };

 bool operator==(const RationalT<T>& rhs) const { return ((num == rhs.num) && (denum == rhs.denum)); };
 bool operator!=(const RationalT<T>& rhs) const { return ((num != rhs.num) && (denum != rhs.denum)); };

 void Euclid();


};

template <typename T>
RationalT<T> operator+(const RationalT<T>& lhs, const RationalT<T>& rhs);
template <typename T>
RationalT<T> operator+(const RationalT<T>& lhs, const T& rhs);
template <typename T>
RationalT<T> operator+(const T& lhs, const RationalT<T>& rhs);


template <typename T>
RationalT<T> operator-(const RationalT<T>& lhs, const RationalT<T>& rhs);
template <typename T>
RationalT<T> operator-(const RationalT<T>& lhs, const T& rhs);
template <typename T>
RationalT<T> operator-(const T& lhs, const RationalT<T>& rhs);


template <typename T>
RationalT<T> operator*(const RationalT<T>& lhs, const RationalT<T>& rhs);
template <typename T>
RationalT<T> operator*(const RationalT<T>& lhs, const T& rhs);
template <typename T>
RationalT<T> operator*(const T& lhs, const RationalT<T>& rhs);


template <typename T>
RationalT<T> operator/(const RationalT<T>& lhs, const RationalT<T>& rhs);
template <typename T>
RationalT<T> operator/(const RationalT<T>& lhs, const T& rhs);
template <typename T>
RationalT<T> operator/(const T& lhs, const RationalT<T>& rhs);


template <typename T>
RationalT<T>::RationalT(const T& top) : num(top)
{}
template <typename T>
RationalT<T>::RationalT(const T& top, const T& bot) : num(top), denum(bot) {
	Euclid();
}
template <typename T>


void RationalT<T>::Euclid() {
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
template <typename T>


RationalT<T>& RationalT<T>::operator+=(const RationalT<T>& rhs)
{
	num = num * rhs.denum + rhs.num*denum;
	denum *= rhs.denum;
	Euclid();
	return *this;
}
template <typename T>
RationalT<T>& RationalT<T>::operator-=(const RationalT<T>& rhs)
{
	num = num * rhs.denum - rhs.num*denum;
	denum *= rhs.denum;
	Euclid();
	return *this;
}
template <typename T>
RationalT<T>& RationalT<T>::operator*=(const RationalT<T>& rhs)
{
	num *= rhs.num;
	denum *= rhs.denum;
	Euclid();
	return *this;
}
template <typename T>
RationalT<T>& RationalT<T>::operator/=(const RationalT<T>& rhs)
{
	num *= rhs.denum;
	denum *= rhs.num;
	Euclid();
	return *this;
}


template <typename T>
RationalT<T> operator+(const RationalT<T>& lhs, const RationalT<T>& rhs)
{
	RationalT<T> sum(lhs);
	sum += rhs;
	return sum;
}
template <typename T>
RationalT<T> operator+(const RationalT<T>& lhs, const T& rhs)
{
	RationalT<T> sum(lhs);
	sum += RationalT<T>(rhs);
	return sum;
}
template <typename T>
RationalT<T> operator+(const T& lhs, const RationalT<T>& rhs)
{
	RationalT<T> sum(rhs);
	sum += RationalT<T>(lhs);
	return sum;
}


template <typename T>
RationalT<T> operator-(const RationalT<T>& lhs, const RationalT<T>& rhs)
{
	RationalT<T> dif(lhs);
	dif -= rhs;
	return dif;
}
template <typename T>
RationalT<T> operator-(const RationalT<T>& lhs, const T& rhs)
{
	RationalT<T> dif(lhs);
	dif -= RationalT<T>(rhs);
	return dif;
}
template <typename T>
RationalT<T> operator-(const T& lhs, const RationalT<T>& rhs)
{
	RationalT<T> dif(lhs);
	dif -= rhs;
	return dif;
}


template <typename T>
RationalT<T> operator*(const RationalT<T>& lhs, const RationalT<T>& rhs)
{
	RationalT<T> mul(lhs);
	mul *= rhs;
	return mul;
}
template <typename T>
RationalT<T> operator*(const RationalT<T>& lhs, const T& rhs)
{
	RationalT<T> mul(lhs);
	mul *= RationalT<T>(rhs);
	return mul;
}
template <typename T>
RationalT<T> operator*(const T& lhs, const RationalT<T>& rhs)
{
	RationalT<T> mul(lhs);
	mul *= rhs;
	return mul;
}


template <typename T>
RationalT<T> operator/(const RationalT<T>& lhs, const RationalT<T>& rhs)
{
	RationalT<T> div(lhs);
	div /= rhs;
	return div;
}
template <typename T>
RationalT<T> operator/(const RationalT<T>& lhs, const T& rhs)
{
	RationalT<T> div(lhs);
	div /= RationalT<T>(rhs);
	return div;
}
template <typename T>
RationalT<T> operator/(const T& lhs, const RationalT<T>& rhs)
{
	RationalT<T> div(lhs);
	div /= rhs;
	return div;
}

template <typename T>
inline std::ostream& operator<<(std::ostream& ostrm, const RationalT<T>& rhs)
{
	return rhs.writeTo(ostrm);
}
template <typename T>
inline std::istream& operator>>(std::istream& istrm, RationalT<T>& rhs)
{
	return rhs.readFrom(istrm);
}

template <typename T>
std::ostream& RationalT<T>::writeTo(std::ostream& ostrm) const
{
	ostrm << num << slesh << denum;
	return ostrm;
}
template <typename T>
std::istream& RationalT<T>::readFrom(std::istream& istrm)
{
	int top(0.0);
	char comma(0);
	int bot(0.0);
	istrm >> top >> comma >> bot;
	if (istrm.good())
	{
		if (RationalT<T>::slesh == comma) {
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
#endif