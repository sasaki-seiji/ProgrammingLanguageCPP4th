/*
 * Cvt_to_upper.h
 *
 *  Created on: 2017/01/05
 *      Author: sasaki
 */

#ifndef CVT_TO_UPPER_H_
#define CVT_TO_UPPER_H_

#include <locale>
using std::codecvt;

class Cvt_to_upper: public codecvt<char, char, mbstate_t>
{
public:
	explicit Cvt_to_upper(size_t r = 0) : codecvt(r) 	{ }

protected:
	using State = mbstate_t;

	result do_in(State& s,
			const char* from, const char* from_end, const char*& from_next,
			char* to, char* to_end, char*& to_next) const override;

	result do_out(State& s,
			const char* from, const char* from_end, const char*& from_next,
			char* to, char* to_end, char*& to_next) const override;

	result do_unshift(State&, char*, char*, char*&) const override
		{ return ok; }

	int do_encoding() const noexcept override { return 1; }
	bool do_always_noconv() const noexcept override { return false; }

	int do_length(State&, const char* from, const char* from_end, size_t max)
		const override;
	int do_max_length() const noexcept override;
};


#endif /* CVT_TO_UPPER_H_ */
