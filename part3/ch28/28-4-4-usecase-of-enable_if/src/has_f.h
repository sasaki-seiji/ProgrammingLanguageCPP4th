/*
 * has_f.h
 *
 *  Created on: 2017/05/17
 *      Author: sasaki
 */

#ifndef HAS_F_H_
#define HAS_F_H_

#include <type_traits>

struct substitution_failure { };

template<typename T>
struct substitution_succeeded : std::true_type
{ };

template<>
struct substitution_succeeded<substitution_failure> : std::false_type
{ };

template<typename T>
struct get_f_result {
private:
	template<typename X>
		static auto check(X const& x) -> decltype(f(x));
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<T>()));
};

template<typename T>
struct has_f : substitution_succeeded<typename get_f_result<T>::type>
{ };

template<typename T>
constexpr bool Has_f()
{
	return has_f<T>::value;
}


#endif /* HAS_F_H_ */
