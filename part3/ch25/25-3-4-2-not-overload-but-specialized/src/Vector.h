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

	int	size() const { return sz; }	// 2016.09.22 add
	T& elem(int i) { return v[i]; }
	T& operator[](int i) { return v[i];}

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


template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& v)
{
	os << "[ ";
	for (T x : v)
		os << x << ' ';
	os << "]";
	return os;
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

	int	size() const { return sz; }	// 2016.09.22 add
	void*& elem(int i) { return v[i]; }
	void*& operator[](int i) { return v[i]; }

	void swap(Vector&);

	void** begin() { return v; }
	void** begin() const { return v; }
	void** end() { return v+sz; }
	void** end() const { return v+sz; }
};

//template<>
	// error: template-id 'Vector<>' for 'Vector<void*>::Vector()' does not match any template declaration
inline Vector<void*>::Vector() : v{nullptr}, sz{0}
{
	std::cout << "Vector<void*>::Vector()\n";
}

inline Vector<void*>::Vector(int s) : v{new void*[s]}, sz{s}
{
	std::cout << "Vector<void*>::Vector(int)\n";
	std::uninitialized_fill(v,v+s,nullptr);
}

inline Vector<void*>::Vector(std::initializer_list<void*> il) : v{new void*[il.size()]}, sz{il.size()}
{
	std::cout << "Vector<void*>::Vector(std::initializer_list<void*>)\n";
	std::uninitialized_copy(il.begin(), il.end(), v);
}

template<typename T>
class Vector<T*> : private Vector<void*>{
	typedef typename std::remove_const<T>::type RCT;

public:
	using Base = Vector<void*>;

	Vector() { std::cout << "Vector<T*>::Vector()\n";};
	explicit Vector(int i) : Base(i) { std::cout << "Vector<T*>::Vector(int)\n"; }
	Vector(std::initializer_list<T*> il) ;

	Vector(const Vector&) = delete;
	Vector& operator=(const Vector&) = delete ;

	int	size() const { return Base::size(); }	// 2016.09.22 add
	T*& elem(int i) // 2016.09.22 change
	{
		RCT*& pr = reinterpret_cast<T*&>(Base::elem(i));
		return const_cast<T*&>(pr);
	}
	T*& operator[](int i)// 2016.09.22 change
	{
		RCT*& pr = reinterpret_cast<RCT*&>(Base::operator[](i));
		return const_cast<T*&>(pr);
	}

	void swap(Vector&);

	T** begin() // 2016.09.22 change
	{
		RCT** p = reinterpret_cast<RCT**>(Base::begin());
		return const_cast<T**>(p);
	}
	T** begin() const // 2016.09.22 add
	{
		RCT** p = reinterpret_cast<RCT**>(Base::begin());
		return const_cast<T**>(p);
	}
	T** end() // 2016.09.22 change
	{
		RCT** p = reinterpret_cast<RCT**>(Base::end());
		return const_cast<T**>(p);
	}
	T** end() const // 2016.09.22 add
	{
		RCT** p = reinterpret_cast<RCT**>(Base::end());
		return const_cast<T**>(p);
	}
};

template<typename T>
Vector<T*>::Vector(std::initializer_list<T*> il)
	:Base(il.size())
{
	std::cout << "Vector<T*>::Vector(std::initializer_list<T*>)\n";
	auto it = il.begin();
	for (int i = 0; it != il.end(); ++it, ++i) {
		// 2016.09.22 change: such as 'const char* -> void*'
		//Base::elem(i) = *it;
		RCT *p = const_cast<RCT*>(*it);
		Base::elem(i) = reinterpret_cast<void*>(p);
	}
}

#endif /* VECTOR_H_ */
