#include <iostream>
#include <sstream>
#include "rationalT.h"

int main()
{
	RationalT<int> a(1, 6);
	RationalT<int> b(1, 3);
	RationalT<int> c;

	c = a + b;
	c = RationalT<int>(1, 2) + 1;
	c = 1 + RationalT<int>(1, 2);

	c = a - b;
	c = RationalT<int>(5, 4) - 1;
	c = 1 - RationalT<int>(1, 4);

	c = a * b;
	c = RationalT<int>(5, 4) * 4;
	c = 4 * RationalT<int>(1, 4);

	c = a / b;
	c = RationalT<int>(5, 4) / 5;
	c = 4 / RationalT<int>(4, 3);

	c = 1;
	c += 1;
	c += RationalT<int>(1, 2);
	c -= 1;
	c -= RationalT<int>(1, 4);

	c = 1;
	c *= RationalT<int>(3, 4);
	c *= (-4);

	return 0;
}