/*
 * my_future_errc.cpp
 *
 *  Created on: 2017/08/06
 *      Author: sasaki
 */


#include "my_future_errc.h"

const error_category& my_future_category() noexcept
{
	static my_future_cat obj;
	return obj;
}

string my_future_cat::message(int ec) const
{
	switch(static_cast<my_future_errc>(ec)) {
	default:
		return "bad my_future_cat code";
	case my_future_errc::broken_promise:
		return "my_future_error: broken promise";
	case my_future_errc::future_already_retrieved:
		return "my_future_error: future already retrieved";
	case my_future_errc::promise_already_satisfied:
		return "my_future_error: promise already satisfied";
	case my_future_errc::no_state:
		return "my_future_error: no state";
	}
}

error_code make_error_code(my_future_errc e) noexcept
{
	return error_code{int(e),my_future_category()};
}
