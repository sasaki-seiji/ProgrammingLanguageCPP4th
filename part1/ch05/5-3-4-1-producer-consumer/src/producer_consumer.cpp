/*
 * producer_consumer.cpp
 *
 *  Created on: 2016/04/04
 *      Author: sasaki
 */

#include <queue>
using std::queue;

#include <condition_variable>
using std::condition_variable;

#include <mutex>
using std::mutex;
using std::unique_lock;

#include <string>
using std::string;
using std::to_string;

#include <iostream>
using std::cout;

#include <thread>
using std::thread;
using namespace std::this_thread;

#include <chrono>
using namespace std::chrono;

class Message {
public:
	Message(string m) : mes{m} { }
	string message() { return mes; }
private:
	string	mes;
};

queue<Message> mqueue;
condition_variable mcond;
mutex mmutex;

void consumer()
{
	while(true) {
		unique_lock<mutex> lck {mmutex};
		mcond.wait(lck);

		auto m = mqueue.front();
		mqueue.pop();
		lck.unlock();

		cout << "consumer() gets " << m.message() << '\n';
		cout.flush();

		if( m.message() == "quit" ) break;
	}
}

void producer()
{
	int	seq = 0 ;
	const int max_count = 100;

	while(true) {
		sleep_for(milliseconds{100});

		string mes;
		if( seq < max_count ) mes = string("message#") + to_string(seq++);
		else mes = "quit";

		Message m { mes };

		unique_lock<mutex> lck {mmutex};
		mqueue.push(m);
		mcond.notify_one();

		if( mes == "quit" ) break;
	}
}

int main()
{
	thread th_producer {producer};
	thread th_consumer {consumer};

	th_producer.join();
	th_consumer.join();
}
