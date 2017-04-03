/*
 * copy_semantics.cpp
 *
 *  Created on: 2016/07/31
 *      Author: sasaki
 */

#include <iostream>
#include <memory>
using namespace std;

struct S {
	int* p;
};

S x {new int{0}};
void f()
{
	cout << "-- f() --\n";

	S y {x};

	cout << "initially; *x.p = " << *x.p << ", *y.p = " << *y.p << '\n';

	*y.p = 1;
	cout << "after *y.p = 1; *x.p = " << *x.p << ", *y.p = " << *y.p << '\n';

	*x.p = 2;
	cout << "after *x.p = 2; *x.p = " << *x.p << ", *y.p = " << *y.p << '\n';

	delete y.p;
	y.p = new int{3};
	cout << "after delete y.p; y.p = new int{3}; *y.p = " << *y.p << '\n';

	*x.p = 4; // terrible
	cout << "after *x.p = 4; *y.p = " << *y.p << '\n';
}

struct S2 {
	shared_ptr<int> p;
};

//S2 x2 {new int{0}};
	// error: could not convert '(operator new(4ull), (<statement>, ((int*)<anonymous>)))' from 'int*' to 'std::shared_ptr<int>'
S2 x2 {shared_ptr<int>(new int{0})};

void f2()
{
	cout << "-- f2() --\n";

	S2 y2 {x2};
	cout << "after S2 y2{x2}; *x2.p: " << *x2.p << ", *y2.p: " << *y2.p << '\n';

	*y2.p = 1;
	cout << "after *y2.p = 1; *x2.p: " << *x2.p << ", *y2.p: " << *y2.p << '\n';

	*x2.p = 2;
	cout << "after *x2.p = 2; *x2.p: " << *x2.p << ", *y2.p: " << *y2.p << '\n';

	y2.p.reset(new int{3});
	cout << "after y2.p.reset(new int{3}); *x2.p: " << *x2.p << ", *y2.p: " << *y2.p << '\n';

	*x2.p = 4;
	cout << "after *x2.p = 4; *x2.p: " << *x2.p << ", *y2.p: " << *y2.p << '\n';
}

using Descriptor = int;
struct Representation {
	static const int W=1000, H=800;
	char canvas[800][1000];
};

class Image {
public:
	Image(const Image& a);
	void write_block(Descriptor);

	Image() : rep{new Representation{}}{ }
	const shared_ptr<Representation>& get_rep() const { return rep;}
private:
	Representation* clone();
	shared_ptr<Representation> rep;
};

Image::Image(const Image& a)
	: rep{a.rep}
{
}

Representation* Image::clone()
{
	return new Representation{*rep};
}

void Image::write_block(Descriptor d)
{
	if (rep.use_count() > 1)
		rep = shared_ptr<Representation>{clone()};
		//rep.reset(clone());

	rep->canvas[100][200] = d;
}

void test_copy_on_write()
{
	cout << "-- test_copy_on_write() --\n";

	Image im1;

	cout << "Image im1; im1.rep = " << im1.get_rep().use_count() << "," << im1.get_rep().get() << endl;

	Image im2{im1};
	cout << "Image im2{im1}; im2.rep = " << im2.get_rep().use_count() << "," << im2.get_rep().get() << endl;

	im2.write_block(10);
	cout << "im2.write_block(); im1.rep = " << im1.get_rep().use_count() << "," << im1.get_rep().get()
			<< "; im2.rep = " << im2.get_rep().use_count() << "," << im2.get_rep().get() << endl;
}

// add main

int main()
{
	f();
	f2();
	test_copy_on_write();
}

