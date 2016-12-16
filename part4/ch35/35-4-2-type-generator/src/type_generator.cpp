/*
 * type_generator.cpp
 *
 *  Created on: 2016/12/16
 *      Author: sasaki
 */


#include <type_traits>
#include <typeinfo>
#include <utility>
#include <vector>
#include <string>
using namespace std;

#include "concept.h"
using namespace Estd;

template<typename K, typename V>
class My_map {
	pair<typename add_const<K>::type, V> default_node;
};

template<typename K, typename V>
class My_map2 {
	pair<Add_const<K>, V> default_node;
};

template<typename T>
void f(T&& v)
{
	Remove_reference<T> x = v;
	++x;

	T y = v;
	++y;

	vector<Remove_reference<T>> vec1;
	//vector<T> vec2;
		// error: forming pointer to reference type 'std::allocator_traits<std::allocator<int&> >::value_type {aka int&}'
}

void user()
{
	cout << "-- user() --\n";

	int val = 7;
	cout << "val: " << val << endl;

	f(val);
	cout << "val: " << val << endl;

	f(7);
	cout << "val: " << val << endl;
}

void change_array()
{
	cout << "-- change_array() --\n";

	int a[10][20];
	Remove_extent<decltype(a)> a20;
	Remove_all_extents<decltype(a)> i;

	cout << Extent<decltype(a20)>() << ' ' << Extent<decltype(i)>() << '\n';
}

template<typename T>
void f2(T&& x)
{
	Add_pointer<T> p = new Remove_reference<T>{};
	*p = x;
	cout << "*p: " << *p << endl;

	//T *p2 = new T{};
		// error: forming pointer to reference type 'int&'
}

void change_pointer()
{
	cout << "-- change_pointer() --\n";

	int v = 7;
	f2(v);
	f2(7);
}

struct Shape {
	virtual void draw() = 0;
	virtual ~Shape() { }
};

struct Circle : public Shape {
	void draw() override { cout << "Circle::draw()\n"; }
};

template<typename... T> struct my_common_type;

template<typename T>
struct my_common_type<T> {
	using type = T;
};

template<typename T, typename U>
struct my_common_type<T,U> {
	using type = decltype(true ? declval<T>() : declval<U>());
};

template<typename T, typename U, typename... V>
struct my_common_type<T, U, V...> {
	using type = typename my_common_type<typename my_common_type<T,U>::type, V...>::type;
};

template<typename... T>
using My_common_type = typename my_common_type<T...>::type;

void test_common_type()
{
	cout << "-- test_common_type() --\n";

	Common_type<int,double> x1;
	//Common_type<int,string> x2;
		// error: no type named 'type' in 'struct std::common_type<int, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >'
	Common_type<int,short,long,long long> x3;
	Common_type<Shape*,Circle*> x4;
	Common_type<void*,double*,Shape*> x5;

	cout << "Common_type<int,double>: " << typeid(x1).name() << endl;
	cout << "Common_type<int,short,long,long long>: " << typeid(x3).name() << endl;
	cout << "Common_type<Shape*,Circle*>: " << typeid(x4).name() << endl;
	cout << "Common_type<void*,double*,Shape*>: " << typeid(x5).name() << endl;

	My_common_type<int,double> y1;
	My_common_type<int,short,long,long long> y3;
	My_common_type<Shape*,Circle*> y4;
	My_common_type<void*,double*,Shape*> y5;

	cout << "My_ommon_type<int,double>: " << typeid(y1).name() << endl;
	cout << "My_common_type<int,short,long,long long>: " << typeid(y3).name() << endl;
	cout << "My_common_type<Shape*,Circle*>: " << typeid(y4).name() << endl;
	cout << "My_common_type<void*,double*,Shape*>: " << typeid(y5).name() << endl;
}

int ff(int) { return 2; }

typedef bool (*PF)(int);

struct Fct {
	double operator()(string) { return 9.8;}
	string operator()(int,int) { return "str"; }
};

auto fx = [](char ch) { return tolower(ch,locale()); };

void test_result_of()
{
	cout << "-- test_result_of() --\n";

	Result_of<decltype(&ff)(int)> r1 = 7;
	Result_of<PF(int)> r2 = true;
	Result_of<Fct(string)> r3 = 9.9;
	Result_of<Fct(int,int)> r4 = "Hero";
	Result_of<decltype(fx)(char)> r5 = 'a';

	cout << "r1: " << r1 << endl;
	cout << "r2: " << r2 << endl;
	cout << "r3: " << r3 << endl;
	cout << "r4: " << r4 << endl;
	cout << "r5: " << r5 << endl;
}

int f();
string f(int);

void test2_result_of()
{
	cout << "-- test2_result_of() --\n";

	//Result_of<decltype(&f)()> r1 = 7;
		// error: decltype cannot resolve address of overloaded function

	//Result_of<ff> r12 = 7;
		// error: type/value mismatch at argument 1 in template parameter list for 'template<class FX> using Result_of = typename std::result_of::type'
	//Result_of<ff(2)> r13 = 7;
		// error: call to non-constexpr function 'int ff(int)'
	//Result_of<decltype(ff)(int)> r2 = 7;
		// error: 'type name' declared as function returning a function
	Result_of<decltype(ff)*(int)> r3 = 7;
	//Result_of<decltype(ff(2))> r4 = 7;
		// error: invalid use of incomplete type 'class std::result_of<int>'

	cout << "r3: " << r3 << endl;
}

template<typename F, typename A>
auto temp(F f, A a) -> Result_of<F(A)>
{
	return f(a);
}

void f4()
{
	cout << "-- f4() --\n";

	int x = temp(ff,1);
	char c = temp(fx,'A');
	double d = temp(Fct(),"Ulysses");

	cout << "x: " << x << endl;
	cout << "c: " << c << endl;
	cout << "d: " << d << endl;
}

int main()
{
	My_map<string, int> m;
	My_map2<string, int> m2;

	user();

	change_array();
	change_pointer();
	test_common_type();
	test_result_of();
	test2_result_of();
	f4();
}
