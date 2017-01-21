/*
 * thread_local.cpp
 *
 *  Created on: 2017/01/21
 *      Author: sasaki
 */


#include <thread>
#include <iostream>
using namespace std;
using namespace std::chrono;

template<typename K, typename V>
class Map {
public:
	Map() { }
	static void set_default(const K&, const V&);
	static pair<const K, V> get_default();
private:
	static pair<const K, V> default_value;
};

template<typename K, typename V>
pair<const K, V> Map<K,V>::default_value {K{0},V{0}};

template<typename K, typename V>
void Map<K,V>::set_default(const K& k, const V& v)
{
	default_value.second = v;
}

template<typename K, typename V>
pair<const K, V> Map<K,V>::get_default()
{
	return default_value;
}

void test(int num)
{
	Map<int,thread::id> m;
	thread::id id = this_thread::get_id();
	m.set_default(num, id);

	this_thread::sleep_for(seconds{num});

	cout << num << ":" << id << " - " << m.get_default().second << std::endl;
}

template<typename K, typename V>
class Map2 {
public:
	Map2() { }
	static void set_default(const K&, const V&);
	static pair<const K, V> get_default();
private:
	static thread_local pair<const K, V> default_value;
};

template<typename K, typename V>
thread_local pair<const K, V> Map2<K,V>::default_value {K{0},V{0}};

template<typename K, typename V>
void Map2<K,V>::set_default(const K& k, const V& v)
{
	default_value.second = v;
}

template<typename K, typename V>
pair<const K, V> Map2<K,V>::get_default()
{
	return default_value;
}

void test2(int num)
{
	Map2<int,thread::id> m;
	thread::id id = this_thread::get_id();
	m.set_default(num, id);

	this_thread::sleep_for(seconds{num});

	cout << num << ":" << id << " - " << m.get_default().second << std::endl;
}


int main()
{
	const int nthread = 4;
	thread ths[nthread];

	cout << "-- share class static variable --\n";
	for (int i=0; i<nthread; ++i)
		ths[i] = thread(test, i);
	for (int i=0; i<nthread; ++i)
		ths[i].join();

	cout << "-- thread local storage --\n";
	for (int i=0; i<nthread; ++i)
		ths[i] = thread(test2, i);
	for (int i=0; i<nthread; ++i)
		ths[i].join();
}
