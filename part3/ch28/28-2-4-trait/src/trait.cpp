/*
 * trait.cpp
 *
 *  Created on: 2016/10/05
 *      Author: sasaki
 */

#include "search.h"
#include <vector>
using namespace std;


// add main
int main()
{
	vector<int> vi { 1, 2, 3, 4, 5 };
	int	ai[] = { 1, 2, 3, 4, 5 };

	search(vi.begin(), vi.end(), 3);
	search(begin(ai), end(ai), 3);

	search2(vi.begin(), vi.end(), 3);
	search2(begin(ai), end(ai), 3);

	search3(vi.begin(), vi.end(), 3);
	search3(begin(ai), end(ai), 3);
}
