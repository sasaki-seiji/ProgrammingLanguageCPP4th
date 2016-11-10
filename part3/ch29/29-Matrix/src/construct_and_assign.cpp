/*
 * construct_and_assign.cpp
 *
 *  Created on: 2016/10/30
 *      Author: sasaki
 */

#include "Matrix.h"
#include <iostream>
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

void test_nonnumeric_matrix()
{
	cout << "--- test_nonnumeric_matrix() --\n";

	Matrix<Piece,2> board1 {
		{Piece::none, Piece::none, Piece::none},
		{Piece::none, Piece::none, Piece::none},
		{Piece::none, Piece::none, Piece::cross}
	};

	cout << board1 << endl;
}

void test_explicit_extents()
{
	cout << "--- test_explicit_extents() --\n";

	Matrix<Piece,2> board2(3,3);
	Matrix<Piece,2> board3 {3,3};
		// error: use of deleted function 'Matrix<T, N>::Matrix(std::initializer_list<U>) [with U = int; T = Piece; long long unsigned int N = 2ull]'

	cout << "board2.desc: " << board2.descriptor() << endl;
	cout << "board23.desc: " << board3.descriptor() << endl;
}
