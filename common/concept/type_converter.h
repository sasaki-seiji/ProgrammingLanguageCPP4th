/*
 * type_converter.h
 *
 *  Created on: 2017/05/20
 *      Author: sasaki
 */

#ifndef TYPE_CONVERTER_H_
#define TYPE_CONVERTER_H_

#include <type_traits>

namespace Estd {

template<bool B, typename X=void>
using Enable_if = typename std::enable_if<B,X>::type;

}

#endif /* TYPE_CONVERTER_H_ */
