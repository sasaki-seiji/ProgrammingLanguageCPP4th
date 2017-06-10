/*
 * sort.h
 *
 *  Created on: 2016/09/22
 *      Author: sasaki
 */

#ifndef SORT_H_
#define SORT_H_

#include "Vector.h"
#include <utility>

template<typename T>
bool less(T a, T b)
{
	return a<b;
}

template<typename T>
void sort(Vector<T>& v)
{
	const size_t n = v.size();

	for (int gap=n/2; 0<gap; gap/=2)
		for (int i=gap; i!=n; ++i)
			for (int j=i-gap; 0<=j; j-=gap)
				if (less(v[j+gap],v[j]))
					std::swap(v[j],v[j+gap]);

}


#endif /* SORT_H_ */
