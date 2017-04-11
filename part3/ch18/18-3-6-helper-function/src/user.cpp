/*
 * user.cpp
 *
 *  Created on: 2016/08/08
 *      Author: sasaki
 */

#include "complex.h"
#include <iostream>
#include <sstream>
using namespace std;

void test_minus_assign()
{
	cout << "-- test_minus_assign() --\n";
	complex z{1,-3};
	complex z1{2, 1};

	cout << "z: " << z << '\n';
	cout << "z1: " << z1 << '\n';
	z -= z1;
	cout << "z -= z1; z: " << z << '\n';
	z -= 2.3;
	cout << "z -= 2.3; z: " << z << '\n';
}

void test_mul_assign()
{
	cout << "-- test_mul_assign() --\n";
	complex z{1,1};
	complex z1{2, 1};

	cout << "z: " << z << '\n';
	cout << "z1: " << z1 << '\n';
	z *= z1;
	cout << "z *= z1; z: " << z << '\n';
	z *= 1.1;
	cout << "z *= 1.1; z: " << z << '\n';
}

void test_div_assign()
{
	cout << "-- test_div_assign() --\n";
	complex z{3,1};
	complex z1{1, 1};

	cout << "z: " << z << '\n';
	cout << "z1: " << z1 << '\n';
	z /= z1;
	cout << "z /= z1; z: " << z << '\n';
	z /= 2;
	cout << "z /= 2; z: " << z << '\n';
}

void test_binary_minus()
{
	cout << "-- test_binary_minus() --\n";
	complex z{3,1};
	complex z1{1, 2};

	cout << "z: " << z << '\n';
	cout << "z1: " << z1 << '\n';

	cout << "z - z1:" << z - z1 << '\n';
	cout << "z - 2: " << z - 2 << '\n';
	cout << "3 - z: " << 3 - z << '\n';

}

void test_mul()
{
	cout << "-- test_mul() --\n";
	complex z{3,1};
	complex z1{1, 2};

	cout << "z: " << z << '\n';
	cout << "z1: " << z1 << '\n';

	cout << "z * z1:" << z * z1 << '\n';
	cout << "z * 2: " << z * 2 << '\n';
	cout << "3 * z: " << 3 * z << '\n';
}

void test_div()
{
	cout << "-- test_div() --\n";
	complex z{3,1};
	complex z1{1, 2};

	cout << "z: " << z << '\n';
	cout << "z1: " << z1 << '\n';

	cout << "z / z1:" << z / z1 << '\n';
	cout << "z / 2: " << z / 2 << '\n';
	cout << "3 / z: " << 3 / z << '\n';
}

void test_unary_operator()
{
	cout << "-- test_unary_operator() --\n";
	complex z{3,-11};

	cout << "z: " << z << '\n';

	cout << "+z: " << +z << '\n';
	cout << "-z: " << -z << '\n';
}

void test_equality()
{
	cout << "-- test_equality() --\n";
	complex z{3,-1};
	complex z1{3, -1}, z2{3, 1};

	cout << "z: " << z << '\n';
	cout << "z1: " << z1 << '\n';
	cout << "z2: " << z2 << '\n';

	cout << boolalpha;
	cout << "z == z1:" << (z == z1) << '\n';
	cout << "z == z2: " << (z == z2) << '\n';
	cout << "z != z1: " << (z != z1) << '\n';
	cout << "z != z2: " << (z != z2) << '\n';
}

void test_stream()
{
	cout << "-- test_stream() --\n";

	istringstream iss("(10, -3.2)");
	complex z;

	iss >> z;
	cout << "z: " << z << '\n';
}

