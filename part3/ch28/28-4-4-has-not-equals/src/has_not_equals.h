/*
 * has_not_equals.h
 *
 *  Created on: 2016/10/10
 *      Author: sasaki
 */

#ifndef HAS_NOT_EQUALS_H_
#define HAS_NOT_EQUALS_H_


struct substitution_failure { };

template<typename T>
struct substitution_succeeded : std::true_type
{ };

template<>
struct substitution_succeeded<substitution_failure> : std::false_type
{ };

template<typename T>
struct get_not_equals_result {
private:
	template<typename X>
		static auto check(const X& x) -> decltype(x!=x);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<T>()));
};

template<typename T>
struct has_not_equals : substitution_succeeded<typename get_not_equals_result<T>::type>
{ };

template<typename T>
constexpr bool Has_not_equals()
{
	return has_not_equals<T>::value;
}



#endif /* HAS_NOT_EQUALS_H_ */
