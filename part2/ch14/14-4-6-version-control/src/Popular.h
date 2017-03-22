/*
 * Popular.h
 *
 *  Created on: 2016/05/28
 *      Author: sasaki
 */

#ifndef POPULAR_H_
#define POPULAR_H_

namespace Popular {
	inline
	#include "V3_2.h"
	#include "V3_0.h"
	#include "V2_4_2.h"

	// 2017.03.22 add: declare namespace member
	template<typename T>
	class Popular::C<T*>;

}

#endif /* POPULAR_H_ */
