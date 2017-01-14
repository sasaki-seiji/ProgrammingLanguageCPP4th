/*
 * sampling.cpp
 *
 *  Created on: 2017/01/14
 *      Author: sasaki
 */

#include <random>
#include <algorithm>
#include <iostream>
using namespace std;

template<typename Iter, typename Size, typename Out, typename Gen>
Out random_sample(Iter first, Iter last, Out result, Size n, Gen&& gen)
{
	using Dist = uniform_int_distribution<Size>;
	using Param = typename Dist::param_type;

	//copy(first, n, result);
	copy(first, first+n, result);
	advance(first, n);

	Dist dist;
	for (Size k = n; first!=last; ++first, ++k) {
		Size r = dist(gen, Param{0,k});
		if (r < n)
			*(result + r) = *first;
	}
	return result;
}

int main()
{
	vector<int> pop(1000);
	vector<int> res(20);

	for (size_t i=0; i<pop.size(); ++i)
		pop[i] = i;

	random_sample(pop.begin(), pop.end(), res.begin(), res.size(),
			default_random_engine{});

	for (auto x : res)
		cout << x << ' ';
	cout << endl;
}
