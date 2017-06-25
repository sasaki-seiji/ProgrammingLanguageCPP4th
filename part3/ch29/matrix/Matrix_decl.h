/*
 * Matrix_decl.h
 *
 *  Created on: 2017/06/25
 *      Author: sasaki
 */

#ifndef MATRIX_DECL_H_
#define MATRIX_DECL_H_

#include "type_converter.h"
using namespace Estd;

#include <iostream>
using namespace std;

template<typename M>
	Enable_if<Matrix_type<M>(), ostream&>
operator<<(ostream& os, const M& m);


#endif /* MATRIX_DECL_H_ */
