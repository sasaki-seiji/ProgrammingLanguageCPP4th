/*
 * unique_ptr.cpp
 *
 *  Created on: 2016/12/07
 *      Author: sasaki
 */


#include <memory>
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

unique_ptr<int[]> make_sequence(int n)
{
	unique_ptr<int[]> p {new int[n]};
	for (int i = 0; i < n; ++i)
		p[i] = i;
	return p;
}

class Shape {
public:
	virtual void draw() { };
};

struct Point {
	int x, y;
};

class Circle : public Shape {
private:
	Point center;
	int radius;
public:
	Circle(Point pt, int r) : center{pt}, radius{r} { }
	void draw()
	{ cout << "Circle::draw(): center.x=" << center.x
		<< ", center.y=" << center.y << ", radius=" << radius << endl; }
};

unique_ptr<int> f(unique_ptr<int> p)
{
	++*p;
	return p;
}
void f2(const unique_ptr<int>& p)
{
	++*p;
}
void use()
{
	unique_ptr<int> p {new int{7}};
	//p=f(p);
		// error: use of deleted function 'std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = int; _Dp = std::default_delete<int>]'
	p=f(move(p));
	cout << "*p: " << *p << endl;
	f2(p);
	cout << "*p: " << *p << endl;
}

extern "C" char* get_data(const char* data)
{
	char* p = (char*)malloc(strlen(data)+1);
	strcpy(p, data);
	return p;
}

using PtoCF = void(*)(void*);

void test()
{
	unique_ptr<char,PtoCF> p {get_data("my_data"), free};
	cout << "p: " << p.get() << endl;
}

template<typename T, typename... Args>
unique_ptr<T> make_unique(Args&&... args)
{
	return unique_ptr<T>{new T{args...}};
}

int main()
{
	unique_ptr<int[]> pseq = make_sequence(10);
	for (int i = 0 ; i < 10; ++i)
		cout << pseq[i] << ',';
	cout << endl;

	Point p1 { -10, 10 }, p2 { 10, -10 };
	unique_ptr<Shape> ps {new Circle{p1,20}};
	//unique_ptr<Shape[2]> pa { new Circle[2]{ Circle{p1,20}, Circle{p2,40} } };
		// error: no matching function for call to 'std::unique_ptr<Shape [2]>::unique_ptr(<brace-enclosed initializer list>)'
	ps->draw();

	use();

	test();

	auto p = make_unique<int>(10);
	cout << "*p: " << *p << endl;
}
