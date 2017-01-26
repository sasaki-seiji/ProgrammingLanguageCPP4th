/*
 * future.cpp
 *
 *  Created on: 2017/01/26
 *      Author: sasaki
 */


#include <thread>
#include <iostream>
#include "future_extension.h"

using namespace std;
using namespace std::chrono;

void wait_for_all_promise(vector<promise<int>>& vp)
{
	cout << "--- wait_for_all_promise() ---\n";

	vector<future<int>> vf;
	for (auto& pr : vp)
		vf.push_back(pr.get_future());
	vector<int> res = wait_for_all(vf);

	for (auto x : res)
		cout << x << endl;
}

void wait_for_any_promise(vector<promise<int>>& vp)
{
	cout << "--- wait_any_all_promise() ---\n";

	vector<future<int>> vf;
	for (auto& pr : vp)
		vf.push_back(pr.get_future());

	for (int count = vp.size(); count; --count) {
		int i = wait_for_any(vf, microseconds{10});
		cout << vf[i].get() << endl;
	}
}

void set_all_promise(vector<promise<int>>& vp)
{
	for (size_t i = 0; i != vp.size(); ++i) {
		vp[i].set_value(i);
		this_thread::sleep_for(milliseconds{400});
	}
}

int main()
{
	vector<promise<int>> vp1;

	for (int i=0; i<5; ++i) {
		vp1.push_back(promise<int>{});
	}

	thread tw1 {wait_for_all_promise, ref(vp1)};
	thread ts1 {set_all_promise, ref(vp1)};
	tw1.join();
	ts1.join();

	vector<promise<int>> vp2;

	for (int i=0; i<5; ++i) {
		vp2.push_back(promise<int>{});
	}

	thread tw2 {wait_for_any_promise, ref(vp2)};
	thread ts2 {set_all_promise, ref(vp2)};
	tw2.join();
	ts2.join();
}
