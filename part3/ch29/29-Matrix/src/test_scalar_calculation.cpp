/*
 * scalar_calculation.cpp
 *
 *  Created on: 2016/11/01
 *      Author: sasaki
 */

#include "Matrix.h"
#include <iostream>
#include <cmath>
using namespace std;

void test_apply_chain()
{
	cout << "--- test_apply_chain() --\n";

	Matrix<double,2> m {{1,-2,3}, {-4,5,-6}};
	cout << "m: " << m << endl;

	m.apply([](double& x){x=abs(x);}).apply([](double& x){x=sqrt(x);});
	cout << "m: " << m << endl;
}

void test_Matrix_assign_scalar()
{
	cout << "--- test_Matrix_assign_scalar() --\n";

	Matrix<double, 2> m {{1,2,3},{4,5,6}};
	cout << "m: " << m << endl;

	m = 10;
	cout << "m: " << m << endl;
}

void test_Matrix_addassign_scalar()
{
	cout << "--- test_Matrix_addassign_scalar() --\n";

	Matrix<double, 2> m {{1,2,3},{4,5,6}};
	cout << "m: " << m << endl;

	m += 10;
	cout << "m: " << m << endl;
}

void test_Matrix_subassign_scalar()
{
	cout << "--- test_Matrix_subassign_scalar() --\n";

	Matrix<double, 2> m {{1,2,3},{4,5,6}};
	cout << "m: " << m << endl;

	m -= 10;
	cout << "m: " << m << endl;
}

void test_Matrix_mulassign_scalar()
{
	cout << "--- test_Matrix_mulassign_scalar() --\n";

	Matrix<double, 2> m {{1,2,3},{4,5,6}};
	cout << "m: " << m << endl;

	m *= 10;
	cout << "m: " << m << endl;
}

void test_Matrix_divassign_scalar()
{
	cout << "--- test_Matrix_divassign_scalar() --\n";

	Matrix<double, 2> m {{1,2,3},{4,5,6}};
	cout << "m: " << m << endl;

	m /= 10;
	cout << "m: " << m << endl;
}

void test_Matrix_modassign_scalar()
{
	cout << "--- test_Matrix_modassign_scalar() --\n";

	Matrix<int, 2> m {{1,2,3},{4,5,6}};
	cout << "m: " << m << endl;

	m %= 3;
	cout << "m: " << m << endl;
}

void test_Matrix_add_scalar()
{
	cout << "--- test_Matrix_add_scalar() --\n";

	Matrix<double, 2> m {{1,2,3},{4,5,6}};
	cout << "m: " << m << endl;

	//auto m2 = m + 10;  // why ?
		// error: no match for 'operator+' (operand types are 'Matrix<double, 2ull>' and 'int')
	auto m2 = m + 10.0;
	cout << "m2: " << m2 << endl;
}

void test_Matrix_sub_scalar()
{
	cout << "--- test_Matrix_sub_scalar() --\n";

	Matrix<double, 2> m {{1,2,3},{4,5,6}};
	cout << "m: " << m << endl;

	auto m2 = m - 10.0;
	cout << "m2: " << m2 << endl;
}

void test_Matrix_mul_scalar()
{
	cout << "--- test_Matrix_mul_scalar() --\n";

	Matrix<double, 2> m {{1,2,3},{4,5,6}};
	cout << "m: " << m << endl;

	auto m2 = m * 10.0;
	cout << "m2: " << m2 << endl;
}

void test_Matrix_div_scalar()
{
	cout << "--- test_Matrix_div_scalar() --\n";

	Matrix<double, 2> m {{1,2,3},{4,5,6}};
	cout << "m: " << m << endl;

	auto m2 = m / 10.0;
	cout << "m2: " << m2 << endl;
}

void test_Matrix_mod_scalar()
{
	cout << "--- test_Matrix_mod_scalar() --\n";

	Matrix<int, 2> m {{1,2,3},{4,5,6}};
	cout << "m: " << m << endl;

	auto m2 = m % 4;
	cout << "m2: " << m2 << endl;
}

