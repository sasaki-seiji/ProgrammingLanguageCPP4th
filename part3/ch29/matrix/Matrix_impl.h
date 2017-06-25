/*
 * Matrix_impl.h
 *
 *  Created on: 2017/06/25
 *      Author: sasaki
 */

#ifndef MATRIX_IMPL_H_
#define MATRIX_IMPL_H_


template<typename M>
	Enable_if<Matrix_type<M>(), ostream&>
operator<<(ostream& os, const M& m)
{
	os << '{';
	for (size_t i = 0; i!=rows(m); ++i) {
		os << m[i];
		if (i+1!=rows(m)) os << ',';
	}
	return os << '}';
}


#endif /* MATRIX_IMPL_H_ */
