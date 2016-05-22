/*
 * function_try_block.cpp
 *
 *  Created on: 2016/05/19
 *      Author: sasaki
 */

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class X {
	vector<int> vi;
	vector<string> vs;

public:
	X(int, int);
};

X::X(int sz1, int sz2)
try
	:vi{sz1},
	 vs{sz2}
{

}
catch (std::exception& err) {
	cerr << "X::X(int,int) caught exception: " << err.what() << '\n';
}

int main()
try
{
	X x{1000, -20};
}
catch (...) {
	cerr << "main() caught exception\n";
}