void test_Matrix_ref_assign_scalar()
{
	cout << "--- test_Matrix_ref_assign_scalar() --\n";

	Matrix<double, 2> m {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	cout << "m: " << m << endl;

	Matrix_ref<double, 2> mr = m(slice(0),slice(1));
	cout << "mr: " << mr << endl;

	mr = 10;
	cout << "mr: " << mr << endl;
	cout << "m: " << m << endl;
}

void test_Matrix_ref_addassign_scalar()
{
	cout << "--- test_Matrix_ref_addassign_scalar() --\n";

	Matrix<double, 2> m {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	cout << "m: " << m << endl;

	Matrix_ref<double, 2> mr = m(slice(0),slice(1));
	cout << "mr: " << mr << endl;

	mr += 10;
	cout << "mr: " << mr << endl;
	cout << "m: " << m << endl;
}

void test_Matrix_ref_subassign_scalar()
{
	cout << "--- test_Matrix_ref_subassign_scalar() --\n";

	Matrix<double, 2> m {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	cout << "m: " << m << endl;

	Matrix_ref<double, 2> mr = m(slice(0),slice(1));
	cout << "mr: " << mr << endl;

	mr -= 10;
	cout << "mr: " << mr << endl;
	cout << "m: " << m << endl;
}

void test_Matrix_ref_mulassign_scalar()
{
	cout << "--- test_Matrix_ref_mulassign_scalar() --\n";

	Matrix<double, 2> m {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	cout << "m: " << m << endl;

	Matrix_ref<double, 2> mr = m(slice(0),slice(1));
	cout << "mr: " << mr << endl;

	mr *= 10;
	cout << "mr: " << mr << endl;
	cout << "m: " << m << endl;
}

void test_Matrix_ref_divassign_scalar()
{
	cout << "--- test_Matrix_ref_divassign_scalar() --\n";

	Matrix<double, 2> m {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	cout << "m: " << m << endl;

	Matrix_ref<double, 2> mr = m(slice(0),slice(1));
	cout << "mr: " << mr << endl;

	mr /= 10;
	cout << "mr: " << mr << endl;
	cout << "m: " << m << endl;
}

void test_Matrix_ref_modassign_scalar()
{
	cout << "--- test_Matrix_ref_modassign_scalar() --\n";

	Matrix<int, 2> m {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	cout << "m: " << m << endl;

	Matrix_ref<int, 2> mr = m(slice(0),slice(1));
	cout << "mr: " << mr << endl;

	mr %= 5;
	cout << "mr: " << mr << endl;
	cout << "m: " << m << endl;
}

void test_Matrix_ref_add_scalar()
{
	cout << "--- test_Matrix_ref_add_scalar() --\n";

	Matrix<double, 2> m {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	cout << "m: " << m << endl;

	Matrix_ref<double, 2> mr = m(slice(0),slice(1));
	cout << "mr: " << mr << endl;

	//auto m2 = mr + 10;  // why ?
		// error: no match for 'operator+' (operand types are 'Matrix_ref<double, 2ull>' and 'int')
	auto m2 = mr + 10.0;
	cout << "m2: " << m2 << endl;
	cout << "mr: " << mr << endl;
}

void test_Matrix_ref_sub_scalar()
{
	cout << "--- test_Matrix_ref_sub_scalar() --\n";

	Matrix<double, 2> m {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	cout << "m: " << m << endl;

	Matrix_ref<double, 2> mr = m(slice(0),slice(1));
	cout << "mr: " << mr << endl;

	auto m2 = mr - 10.0;
	cout << "m2: " << m2 << endl;
	cout << "mr: " << mr << endl;
}

void test_Matrix_ref_mul_scalar()
{
	cout << "--- test_Matrix_ref_mul_scalar() --\n";

	Matrix<double, 2> m {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	cout << "m: " << m << endl;

	Matrix_ref<double, 2> mr = m(slice(0),slice(1));
	cout << "mr: " << mr << endl;

	auto m2 = mr * 10.0;
	cout << "m2: " << m2 << endl;
	cout << "mr: " << mr << endl;
}



