/*
 * Vector.h
 *
 *  Created on: 2016/03/27
 *      Author: sasaki
 */

#ifndef VECTOR_H_
#define VECTOR_H_

#include <stdexcept>

template<typename T>
class Vector {
private:
	T*	elem;
	int	sz;
public:
	using value_type = T;	// 3.4.5 alias
	Vector(int s);
	~Vector() { delete[] elem; }

	T& operator[](int i);
	const T& operator[](int i) const;
	int size() const { return sz; }
};

// 2016.03.27 add
class Negative_size {};

template<typename T>
Vector<T>::Vector(int s)
{
	if (s < 0) throw Negative_size {};
	elem = new T[s];
	sz = s;
}

template<typename T>
T& Vector<T>::operator[](int i)
{
	if (i < 0 || size() <= i)
		throw std::out_of_range {"Vector::operator[]" };
	return elem[i];
}

template<typename T>
const T& Vector<T>::operator[](int i) const
{
	if (i < 0 || size() <= i)
		throw std::out_of_range {"Vector::operator[]" };
	return elem[i];
}

template<typename T>
const T* begin(const Vector<T>& x)
{
	return x.size() ? &x[0] : nullptr;
}

template<typename T>
const T* end(const Vector<T>& x)
{
	return begin(x) + x.size();
}
#endif /* VECTOR_H_ */
