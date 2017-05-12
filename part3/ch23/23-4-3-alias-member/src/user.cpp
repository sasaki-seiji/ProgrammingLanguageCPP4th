/*
 * user.cpp
 *
 *  Created on: 2016/09/11
 *      Author: sasaki
 */


#include "Vector.h"
#include <iostream>
using namespace std;

template<typename T>
T sum(const Vector<T>& v)
{
	typename Vector<T>::value_type ans = T{};

	for (typename Vector<T>::const_iterator it = v.begin(); it!=v.end(); ++it)
		ans += *it;

	return ans;
}

int main()
{
	Vector<int> vi{1,1,2,3,5,8,13};

	int ans = sum(vi);
	cout << "sum(vi) returns " << ans << '\n';
}
