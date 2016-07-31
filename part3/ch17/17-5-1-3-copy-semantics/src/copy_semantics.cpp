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
	S y {x};

	cout << "*x.p: " << *x.p << ", *y.p: " << *y.p << '\n';

	*y.p = 1;
	*x.p = 2;
	cout << "*x.p: " << *x.p << ", *y.p: " << *y.p << '\n';

	delete y.p;
	y.p = new int{3};
	cout << "*y.p: " << *y.p << '\n';

	*x.p = 4; // terrible

	cout << "*y.p: " << *y.p << '\n';
}

struct S2 {
	shared_ptr<int> p;
};

//S2 x2 {new int{0}};
	// error: could not convert '(operator new(4ull), (<statement>, ((int*)<anonymous>)))' from 'int*' to 'std::shared_ptr<int>'
S2 x2 {shared_ptr<int>(new int{0})};

void f2()
{
	S2 y2 {x2};
	cout << "*x2.p: " << *x2.p << ", *y2.p: " << *y2.p << '\n';

	*y2.p = 1;
	*x2.p = 2;
	cout << "*x2.p: " << *x2.p << ", *y2.p: " << *y2.p << '\n';

	y2.p.reset(new int{3});
	*x2.p = 4;
	cout << "*x2.p: " << *x2.p << ", *y2.p: " << *y2.p << '\n';
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
	Representation* get_rep() const { return rep.get();}
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
		//rep = shared_ptr<Representation>{clone()};
		rep.reset(clone());

	rep->canvas[100][200] = d;
}

// add main

int main()
{
	f();
	f2();

	Image im1;
	cout << "im1.get_rep(): " << im1.get_rep() << '\n';

	Image im2{im1};
	cout << "im2.get_rep(): " << im2.get_rep() << '\n';

	im2.write_block(10);
	cout << "im2.get_rep(): " << im2.get_rep() << '\n';
}

