/*
 * type_predicate.cpp
 *
 *  Created on: 2016/04/06
 *      Author: sasaki
 */


#include <type_traits>
#include <string>
#include <iostream>

template<typename T>
constexpr bool Is_arithmetic()
{
	return std::is_arithmetic<T>::value;
}

template<typename Scalar>
class complex {
	Scalar re, im;
public:
	static_assert(Is_arithmetic<Scalar>(),
			"Sorry, I only support complex of arithmetic types");
};
int main()
{
	bool b1 = Is_arithmetic<int>();
	bool b2 = Is_arithmetic<std::string>();

	std::cout << "b1 = " << b1 << ", b2 = " << b2 << '\n';

	complex<double> cd;
	//complex<std::string> cs;
}

