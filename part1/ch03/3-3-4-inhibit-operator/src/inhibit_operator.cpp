/*
 * inhibit_operator.cpp
 *
 *  Created on: 2016/03/27
 *      Author: sasaki
 */


class Shape {
public:
	Shape() { }
	~Shape() {}

	Shape(const Shape&) =delete;
	Shape& operator=(const Shape&) =delete;

	Shape(Shape&&) =delete;
	Shape& operator=(Shape&&) =delete;
};

Shape f()
{
	Shape sh;
	//return sh;		// move constructor/assign
		// use of deleted function 'Shape::Shape(Shape&&)'
}

int main()
{
	Shape sh1;		// default constructor
	//Shape sh2(sh1); // copy constructor
		// use of deleted function 'Shape::Shape(const Shape&)'

	//Shape sh3 = f();
		// use of deleted function 'Shape::Shape(Shape&&)'
}

