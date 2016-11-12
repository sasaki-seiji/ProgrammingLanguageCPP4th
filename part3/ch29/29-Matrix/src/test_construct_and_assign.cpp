/*
 * construct_and_assign.cpp
 *
 *  Created on: 2016/10/30
 *      Author: sasaki
 */

#include "Matrix.h"
#include <iostream>
#include <complex>
using namespace std;

enum class Piece { none, cross, naught };
ostream& operator<<(ostream& os, Piece piece)
{
	if (piece == Piece::none) os << "none";
	else if (piece == Piece::cross) os << "cross";
	else if (piece == Piece::naught) os << "naught";
	else os << "(unknown)";
	return os;
}

void test_Matrix_from_Matrix_initializer()
{
	cout << "--- test_Matrix_from_Matrix_initializer() --\n";

	Matrix<Piece,2> board1 {
		{Piece::none, Piece::none, Piece::none},
		{Piece::none, Piece::none, Piece::none},
		{Piece::none, Piece::none, Piece::cross}
	};
	cout << board1 << endl;

#if 0 // assert -> abort
	Matrix<int,2> jagged_matrix {
		{1, 2, 3},
		{4, 5},
		{6, 7, 8}
	};
#endif

#if 0 // not compiled
	Matrix<int, 3> mismatch_level {
		{1, 2, 3},
		{4, 5, 6}
	};
#endif
}

void test_Matrix_assign_Matrix_initializer()
{
	cout << "--- test_Matrix_assign_Matrix_initializer() --\n";

	Matrix<int,2> m(2,3);
	m = {{1,2,3},{4,5,6}};
	cout << "m.descriptor(): " << m.descriptor() << endl;
	cout << "m: " << m << endl;
}

void test_explicit_Matrix_from_extents()
{
	cout << "--- test_explicit_Matrix_from_extents() --\n";

	Matrix<Piece,2> board2(3,3);
	Matrix<Piece,2> board3 {3,3};
		// error: use of deleted function 'Matrix<T, N>::Matrix(std::initializer_list<U>) [with U = int; T = Piece; long long unsigned int N = 2ull]'

	cout << "board2.desc: " << board2.descriptor() << endl;
	cout << "board3.desc: " << board3.descriptor() << endl;

	// 2016.11.12 add

	Matrix<double,2> md(2,3);
	cout << "md.decs: " << md.descriptor() << endl;
	cout << "md: " << md << endl;
}

void test_Matrix_from_Matrix_ref()
{
	cout << "--- test_Matrix_from_Matrix_ref() --\n";

	Matrix<int,2> m {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};
	cout << "m: " << m << endl;

	Matrix_ref<int,1> r1 = m.row(1);
	cout << "m.row(1): " << r1 << endl;

	Matrix<int,1> mr1 {r1};
	cout << "mr1.desc: " << mr1.descriptor()<< endl;
	cout << "mr1: " << mr1 << endl;
	cout << "mr1(1): " << mr1(1) << endl;

	Matrix_ref<int,1> c1 = m.col(1);
	cout << "m.col(1): " << c1 << endl;

	Matrix<int,1> mc1 {c1};
	cout << "mc1.desc: " << mc1.descriptor()<< endl;
	cout << "mc1: " << mc1 << endl;
	cout << "mc1(1): " << mc1(1) << endl;
}

void test_Matrix_assign_Matrix_ref()
{
	cout << "--- test_Matrix_assing_Matrix_ref() --\n";

	Matrix<int,2> m {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};
	cout << "m: " << m << endl;

	Matrix_ref<int,1> r1 = m.row(1);
	cout << "m.row(1): " << r1 << endl;

	Matrix<int,1> mr1(3);
	mr1 = r1;
	cout << "mr1.desc: " << mr1.descriptor()<< endl;
	cout << "mr1: " << mr1 << endl;
	cout << "mr1(1): " << mr1(1) << endl;

	Matrix_ref<int,1> c1 = m.col(1);
	cout << "m.col(1): " << c1 << endl;

	Matrix<int,1> mc1(3);
	mc1 = c1;
	cout << "mc1.desc: " << mc1.descriptor()<< endl;
	cout << "mc1: " << mc1 << endl;
	cout << "mc1(1): " << mc1(1) << endl;
}

void test_Matrix_from_different_Matrix()
{
	cout << "--- test_Matrix_from_different_Matrix() --\n";

	Matrix<double,2> md {
		{1.1, 2.2, 3.3},
		{4.4, 5.5, 6.6},
		{7.7, 8.8, 9.9}
	};
	cout << "md: " << md << endl;

	Matrix<int,2> mi {md};
	cout << "mi: " << mi << endl;
}

void test_Matrix_assign_different_Matrix()
{
	cout << "--- test_Matrix_assign_different_Matrix() --\n";

	Matrix<complex<double>,2> mc(2,2);
	mc = {
		{1.1, 2.2, 3.3},
		{4.4, 5.5, 6.6},
		{7.7, 8.8, 9.9}
	};
	cout << "mc: " << mc << endl;
}
