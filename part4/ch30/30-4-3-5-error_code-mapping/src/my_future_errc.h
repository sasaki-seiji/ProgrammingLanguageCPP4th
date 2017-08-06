/*
 * my_future_errc.h
 *
 *  Created on: 2017/08/06
 *      Author: sasaki
 */

#ifndef MY_FUTURE_ERRC_H_
#define MY_FUTURE_ERRC_H_

#include <system_error>
#include <string>
using namespace std;

enum class my_future_errc {
	broken_promise = 1,
	future_already_retrieved,
	promise_already_satisfied,
	no_state
};

class my_future_cat : public error_category {
public:
	const char* name() const noexcept override { return "future"; }
	string message(int ec) const override;
};

const error_category& my_future_category() noexcept;

error_code make_error_code(my_future_errc e) noexcept;

namespace std {
	template<>
	struct is_error_code_enum<my_future_errc> : public true_type { };
}

#endif /* MY_FUTURE_ERRC_H_ */
