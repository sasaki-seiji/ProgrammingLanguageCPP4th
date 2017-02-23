/*
 * literal_type.cpp
 *
 *  Created on: 2016/04/27
 *      Author: sasaki
 */

#include <iostream>
#include <cmath>
using namespace std;


struct Point {
	int x, y, z;
	constexpr Point up(int d) { return {x, y, z+d}; }
	constexpr Point move(int dx, int dy) { return {x+dx, y+dy}; }
};

constexpr Point origo {0, 0};
const int z = origo.x;

constexpr Point a[] = {
	origo, Point{1,1}, Point{2,2}, origo.move(3,3)
};
constexpr int x = a[1].x;
constexpr Point xy{0,sqrt(2)};

constexpr int square(int x)
{
	return x*x;
}

constexpr int isqrt_helper(int sq, int d, int a)
{
	return sq <= a ? isqrt_helper(sq+d, d+2, a) : d;
}

constexpr int isqrt(int x)
{
	return isqrt_helper(1, 3, x)/2 - 1;
}

constexpr int radial_distance(Point p)
{
	return isqrt(square(p.x)+square(p.y)+square(p.z));
}

constexpr Point p1 {10,20,30};
constexpr Point p2 {p1.up(20)};
constexpr int dist = radial_distance(p2);

ostream& operator<<(ostream& os, const Point&pt)
{
	os << '{' << pt.x << ',' << pt.y << ',' << pt.z << '}';
	return os;
}

int main()
{
	cout << "origo: " << origo << '\n';

	cout << "z: " << z << '\n';

	cout << "a[0]: " << a[0] << '\n';
	cout << "a[1]: " << a[1] << '\n';
	cout << "a[2]: " << a[2] << '\n';
	cout << "a[3]: " << a[3] << '\n';

	cout << "x: " << x << '\n';
	cout << "xy: " << xy << '\n';

	cout << "p1: " << p1 << '\n';
	cout << "p2: " << p2 << '\n';
	cout << "dist: " << dist << '\n';
}

