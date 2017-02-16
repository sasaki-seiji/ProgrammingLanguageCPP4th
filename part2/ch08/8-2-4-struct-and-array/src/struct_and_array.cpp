/*
 * struct_and_array.cpp
 *
 *  Created on: 2016/04/18
 *      Author: sasaki
 */

#include <iostream>
#include <initializer_list>
#include <algorithm>
#include <cassert>
//using namespace std;
using std::cout;
using std::initializer_list;
using std::copy;
using std::uninitialized_copy;
using std::ostream;

struct Point {
	int x, y;
};

ostream& operator<<(ostream& os, const Point p)
{
	os << '{' << p.x << ',' << p.y << '}';
	return os;
}

void print(const Point a[], int s)
{
	for (int i=0; i!=s; ++i)
		cout << a[i] << '\n';
}

Point points[3] {{1,2},{3,4},{5,6}};
int x2 = points[2].x;

struct Point3Array {
	Point elem[3];
#ifdef ELIMINATE_BRACKET
	// 2016.04.18,2016.04.20 add
	Point3Array(const initializer_list<Point>& args)
	{ assert(args.size() == 3);
	  uninitialized_copy(args.begin(), args.end(), elem); }
#endif
};

void print(const Point3Array& pa3)
{
	for (int i=0; i!=3; ++i)
		cout << pa3.elem[i] << '\n';
}

#ifdef ELIMINATE_BRACKET
Point3Array points2 {{1,2},{3,4},{5,6}};
#else
Point3Array points2 {{{1,2},{3,4},{5,6}}};
#endif

int y2 = points2.elem[2].y;

Point3Array shift(Point3Array a, Point p)
{
	for (int i = 0; i!=3; ++i) {
		a.elem[i].x += p.x;
		a.elem[i].y += p.y;
	}
	return a;
}

void test_point3array()
{
	cout << "-- test for Point3Array struct --\n";
	Point3Array ax2 = shift(points2, {10,20});
	print(ax2);
}

template<typename T, size_t N>
struct array {
	using size_type = size_t;
	T elem[N];

	// 2016.04.18 add
	array(const initializer_list<T>& args)
	{ uninitialized_copy(args.begin(), args.end(), elem); }

	T* begin() noexcept { return elem; }
	const T* begin() const noexcept { return elem; }
	T* end() noexcept { return elem+N; }
	const T* end() const noexcept { return elem+N; }

	constexpr size_type size() noexcept { return N; }

	T& operator[](size_type n) { return elem[n]; }
	const T& operator[](size_type n) const { return elem[n]; }

	T* data() noexcept { return elem; }
	const T* data() const noexcept { return elem; }
};

using PointArray = array<Point,3>;

PointArray points3 {{1,2},{3,4},{5,6}};
int x3 = points3[2].x;
int y3 = points3[2].y;

PointArray shift(PointArray a, Point p)
{
	for (size_t i=0; i!=a.size(); ++i) {
		a[i].x += p.x;
		a[i].y += p.y;
	}
	return a;
}

// 2016.04.20 change: for compile error
//template<typename T, int N>
	// no matching function for call to 'print(PointArray&)'
template<typename T, size_t N>
void print(const array<T,N>& a)
{
	for (size_t i=0; i!=a.size(); ++i)
		cout << a[i] << '\n';
}

void test_pointarray()
{
	cout << "-- test for array<Point,3> template struct --\n";
	PointArray ax3 = shift(points3, {10, 20});
	print(ax3);
}

Point point1[] = {{1,2},{3,4},{5,6}};
array<Point,3> point2 = {{1,2},{3,4},{5,6}};
//array<Point> point3 = {{1,2},{3,4},{5,6}};
	// wrong number of template arguments (1, should be 2)
	// error: scalar object ‘point3’ requires one element in initializer

void test_printarray()
{
	cout << "-- test for print built-in array and template array --\n";
	print(point1, 4);
	print(point2);
}

int main()
{
	cout << "::x2 = " << ::x2 << '\n';
	cout << "::y2 = " << ::y2 << '\n';
	cout << "::x3 = " << ::x3 << '\n';
	cout << "::y3 = " << ::y3 << '\n';

	test_point3array();
	test_pointarray();
	test_printarray();
}

