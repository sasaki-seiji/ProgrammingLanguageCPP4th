/*
 * when_cannot_use_exception.cpp
 *
 *  Created on: 2017/03/09
 *      Author: sasaki
 */

#include <utility>
#include <iostream>
using namespace std;

const int max_size = 100;

template<typename T>
class my_vector {
	int error_code;
	T *elem;
public:
	my_vector(int n) : error_code{0}, elem{nullptr}
	{
		if (n < max_size ) elem = new T[n];
		else error_code = 1;
	}
	int invalid() const { return error_code; }
	~my_vector() { if (!error_code) delete [] elem; }
};

pair<char* ,int> make_vector(int n)
{
	char* p = nullptr;
	int error_code = 0;

	if (n < max_size) p = new char[n];
	else error_code = 1;

	return make_pair(p, error_code);
}

void release_vector(pair<char*,int> p)
{
	delete [] p.first;
}

void f(int n)
{
	cout << "-- f(" << n << ") --\n";

	my_vector<int> x(n);
	if (x.invalid()) {
		cout << "f(): fail to construct my_vector\n";
		return ;
	}
	/////
}

void g(int n)
{
	cout << "-- g(" << n << ") --\n";

	auto v = make_vector(n);
	if (v.second) {
		cout << "g(): fail make_vector()\n";
		return ;
	}
	auto val = v.first;
	val[10] = 'x';
	cout << "val[10]: " << val[10] << endl;
	release_vector(v);
}

int main()
{
	f(10);
	f(1000);
	g(10);
	g(1000);
}

