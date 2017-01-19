/*
 * move_thread.cpp
 *
 *  Created on: 2017/01/19
 *      Author: sasaki
 */


#include <thread>
#include <vector>
#include <iostream>
using namespace std;

void square(int *pi)
{
	*pi *= *pi;
}

int main()
{
	vector<thread> worker(1000);
	vector<int> values(1000);

	for (int i = 0; i!=worker.size(); ++i) {
		values[i] = i;
		thread tmp { square, &values[i] };
		worker[i] = move(tmp);
	}

	for (int i=0; i!=worker.size(); ++i) {
		worker[i].join();
		cout << "square of " << i << " is " << values[i] << endl;
	}
}
