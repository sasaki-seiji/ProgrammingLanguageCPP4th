/*
 * ssort.h
 *
 *  Created on: 2016/05/11
 *      Author: sasaki
 */

#ifndef SSORT_H_
#define SSORT_H_

#include <cstdlib>

using CFT = int(const void*, const void*);

void ssort(void* base, size_t n, size_t sz, CFT cmp);

#endif /* SSORT_H_ */
