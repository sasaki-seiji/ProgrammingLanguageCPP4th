/*
 * allocator.cpp
 *
 *  Created on: 2016/12/10
 *      Author: sasaki
 */

#include <vector>
#include <complex>
#include <iostream>
using namespace std;

template<typename T>
struct Simple_alloc {
	using value_type = T;

	Simple_alloc() { }

	T* allocate(size_t n)
		{ return reinterpret_cast<T*>(new char[n*sizeof(T)]); }
	void deallocate(T* p, size_t n)
		{ delete [] reinterpret_cast<char*>(p); }
};

class Arena {
	void* p;
	int s;

	int used;
public:
	Arena(void* pp, int ss) : p{pp}, s{ss}, used{0} { }

	void* get(size_t n);
	void release(void* p, size_t n) { }
};

void* Arena::get(size_t n)
{
	char* ret = reinterpret_cast<char*>(p) + used;
	if (used + n <= s) {
		used += n;
		return ret;
	}
	return nullptr;
}

template<typename T>
struct My_alloc {
	Arena& a;
	My_alloc(Arena& aa) : a(aa) { }
	My_alloc() { }

	using value_type = T;
	T* allocate(size_t n)
		{ return reinterpret_cast<T*>(a.get(n*sizeof(T))); }
	void deallocate(T* p, size_t n)
		{ a.release(p, n*sizeof(T)); }
};

constexpr int sz {100000};
Arena my_arena1{new char[sz], sz};
Arena my_arena2{new char[10*sz], 10*sz};

vector<int> v0;
vector<int, My_alloc<int>> v1 {My_alloc<int>{my_arena1}};
vector<int, My_alloc<int>> v2 {My_alloc<int>{my_arena2}};
vector<int, Simple_alloc<int>> v3;

template<typename T>
	using Arena_vec = std::vector<T,My_alloc<T>>;
template<typename T>
	using Simple_vec = std::vector<T,Simple_alloc<T>>;

My_alloc<complex<double>> Alloc2 {my_arena2};

Arena_vec<complex<double>> vcd {{{1,2}, {3,4}}, Alloc2};

Simple_vec<string> vs {"Sam Vimes", "Fred Colon", "Nobby Nobbs"};

template<typename T, typename A>
ostream& operator<<(ostream& os, const vector<T,A>& v)
{
	for (auto& x : v)
		os << x << ", ";
	return os;
}

int main()
{
	v0.push_back(100);
	cout << "v0[0]: " << v0[0] << endl;

	v1.push_back(200);
	cout << "v1[0]: " << v1[0] << endl;

	v2.push_back(300);
	cout << "v2[0]: " << v2[0] << endl;

	v3.push_back(400);
	cout << "v3[0]: " << v3[0] << endl;

	cout << "vcd: " << vcd << endl;
	cout << "vs: " << vs << endl;
}
