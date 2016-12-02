/*
 * min_max.cpp
 *
 *  Created on: 2016/12/03
 *      Author: sasaki
 */


#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	int x = 7;
	int y = 9;

	//++min(x,y);
		// error: increment of read-only location 'std::min<int>(x, y)'
	//++min({x,y});
		// error: lvalue required as increment operand

	string s = "Large_Hadron_Collider";
	auto p = minmax_element(s.begin(), s.end(),
				[](char c1, char c2){ return toupper(c1) < toupper(c2); });
	cout << "min==" << *(p.first) << " max==" << *(p.second) << '\n';
}
