/*
 * pod.cpp
 *
 *  Created on: 2016/04/21
 *      Author: sasaki
 */


#include <iostream>
#include <type_traits>
#include <vector>
using namespace std;


struct S0 { };
struct S1 { int a; };
struct S2 { int a; S2(int aa) : a(aa) { } };
struct S3 { int a; S3(int aa) : a(aa) { } S3() { } };
struct S4 { int a; S4(int aa) : a(aa) { } S4() = default; };

struct S5 { virtual void f(); };

struct S6 : S1 { };
struct S7 : S0 { int b; };
struct S8 : S1 { int b; };
struct S9 : S0, S1 { };

void test_pod()
{
	cout << "is_pod<S0>::value ? " << is_pod<S0>::value << '\n';
	cout << "  is_standard_layout<S0>::value ? " << is_standard_layout<S0>::value << '\n';
	cout << "  is_trivially_copyable<S0>::value ? " << is_trivially_copyable<S0>::value << '\n';
	cout << "  is_trivially_default_constructible<S0>::value ? " << is_trivially_default_constructible<S0>::value << '\n';

	cout << "is_pod<S1>::value ? " << is_pod<S1>::value << '\n';
	cout << "  is_standard_layout<S1>::value ? " << is_standard_layout<S1>::value << '\n';
	cout << "  is_trivially_copyable<S1>::value ? " << is_trivially_copyable<S1>::value << '\n';
	cout << "  is_trivially_default_constructible<S1>::value ? " << is_trivially_default_constructible<S1>::value << '\n';

	cout << "is_pod<S2>::value ? " << is_pod<S2>::value << '\n';
	cout << "  is_standard_layout<S2>::value ? " << is_standard_layout<S2>::value << '\n';
	cout << "  is_trivially_copyable<S2>::value ? " << is_trivially_copyable<S2>::value << '\n';
	cout << "  is_trivially_default_constructible<S2>::value ? " << is_trivially_default_constructible<S2>::value << '\n';

	cout << "is_pod<S3>::value ? " << is_pod<S3>::value << '\n';
	cout << "  is_standard_layout<S3>::value ? " << is_standard_layout<S3>::value << '\n';
	cout << "  is_trivially_copyable<S3>::value ? " << is_trivially_copyable<S3>::value << '\n';
	cout << "  is_trivially_default_constructible<S3>::value ? " << is_trivially_default_constructible<S3>::value << '\n';

	cout << "is_pod<S4>::value ? " << is_pod<S4>::value << '\n';
	cout << "  is_standard_layout<S4>::value ? " << is_standard_layout<S4>::value << '\n';
	cout << "  is_trivially_copyable<S4>::value ? " << is_trivially_copyable<S4>::value << '\n';
	cout << "  is_trivially_default_constructible<S4>::value ? " << is_trivially_default_constructible<S4>::value << '\n';

	cout << "is_pod<S5>::value ? " << is_pod<S5>::value << '\n';
	cout << "  is_standard_layout<S5>::value ? " << is_standard_layout<S5>::value << '\n';
	cout << "  is_trivially_copyable<S5>::value ? " << is_trivially_copyable<S5>::value << '\n';
	cout << "  is_trivially_default_constructible<S5>::value ? " << is_trivially_default_constructible<S5>::value << '\n';

	cout << "is_pod<S6>::value ? " << is_pod<S6>::value << '\n';
	cout << "  is_standard_layout<S6>::value ? " << is_standard_layout<S6>::value << '\n';
	cout << "  is_trivially_copyable<S6>::value ? " << is_trivially_copyable<S6>::value << '\n';
	cout << "  is_trivially_default_constructible<S6>::value ? " << is_trivially_default_constructible<S6>::value << '\n';

	cout << "is_pod<S7>::value ? " << is_pod<S7>::value << '\n';
	cout << "  is_standard_layout<S7>::value ? " << is_standard_layout<S7>::value << '\n';
	cout << "  is_trivially_copyable<S7>::value ? " << is_trivially_copyable<S7>::value << '\n';
	cout << "  is_trivially_default_constructible<S7>::value ? " << is_trivially_default_constructible<S7>::value << '\n';

	cout << "is_pod<S8>::value ? " << is_pod<S8>::value << '\n';
	cout << "  is_standard_layout<S8>::value ? " << is_standard_layout<S8>::value << '\n';
	cout << "  is_trivially_copyable<S8>::value ? " << is_trivially_copyable<S8>::value << '\n';
	cout << "  is_trivially_default_constructible<S8>::value ? " << is_trivially_default_constructible<S8>::value << '\n';

	cout << "is_pod<S9>::value ? " << is_pod<S9>::value << '\n';
	cout << "  is_standard_layout<S9>::value ? " << is_standard_layout<S9>::value << '\n';
	cout << "  is_trivially_copyable<S9>::value ? " << is_trivially_copyable<S9>::value << '\n';
	cout << "  is_trivially_default_constructible<S9>::value ? " << is_trivially_default_constructible<S9>::value << '\n';

}

template<typename T>
void mycopy(T* to, const T* from, int count)
{
	if (is_pod<T>::value) {
		memcpy(to, from, count*sizeof(T));
		cout << "memcpy()\n";
	}
	else {
		for (int i=0; i!=count; ++i)
			to[i] = from[i];
		cout << "member wise copy\n";
	}
}

int main()
{
	test_pod();

	int	ia1[10], ia2[10];
		// 'int' has trivial default constructor, so array do not initialize each element
	string sa1[10], sa2[10];
		// 'string' has non-trivial default constructor, so array initialize each element

	mycopy(ia1, ia2, 10);
	mycopy(sa1, sa2, 10);
}
