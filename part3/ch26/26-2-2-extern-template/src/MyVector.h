/*
 * MyVector.h
 *
 *  Created on: 2016/09/24
 *      Author: sasaki
 */

#ifndef MYVECTOR_H_
#define MYVECTOR_H_


#include <memory>
#include <initializer_list>
#include <iostream>

template<typename T>
class MyVector {
	T* v;
	size_t sz;
public:
	MyVector();
	explicit MyVector(size_t);
	MyVector(std::initializer_list<T>);
	MyVector(const MyVector&) = delete;
	MyVector& operator=(const MyVector&) = delete ;

	~MyVector() { delete []v; }

	size_t	size() const { return sz; }	// 2016.09.22 add
	T& elem(size_t i) { return v[i]; }
	T& operator[](size_t i) { return v[i];}

	void swap(MyVector&);

	T* begin() { return v; }
	const T* begin() const { return v; }
	T* end() { return v+sz; }
	const T* end() const { return v+sz; }
};

template<typename T>
MyVector<T>::MyVector() : v{nullptr}, sz{0}
{
	std::cout << "MyVector<T>::MyVector()\n";
}

template<typename T>
MyVector<T>::MyVector(size_t s) : v{new T[s]}, sz{s}
{
	std::cout << "MyVector<T>::MyVector(size_t)\n";
}

template<typename T>
MyVector<T>::MyVector(std::initializer_list<T> il) : v{new T[il.size()]}, sz{il.size()}
{
	std::cout << "MyVector<T>::MyVector(std::initializer_list<T>)\n";
	std::copy(il.begin(), il.end(), v);
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const MyVector<T>& v)
{
	os << "[ ";
	for (T x : v)
		os << x << ' ';
	os << "]";
	return os;
}


#endif /* MYVECTOR_H_ */