void test_sqrt()
{
	cout << "-- test_sqrt() --\n";

	complex z1, z2{2}, z3{2.0i};
	cout << "z1: " << z1 << '\n';
	cout << "z2: " << z2 << '\n';
	cout << "z3: " << z3 << '\n';

	cout << "sqrt(z1): " << sqrt(z1) << '\n';
	cout << "sqrt(z2): " << sqrt(z2) << '\n';
	cout << "sqrt(z3): " << sqrt(z3) << '\n';

}
const double pi = 3.14159265358979323846;
void test_polar()
{
	cout << "-- test_polar() --\n";

	complex z1, z2, z3;
	z1 = polar(2, 0);
	z2 = polar(2, pi/4);
	z3 = polar(2, pi/2);

	cout << "z1=polar(2,0);    z1: " << z1 << '\n';
	cout << "z2=polar(2,pi/4); z2: " << z2 << '\n';
	cout << "z3=polar(2,pi/2); z3: " << z3 << '\n';
}

void test_conj()
{
	cout << "-- test_conj() --\n";

	complex z1{1,2}, z2{2, -3};
	cout << "z1: " << z1 << '\n';
	cout << "z2: " << z2 << '\n';

	cout << "conj(z1): " << conj(z1) << '\n';
	cout << "conj(z2): " << conj(z2) << '\n';
}

void test_abs()
{
	cout << "-- test_abs() --\n";

	complex z1{1,2}, z2{1, -1};
	cout << "z1: " << z1 << '\n';
	cout << "z2: " << z2 << '\n';

	cout << "abs(z1): " << abs(z1) << '\n';
	cout << "abs(z2): " << abs(z2) << '\n';
}

void test_arg()
{
	cout << "-- test_arg() --\n";

	complex z1{-1, 0}, z2{1, 1};
	cout << "z1: " << z1 << '\n';
	cout << "z2: " << z2 << '\n';

	cout << "arg(z1): " << arg(z1) << '\n';
	cout << "arg(z2): " << arg(z2) << '\n';
}

void test_norm()
{
	cout << "-- test_norm() --\n";

	complex z1{1,2}, z2{1, -1};
	cout << "z1: " << z1 << '\n';
	cout << "z2: " << z2 << '\n';

	cout << "norm(z1): " << norm(z1) << '\n';
	cout << "norm(z2): " << norm(z2) << '\n';
}

void test_real_imag()
{
	cout << "-- test_real_imag() --\n";

	complex z1{-1, 0}, z2{1, 2};
	cout << "z1: " << z1 << '\n';
	cout << "z2: " << z2 << '\n';

	cout << "real(z1): " << real(z1) << ", imag(z1): " << imag(z1) << '\n';
	cout << "real(z2): " << real(z2) << ", imag(z2): " << imag(z2) << '\n';
}

void test_acos()
{
	cout << "-- test_acos() --\n";

	complex z1, z2{1}, z3{1.0i};
	cout << "z1: " << z1 << '\n';
	cout << "z2: " << z2 << '\n';
	cout << "z3: " << z3 << '\n';

	cout << "acos(z1): " << acos(z1) << '\n';
	cout << "acos(z2): " << acos(z2) << '\n';
	cout << "acos(32): " << acos(32) << '\n';
}

void test_asin()
{
	cout << "-- test_asin() --\n";

	complex z1, z2{1}, z3{1.0i};
	cout << "z1: " << z1 << '\n';
	cout << "z2: " << z2 << '\n';
	cout << "z3: " << z3 << '\n';

	cout << "asin(z1): " << asin(z1) << '\n';
	cout << "asin(z2): " << asin(z2) << '\n';
	cout << "asin(32): " << asin(32) << '\n';
}

void test_atan()
{
	cout << "-- test_atan() --\n";

	complex z1, z2{1}, z3{1.0i};
	cout << "z1: " << z1 << '\n';
	cout << "z2: " << z2 << '\n';
	cout << "z3: " << z3 << '\n';

	cout << "atan(z1): " << atan(z1) << '\n';
	cout << "atan(z2): " << atan(z2) << '\n';
	cout << "atan(32): " << atan(32) << '\n';
}

int main()
{
	test_minus_assign();
	test_mul_assign();
	test_div_assign();
	test_binary_minus();
	test_mul();
	test_div();
	test_unary_operator();
	test_equality();
	test_stream();
	test_sqrt();
	test_polar();
	test_conj();
	test_abs();
	test_arg();
	test_norm();
	test_real_imag();
	test_acos();
	test_asin();
	test_atan();
}
