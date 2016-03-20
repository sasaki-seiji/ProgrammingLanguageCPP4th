/*
 * namespace.cpp
 *
 *  Created on: 2016/03/20
 *      Author: sasaki
 */

#include <iostream>

namespace My_code {
	class complex {
	public:
		complex(double r, double i) :re{r}, im{i} { }
		double real() {return re;}
		double imag() {return im;}
	private:
		double re, im;
	};

	complex sqrt(complex)
	{
		return complex{1.2, 1.5} ; // arbitary value;
	}

	int main();
}

int My_code::main()
{
	complex z {1, 2};
	auto z2 = sqrt(z);
	std::cout << '{' << z2.real() << ',' << z2.imag() << "}\n";

	return 0 ; // 2016.03.20 neet return value
}

int main()
{
	return My_code::main();
}
