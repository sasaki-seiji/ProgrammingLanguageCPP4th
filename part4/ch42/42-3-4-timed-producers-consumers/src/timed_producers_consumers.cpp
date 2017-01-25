/*
 * timed_producers_consumers.cpp
 *
 *  Created on: 2017/01/25
 *      Author: sasaki
 */


#include <thread>
#include <iostream>

#include "Sync_queue.h"
#include "Message.h"

using namespace std;
using namespace std::chrono;

Sync_queue<Message> mq;

void finite_producer()
{
	const int m_count = 50;
	for (int seq = 0; seq < m_count; ++seq ) {
		Message m;
		m.seq = seq;
		m.mes = "sending message from finite_producer() #" + to_string(seq);
		mq.put(move(m));
		this_thread::sleep_for(milliseconds{100});
	}
}

void timed_producer()
try
{
	int seq = 0;
	while (true ) {
		Message m;
		m.seq = seq;
		m.mes = "sending message from timed_producer() #" + to_string(seq);
		mq.put(m, milliseconds{500}, 100);
		++seq;
	}
}
catch (exception& e) {
	cerr << "timed_producer(): " << e.what() << endl;
}

void finite_consumer()
{
	const int m_count = 200;
	for (int i = 0; i < m_count; ++i ) {
		Message m;
		mq.get(m);
		cout << "seq:" << m.seq << ", mes:\"" << m.mes << "\"" << endl;
	}
}

void timed_consumer()
try
{
	while (true) {
		Message m;
		mq.get(m, milliseconds{200});
		cout << "seq:" << m.seq << ", mes:\"" << m.mes << "\"" << endl;
	}
}
catch (exception& e) {
	cerr << "timed_consumer(): " << e.what() << endl;
}

int main()
{
	thread t1 {finite_producer};
	thread t2 {timed_consumer};

	t1.join();
	t2.join();

	thread t3 {timed_producer};
	thread t4 {finite_consumer};

	t3.join();
	t4.join();
}


