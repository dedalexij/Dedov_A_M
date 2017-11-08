#include <iostream>
#include <sstream>
#include "complex.h"


int main()
{
	using namespace std;

	testParse("{1,0");
	testParse("{1,}");
	testParse("{10}");
	testParse("{,0}");
	testParse("{1,0}");
	testParse("{1000,1000}");

	Complex z;
	z += Complex(2.0);
	z -= Complex(1.0);
	z += Complex(0.0, 2.0);
	z -= Complex(0.0, 1.0);

	z *= Complex(2.0);
	z /= Complex(2.0, 1.0);
	z *= Complex(2.0, 2.0);
	z /= Complex(2.0, 2.0);

	z = Complex(1.0) + Complex(1.0);
	z = Complex(1.0, 1.0) + Complex(1.0);
	z = Complex(1.0) - Complex(1.0);
	z = Complex(1.0, 1.0) - Complex(1.0);
	z = Complex(1.0) * Complex(1.0);
	z = Complex(1.0, 1.0) * Complex(2.0);
	z = Complex(2.0, 2.0) / Complex(0.5);

	std::cin.get();

}