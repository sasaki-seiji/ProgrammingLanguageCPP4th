/*
 * while_statement.cpp
 *
 *  Created on: 2016/04/24
 *      Author: sasaki
 */

#include <iostream>
#include <vector>
using namespace std;

template<typename Iter, typename Value>
Iter find(Iter first, Iter last, Value val)
{
	while (first!=last && *first!=val)
		++first;
	return first;
}

int main()
{
	vector<int> vi = {3, 4, 2, 7, 1, 8, 10, 2};

	auto it = find(vi.begin(), vi.end(), 7);
	cout << ((it != vi.end()) ? "found 7" : "not found 7" ) << '\n';

	it = find(vi.begin(), vi.end(), 9);
	cout << ((it != vi.end()) ? "found 9" : "not found 9" ) << '\n';

}

