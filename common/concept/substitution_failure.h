/*
 * substitution_failure.h
 *
 *  Created on: 2017/05/20
 *      Author: sasaki
 */

#ifndef SUBSTITUTION_FAILURE_H_
#define SUBSTITUTION_FAILURE_H_

#include <type_traits>

namespace Estd {

struct substitution_failure { };

template<typename T>
struct substitution_succeeded : std::true_type
{ };

template<>
struct substitution_succeeded<substitution_failure> : std::false_type
{ };

}

#endif /* SUBSTITUTION_FAILURE_H_ */
