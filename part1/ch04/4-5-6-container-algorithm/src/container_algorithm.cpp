/*
 * container_algorithm.cpp
 *
 *  Created on: 2016/04/03
 *      Author: sasaki
 */

#include <algorithm>

namespace Estd {
	using namespace std;

	template<typename C>
	void sort(C& c)
	{
		sort(c.begin(), c.end());
	}

	template<typename C, typename Pred>
	void sort(C& c, Pred p)
	{
		sort(c.begin(), c.end(), p);
	}
}

#include <vector>
#include <iostream>

using namespace std;
using namespace Estd;

template<typename C>
void print_values(C& c, ostream& os)
{
	for (auto& x : c)
		os << x << '\n';
}

int main()
{
	vector<int> vi { 10, 3, 5, 2, 14, 8};

	cout << "sort vector\n";
	sort(vi);
	print_values(vi, cout);

	cout << "sort vector descendant order\n";
	sort(vi, [](int x, int y){ return y - x; }); // descendant order
	print_values(vi, cout);
}

