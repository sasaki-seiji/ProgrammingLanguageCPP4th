/*
 * raw_storage_iterator.cpp
 *
 *  Created on: 2016/12/11
 *      Author: sasaki
 */

#include <memory>
#include <algorithm>
#include <iostream>
using namespace std;


void test1()
{
	char seed[] = "012345";

	auto pp = get_temporary_buffer<string>(1000);
	if (pp.second < 1000) {
		cerr << "not enough memory\n" ;
		return;
	}
	auto p = raw_storage_iterator<string*,string>(pp.first);
	generate_n(p, pp.second,
		[&]{ next_permutation(seed, seed+sizeof(seed)-1); return seed; });

	for (int i = 0; i < pp.second; ++i)
		cout << pp.first[i] << endl;
}

int main()
{
	test1();
}
