/*
 * ssort.cpp
 *
 *  Created on: 2016/05/11
 *      Author: sasaki
 */

#include "ssort.h"

using CFT = int(const void*, const void*);

void ssort(void* base, size_t n, size_t sz, CFT cmp)
{
	for (int gap = n/2; 0 < gap; gap /= 2)
		for (int i = gap; i != n; i++)
			for (int j = i - gap; 0 <= j; j -= gap) {
				char* b = static_cast<char*>(base);
				char* pj = b + j*sz;
				char* pjg = b + (j + gap)*sz;
				if (cmp(pjg, pj) < 0 ) {
					for (int k = 0; k != sz; k++) {
						char temp = pj[k];
						pj[k] = pjg[k];
						pjg[k] = temp;
					}
				}
			}
}


