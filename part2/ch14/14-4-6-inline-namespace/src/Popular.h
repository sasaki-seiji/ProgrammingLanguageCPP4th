/*
 * Popular.h
 *
 *  Created on: 2016/05/28
 *      Author: sasaki
 */

#ifndef POPULAR_H_
#define POPULAR_H_


namespace Popular {

	inline namespace V3_2 {
		double f(double);
		int f(int);
		template<typename T>
			class C { };
	}

	namespace V3_0 {
		double f(double);
		template<typename T>
			class C { };
	}

	namespace V2_4_2 {
		double f(double);
		template<typename T>
			class C { };
	}

	// 2017.03.22 add: declare namespace member
	template<typename T>
	class Popular::C<T*>;

}


#endif /* POPULAR_H_ */
