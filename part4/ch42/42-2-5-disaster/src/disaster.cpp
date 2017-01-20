/*
 * disaster.cpp
 *
 *  Created on: 2017/01/20
 *      Author: sasaki
 */


#include <thread>
#include <iostream>
using namespace std;
using namespace std::chrono;

void home()
{
	int var;
	thread disaster {[&]{ this_thread::sleep_for(milliseconds{1}); ++var; } };
	disaster.detach();
}

int other_func(int i, int j)
{
	int ans = i+j;
	//cout << "i+j=" << ans << endl;
	return ans;
}

int main()
{
	const int count=100000;

	home();

	for (int i=0; i<count; ++i)
		for (int j=0; j<count; ++j)
			if (other_func(i,j) != i+j) cerr << "trouble" << endl;

}
