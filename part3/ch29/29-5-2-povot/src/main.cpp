/*
 * main.cpp
 *
 *  Created on: 2016/11/23
 *      Author: sasaki
 */

#include "classical_gaussian_elimination.h"
#include <random>
#include <iostream>
using namespace std;

random_device seed_gen;
mt19937 engine(seed_gen());

Mat2d random_matrix(size_t n)
{
	uniform_real_distribution<> dist1(-1.0, 1.0);

	Mat2d m(n,n);
	for (size_t i = 0; i < n; ++i)
		for (size_t j = 0; j < n; ++j)
			m(i,j) = dist1(engine);
	return m;
}

Vec random_vector(size_t n)
{
	uniform_real_distribution<> dist1(-1.0, 1.0);

	Vec v(n);
	for (size_t i = 0; i < n; ++i)
		v(i) = dist1(engine);
	return v;
}

void solve_system(const Mat2d& A, const Vec& b)
{
	cout << "A = " << A << '\n';
	cout << "b = " << b << '\n';

	try {
		Vec x = classical_gaussian_elimination(A,b);
		cout << "classical elim solution is x = " << x << '\n';
		Vec v = A * x;
		cout << "A * x = " << v << '\n';
	}
	catch(const exception& e) {
		cerr << e.what() << '\n';
	}
}

void solve_random_system(size_t n)
{
	Mat2d A = random_matrix(n);
	Vec b = random_vector(n);

	solve_system(A, b);
}

int main()
{
	cout << "--- random test ---\n";
	solve_random_system(3);

	cout << "--- zero diagonal ---\n";
	Mat2d A = {
			{ 0, 1, 0 },
			{ 0, 0, 1 },
			{ 1, 0, 0 }
	};
	Vec b = { 1, 2, 3 };
	solve_system(A,b);
}
