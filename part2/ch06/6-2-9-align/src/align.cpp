/*
 * align.cpp
 *
 *  Created on: 2016/04/09
 *      Author: sasaki
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <ostream>
using namespace std;

auto ac = alignof(char);
auto ai = alignof(int);
struct T { int i; };
auto ad = alignof(T);

int a[20];
auto aa = alignof(decltype(a));

struct X {
	char	c;
	int 	i;
	double	d;
	ostream& print(ostream& os) {
		os << "c{'" << c << "'}, i{"<< i << "}, d{" << d << "}\n";
		return os;
	}
};

void user(const vector<X>& vx)
{
	constexpr int bufmax = 1024;
	alignas(X) char buffer[bufmax];

	const int max = min(vx.size(), bufmax/sizeof(X));
	uninitialized_copy(vx.begin(), vx.begin()+max, reinterpret_cast<X*>(buffer));

	X* px = reinterpret_cast<X*>(buffer);
	for (X* p = px; p < px + max; ++p)
		p->print(cout);
}

int main()
{
	cout << "alignof(char) -> " << ac << '\n';
	cout << "alignof(int) -> " << ai << '\n';
	cout << "alignof(T) where struct T { int i; } -> " << ad << '\n';
	cout << "alignof(decltype(a)) where int a[20] -> " << aa << '\n';

	vector<X> vx = {
		{ 'a', 1, 1.1 },
		{ 'b', 2, 2.2 },
		{ 'c', 3, 3.3 },
		{ 'd', 4, 4.4 },
		{ 'e', 5, 5.5 },
	};
	user(vx);
}
