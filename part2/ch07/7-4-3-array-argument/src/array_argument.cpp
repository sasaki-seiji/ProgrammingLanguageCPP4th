/*
 * array_argument.cpp
 *
 *  Created on: 2016/04/16
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

void comp(double arg[10])
{
	for (int i=0; i!=10; ++i)
		arg[i]+=99;
}

void comp2(double* arg)
{
	for (int i=0; i!=10; ++i)
		arg[i]+=99;
}

void print(double* arg)
{
	for (int i=0; i!=10; ++i)
		cout << arg[i] << '\t';
	cout << '\n';
}

void f()
{
	double a1[10] = {0};	// メモリレイアウト上、a3[100]、a2[5]、a1[10]の順？
	double a2[5] = {0};
	double a3[100] = {0};

	comp(a1);
	comp(a2);
	comp(a3);

	print(a1);
	print(a2);
	print(a3);

	comp2(a1);
	comp2(a2);
	comp2(a3);

	print(a1);
	print(a2);
	print(a3);
}

void print_m35(int m[3][5])
{
	for (int i = 0; i!=3; i++) {
		for (int j = 0; j!=5; j++)
			cout << m[i][j] << '\t';
		cout << '\n';
	}
}

void print_mi5(int m[][5], int dim1)
{
	for (int i = 0; i!=dim1; i++){
		for (int j = 0; j!=5; j++)
			cout << m[i][j] << '\t';
		cout << '\n';
	}
}

void print_mij(int* m, int dim1, int dim2)
{
	for (int i = 0; i!=dim1; i++){
		for (int j = 0; j!=dim2; j++)
			cout << m[i*dim2+j] << '\t';
		cout << '\n';
	}
}

void test()
{
	int v[3][5] = {
		{0,1,2,3,4},
		{10,11,12,13,14},
		{20,21,22,23,24}
	};

	print_m35(v);
	print_mi5(v, 3);
	print_mij(&v[0][0], 3, 5);
}

int main()
{
	f();
	test();
}
