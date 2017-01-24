/*
 * producers_consumers.cpp
 *
 *  Created on: 2017/01/24
 *      Author: sasaki
 */


#include <thread>
#include <iostream>

#include "Sync_queue.h"
#include "Message.h"

using namespace std;
using namespace std::chrono;

Sync_queue<Message> mq;

void producer()
{
	int seq = 0;
	while (true) {
		Message m;
		m.seq = seq;
		m.mes = "sending message#" + to_string(seq);
		mq.put(move(m));
		seq++;
		this_thread::sleep_for(milliseconds{100});
	}
}

void consumer()
{
	while (true) {
		Message m;
		mq.get(m);
		cout << "seq:" << m.seq << ", mes:\"" << m.mes << "\"" << endl;
	}
}

int main()
{
	thread t1 {producer};
	thread t2 {consumer};

	t1.join();
	t2.join();
}
