/*
 * construct_and_assign.cpp
 *
 *  Created on: 2016/10/30
 *      Author: sasaki
 */

#include "Matrix.h"

enum class Piece { none, cross, naught };

Matrix<Piece,2> board1 {
	{Piece::none, Piece::none, Piece::none},
	{Piece::none, Piece::none, Piece::none},
	{Piece::none, Piece::none, Piece::cross}
};

Matrix<Piece,2> board2(3,3);
//Matrix<Piece,2> board3 {3,3};
	// error: use of deleted function 'Matrix<T, N>::Matrix(std::initializer_list<U>) [with U = int; T = Piece; long long unsigned int N = 2ull]'

