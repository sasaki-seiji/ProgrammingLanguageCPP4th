/*
 * Assert.h
 *
 *  Created on: 2016/05/16
 *      Author: sasaki
 */

#ifndef ASSERT_H_
#define ASSERT_H_

#include <stdexcept>
#include <string>

namespace Assert {

	using namespace std;

	enum class Mode { throw_, terminate_, ignore_ };
	constexpr Mode current_mode = CURRENT_MODE;
	constexpr int current_level = CURRENT_LEVEL;
	constexpr int default_level = 1;

	constexpr bool level(int n)
		{ return n <= current_level; }

	struct Error : runtime_error {
		Error(const string& p) :runtime_error(p) {}
	};

	template<bool condition =level(default_level), typename Except = Error>
	void dynamic(bool assertion, const string& message = "Assert::dynamic failed")
	{
		if (assertion)
			return ;
		if (current_mode == Mode::throw_)
			throw Except{message};
		if (current_mode == Mode::terminate_)
			std::terminate();
	}

	template<>
	inline void dynamic<false, Error>(bool assertion, const string& s)
	{ }

#if 0 // 2017.03.12 delete
	inline void dynamic(bool b, const string& s)
	{
		dynamic<true, Error>(b, s);
	}
	inline void dynamic(bool b)
	{
		dynamic<true, Error>(b);
	}
#endif
	string compose(const char* file, int line, const string& message);


} /* namespace Assert */

#endif /* ASSERT_H_ */
