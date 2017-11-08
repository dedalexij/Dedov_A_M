#include <iostream>
#include <sstream>
#include "rational.h"

int main()
{
	Rational a(1, 6);
	Rational b(1, 3);
	Rational c;

	c = a + b;
	c = Rational(1, 2) + 1;
	c = 1 + Rational(1, 2);

	c = a - b;
	c = Rational(5, 4) - 1;
	c = 1 - Rational(1, 4);

	c = a * b;
	c = Rational(5, 4) * 4;
	c = 4 * Rational(1, 4);

	c = a / b;
	c = Rational(5, 4) / 5;
	c = 4 / Rational(4, 3);

	c = 1;
	c += 1;
	c += Rational(1, 2);
	c -= 1;
	c -= Rational(1, 4);

	c = 1;
	c *= Rational(3, 4);
	c *= (-4);

	return 0;
}