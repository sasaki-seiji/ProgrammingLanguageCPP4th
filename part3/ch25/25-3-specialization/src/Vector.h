/*
 * Vector.h
 *
 *  Created on: 2016/09/19
 *      Author: sasaki
 */

#ifndef VECTOR_H_
#define VECTOR_H_

#include <memory>
#include <initializer_list>
#include <iostream>

template<typename T>
class Vector {
	T* v;
	int sz;
public:
	Vector();
	explicit Vector(int);
	Vector(std::initializer_list<T>);
	Vector(const Vector&) = delete;
	Vector& operator=(const Vector&) = delete ;

	~Vector() { delete []v; }

	T& elem(int i) { return v[i]; }
	T& operator[](int i);

	void swap(Vector&);

	T* begin() { return v; }
	const T* begin() const { return v; }
	T* end() { return v+sz; }
	const T* end() const { return v+sz; }
};

template<typename T>
Vector<T>::Vector() : v{nullptr}, sz{0}
{
	std::cout << "Vector<T>::Vector()\n";
}

template<typename T>
Vector<T>::Vector(int s) : v{new T[s]}, sz{s}
{
	std::cout << "Vector<T>::Vector(int)\n";
	std::uninitialized_fill(v,v+s,T{});
}

template<typename T>
Vector<T>::Vector(std::initializer_list<T> il) : v{new T[il.size()]}, sz{il.size()}
{
	std::cout << "Vector<T>::Vector(std::initializer_list<T>)\n";
	std::uninitialized_copy(il.begin(), il.end(), v);
}


template<>
class Vector<void*> {
	void** v;
	int sz;
public:
	Vector();
	explicit Vector(int);
	Vector(std::initializer_list<void*>);
	Vector(const Vector&) = delete;
	Vector& operator=(const Vector&) = delete ;

	~Vector() { delete []v; }

	void*& elem(int i) { return v[i]; }
	void*& operator[](int i);

	void swap(Vector&);

	void** begin() { return v; }
	void** end() { return v+sz; }
};

//template<>
	// error: template-id 'Vector<>' for 'Vector<void*>::Vector()' does not match any template declaration
Vector<void*>::Vector() : v{nullptr}, sz{0}
{
	std::cout << "Vector<void*>::Vector()\n";
}

Vector<void*>::Vector(int s) : v{new void*[s]}, sz{s}
{
	std::cout << "Vector<void*>::Vector(int)\n";
	std::uninitialized_fill(v,v+s,nullptr);
}

Vector<void*>::Vector(std::initializer_list<void*> il) : v{new void*[il.size()]}, sz{il.size()}
{
	std::cout << "Vector<void*>::Vector(std::initializer_list<void*>)\n";
	std::uninitialized_copy(il.begin(), il.end(), v);
}

template<typename T>
class Vector<T*> : private Vector<void*>{
public:
	using Base = Vector<void*>;

	Vector() { };
	explicit Vector(int i) : Base(i) { }
	Vector(std::initializer_list<T*> il) ;

	Vector(const Vector&) = delete;
	Vector& operator=(const Vector&) = delete ;

	T*& elem(int i) { return reinterpret_cast<T*&>(Base::elem(i)); }
	T*& operator[](int i) { return reinterpret_cast<T*&>(Base::operator[](i)); }

	void swap(Vector&);

	T** begin() { return reinterpret_cast<T**>(Base::begin()); }
	T** end() { return reinterpret_cast<T**>(Base::end()); }
};

template<typename T>
Vector<T*>::Vector(std::initializer_list<T*> il)
	:Base(il.size())
{
	auto it = il.begin();
	for (int i = 0; it != il.end(); ++it, ++i)
		Base::elem(i) = *it;
}

#endif /* VECTOR_H_ */
