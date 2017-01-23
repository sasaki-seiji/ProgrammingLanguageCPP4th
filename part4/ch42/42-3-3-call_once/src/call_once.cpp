/*
 * call_once.cpp
 *
 *  Created on: 2017/01/23
 *      Author: sasaki
 */


#include <thread>
#include <mutex>
#include <iostream>
using namespace std;

struct Y {
	int y;
};

class X {
public:
	X();
	static Y get_Y();

private:
	static once_flag static_flag;
	static Y static_data_for_class_X;
	static void init();
};

once_flag X::static_flag;

void X::init()
{
	cout << "X::init() called from " << this_thread::get_id() << endl;
	static_data_for_class_X = {123};
}

Y X::static_data_for_class_X;

Y X::get_Y(){
	return static_data_for_class_X;
}


X::X()
{
	call_once(static_flag, init);
}

void task()
{
	X x;

	cout << this_thread::get_id() << ": " << X::get_Y().y << endl;
}

int main()
{
	const int nthread = 4;
	thread ths[nthread];

	for (int i=0; i<nthread; ++i) {
		ths[i] = thread{task};
	}
	for (int i=0; i<nthread; ++i) {
		ths[i].join();
	}

}
