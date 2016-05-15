/*
 * finally.cpp
 *
 *  Created on: 2016/05/15
 *      Author: sasaki
 */

#include <iostream>
#include <cstdlib>
using namespace std;

template<typename F>
struct Final_action {
	Final_action(F f) :clean{f} {}
	~Final_action() { clean(); }
	F clean;
	//Final_action(const Final_action&) =delete;
		// use of deleted function 'Final_action<F>::Final_action(const Final_action<F>&) [with F = test()::<lambda()>]'
	Final_action& operator=(const Final_action&) =delete;
};

template<typename F>
Final_action<F> finally(F f)
{
	return Final_action<F>(f);
		// use of deleted function 'Final_action<F>::Final_action(const Final_action<F>&) [with F = test()::<lambda()>]'
}

void test()
{
	int* p = new int{7};
	int* buf = (int*)malloc(100*sizeof(int));

	auto act1 = finally([&]{ delete p;
								free(buf);
								cout << "Goodby, Cruel world!\n";
							}
				);

	int var = 0;
	cout << "var = " << var << '\n';

	{
		var = 1;
		auto act2 = finally([&]{ cout << "finally!\n"; var = 7; });
			// use of deleted function 'Final_action<F>::Final_action(const Final_action<F>&) [with F = test()::<lambda()>]'
		cout << "var = " << var << '\n';
	}

	cout << "var = " << var << '\n';
}

int main()
{
	test();
}
