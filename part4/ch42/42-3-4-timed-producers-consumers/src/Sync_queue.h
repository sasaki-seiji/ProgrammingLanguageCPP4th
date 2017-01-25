/*
 * Sync_queue.h
 *
 *  Created on: 2017/01/24
 *      Author: sasaki
 */

#ifndef SYNC_QUEUE_H_
#define SYNC_QUEUE_H_


#include <mutex>
#include <condition_variable>
#include <chrono>
#include <list>
using std::mutex;
using std::condition_variable;
using std::lock_guard;
using std::unique_lock;
using std::list;
using std::move;
using std::chrono::steady_clock;
using std::runtime_error;

template<typename T>
class Sync_queue {
public:
	void put(const T& val);
	void put(T&& val);
	void put(const T& val, steady_clock::duration d, size_t n);
	void get(T& val);
	void get(T& val, steady_clock::duration d);
private:
	mutex mtx;
	condition_variable cond;
	list<T> q;
};

template<typename T>
void Sync_queue<T>::put(const T& val)
{
	lock_guard<mutex> lck(mtx);
	q.push_back(val);
	cond.notify_one();
}

template<typename T>
void Sync_queue<T>::put(T&& val)
{
	lock_guard<mutex> lck(mtx);
	q.push_back(move(val));
	cond.notify_all();
}

template<typename T>
void Sync_queue<T>::put(const T& val, steady_clock::duration d, size_t n)
{
	unique_lock<mutex> lck(mtx);
	bool not_full = cond.wait_for(lck, d, [this,n]{ return q.size() < n; });
	if (not_full) {
		q.push_back(val);
		cond.notify_all();
	}
	else {
		cond.notify_all();
		throw runtime_error{"Sync_queue: put() timeout"};
	}
}

template<typename T>
void Sync_queue<T>::get(T& val)
{
	unique_lock<mutex> lck(mtx);
	cond.wait(lck, [this]{ return !q.empty(); });
	val = q.front();
	q.pop_front();
	cond.notify_all(); // 2017.01.25 add
}

template<typename T>
void Sync_queue<T>::get(T& val, steady_clock::duration d)
{
	unique_lock<mutex> lck(mtx);
	bool not_empty = cond.wait_for(lck, d, [this]{ return !q.empty(); });
	if (not_empty) {
		val = q.front();
		q.pop_front();
		cond.notify_all(); // 2017.01.25 add
	}
	else
		throw runtime_error{"Sync_queue: get() timeout"};
}

#endif /* SYNC_QUEUE_H_ */
