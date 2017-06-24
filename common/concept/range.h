/*
 * Range.h
 *
 *  Created on: 2017/06/25
 *      Author: sasaki
 */

#ifndef RANGE_H_
#define RANGE_H_

#include "type_relation.h"
#include "has_begin_end.h"
#include "has_increment.h"
#include "has_dereference.h"

namespace Estd {

template<typename T>
constexpr bool Range()
{
	return
		( Has_member_begin<T>()
			&& Has_member_end<T>()
			&& Same<Member_begin_result<T>,Member_end_result<T>>()
			&& Has_pre_increment<Member_begin_result<T>>()
			&& Has_dereference<Member_begin_result<T>>()
		)
	||
		( Has_global_begin<T>()
			&& Has_global_end<T>()
			&& Same<Global_begin_result<T>,Global_end_result<T>>()
			&& Has_pre_increment<Global_begin_result<T>>()
			&& Has_dereference<Global_begin_result<T>>()
		);
}

} // end of Estd


#endif /* RANGE_H_ */
