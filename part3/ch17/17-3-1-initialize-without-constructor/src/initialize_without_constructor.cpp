/*
 * initialize_without_constructor.cpp
 *
 *  Created on: 2016/07/24
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

int a {1};
char* p {nullptr};


struct Work {
	string author;
	string name;
	int year;
};

Work s9 { "Beethoven",
		"Symphony No. 9 in D minor, Op. 125: Choral",
		1824
};

Work currently_playing { s9 };
Work none { };

Work alpha;

void f()
{
	cout << "-- f() --\n";

	Work beta;

	cout << "alpha.author: " << alpha.author << '\n'
			<< "alpha.name: " << alpha.name << '\n'
			<< "alpha.year: " << alpha.year << '\n';

	cout << "beta.author: " << beta.author << '\n'
			<< "beta.name: " << beta.name << '\n'
			<< "beta.year: " << beta.year << '\n';
}

struct Buf {
	int count;
	char buf[16*1024];
};

Buf buf0;

void g()
{
	cout << "-- g() --\n";

	Buf buf1;
	Buf buf2 {};
	int* p1 = new int;
	int* p2 = new int{};
	int* p3 = new int{7};

	cout << "buf0.count: " << buf0.count <<
			", int(buf0.buf[1000]): " << int(buf0.buf[1000]) << '\n';
	cout << "buf1.count: " << buf1.count <<
			", int(buf1.buf[1000]): " << int(buf1.buf[1000]) << '\n';
	cout << "buf2.count: " << buf2.count <<
			", int(buf2.buf[1000]): " << int(buf2.buf[1000]) << '\n';

	cout << "*p1: " << *p1 << '\n';
	cout << "*p2: " << *p2 << '\n';
	cout << "*p3: " << *p3 << '\n';

	delete p1;
	delete p2;
	delete p3;
}

template<typename T>
class Checked_pointer {
//private:
	// error: no matching function for call to 'Checked_pointer<int>::Checked_pointer(<brace-enclosed initializer list>)'
public:
	T* p;
public:
	T& operator*();
};

Checked_pointer<int> cp {new int{7}};

// add undef func

template<typename T>
inline T& Checked_pointer<T>::operator*()
{
	if (!p) throw runtime_error("Checked_pointer::operator*()");
	return *p;
}

// add main

int main()
{
	cout << "a: " << a << '\n';
	cout << "static_cast<void*>(p): " << static_cast<void*>(p) << '\n';

	cout << "s9.author: " << s9.author << '\n'
			<< "s9.name: " << s9.name << '\n'
			<< "s9.year: " << s9.year << '\n';
	cout << "currently_playing.author: " << currently_playing.author << '\n'
			<< "currently_playing.name: " << currently_playing.name << '\n'
			<< "currently_playing.year: " << currently_playing.year << '\n';
	cout << "none.author: " << none.author << '\n'
			<< "none.name: " << none.name << '\n'
			<< "none.year: " << none.year << '\n';

	f();
	g();

	cout << "*cp: " << *cp << '\n';
}


