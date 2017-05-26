/*
 * iterator_traits.h
 *
 *  Created on: 2017/05/26
 *      Author: sasaki
 */

#ifndef ITERATOR_TRAITS_H_
#define ITERATOR_TRAITS_H_

#include <iterator>

namespace Estd {

template<typename T>
using Value_type = typename std::iterator_traits<T>::value_type;

template<typename T>
using Difference_type = typename std::iterator_traits<T>::difference_type;

template<typename T>
using Iterator_category = typename std::iterator_traits<T>::iterator_category;

} // end of namespace Estd

#endif /* ITERATOR_TRAITS_H_ */
