/*
 * Predicate.h
 *
 *  Created on: 2017/06/24
 *      Author: sasaki
 */

#ifndef PREDICATE_H_
#define PREDICATE_H_

#include "has_call.h"
#include "boolean.h"

namespace Estd {

template<typename T, typename U>
constexpr bool Predicate()
{
	return Has_call<T,U>()
		//	&& Boolean<Call_result<T,U>>();
			&& Same<Call_result<T,U>,bool>();
}

}


#endif /* PREDICATE_H_ */
