/*
 * priority_queue.cpp
 *
 *  Created on: 2016/11/27
 *      Author: sasaki
 */


#include <queue>
#include <mutex>
#include <thread>
#include <string>
#include <iostream>
using namespace std;

struct Message {
	int priority;
	string str;
	bool operator<(const Message& x) const { return priority < x.priority; }
};

void server(priority_queue<Message>& q, mutex& m)
{
	while (!q.empty()) {
		Message mess;
		{	lock_guard<mutex> lck(m);
			if (q.empty()) return;
			mess = q.top();
			q.pop();
		}

		cout << mess.priority << ':' << mess.str << endl;
	}

}

void client(priority_queue<Message>& q, mutex& m)
{
	for (size_t n = 0; n < 10; ++n) {
		Message mess;
		mess.priority = n % 5;
		mess.str = string("client message#") + to_string(n);
		{	lock_guard<mutex> lck(m);
			q.push(mess);
		}
	}
}

int main()
{
	priority_queue<Message> mq;
	mutex mx;
	thread t1 { [&]{ client(mq, mx); } };
	thread t2 { [&]{ server(mq, mx); } };

	t1.join();
	t2.join();
}


