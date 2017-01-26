/*
 * task_server.cpp
 *
 *  Created on: 2017/01/26
 *      Author: sasaki
 */


#include <future>
#include <cmath>
#include <iostream>
#include "Sync_queue.h"

using namespace std;

using Res = double;
using Args = double;
using PTT = Res(Args);

Sync_queue<packaged_task<PTT>> server;

Res f(Args a) { return a + 1.0; }
struct G {
	Res operator()(Args a) { return a * 2.0; }
};
auto h = [=](Args a) { return sqrt(a); };

void requestor()
{
	packaged_task<PTT> job1(f);
	packaged_task<PTT> job2(G{});
	packaged_task<PTT> job3(h);

	auto f1 = job1.get_future();
	auto f2 = job2.get_future();
	auto f3 = job3.get_future();

	server.put(move(job1));
	server.put(move(job2));
	server.put(move(job3));

	auto r1 = f1.get();
	auto r2 = f2.get();
	auto r3 = f3.get();

	cout << "r1=" << r1 << endl;
	cout << "r2=" << r2 << endl;
	cout << "r3=" << r3 << endl;
}

void task_server()
{
	while(true) {
		packaged_task<PTT> t;
		server.get(t);
		t(1.23);
	}
}

int main()
{
	thread tc {requestor};
	thread ts {task_server};

	tc.join();
	ts.join();
}
