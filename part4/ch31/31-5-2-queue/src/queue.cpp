/*
 * queue.cpp
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
	int code ;
	string str;
};

void server(queue<Message>& q, mutex& m)
{
	while (!q.empty()) {
		Message mess;
		{	lock_guard<mutex> lck(m);
			if (q.empty()) return;
			mess = q.front();
			q.pop();
		}

		cout << mess.str << endl;
	}

}

void client(queue<Message>& q, mutex& m)
{
	for (size_t n = 0; n < 10; ++n) {
		Message mess;
		mess.str = string("client message#") + to_string(n);
		{	lock_guard<mutex> lck(m);
			q.push(mess);
		}
	}
}

int main()
{
	queue<Message> mq;
	mutex mx;
	thread t1 { [&]{ client(mq, mx); } };
	thread t2 { [&]{ server(mq, mx); } };

	t1.join();
	t2.join();
}
