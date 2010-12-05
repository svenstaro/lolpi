/* 
 * This is a very simple C++ implementation of Bellard's formula for
 * calculating PI.
 * This implementation is GPL3 licensed.
 * Author: Sven-Hendrik Haase <sh@lutzhaase.com>
 */

#include <boost/foreach.hpp>

#include <gmpxx.h>

#include <cmath>
#include <iostream>
#include <string>

#define PRECISION 100000

mpf_class mpf_pow(mpf_class base, mpf_class exp) {
	mpf_class num(base, PRECISION);
	if(exp == 0) {
		num = 1;
	} else {
		while(exp > 1) {
			num *= base;
			--exp;
		}
	}

	return num;
}

int main() {
	std::cout.precision(PRECISION);

	mpf_class pi(0, PRECISION);
	mpf_class n(PRECISION, PRECISION);
	for(mpf_class i(0, PRECISION); i < n; ++i) {
		pi += (
			(mpf_pow(-1, i)/mpf_pow(2, 10 * i)) * (
				-(mpf_pow(2, 5)/(4 * i + 1)) -
				1/(4 * i + 3) +
				mpf_pow(2, 8)/(10 * i + 1) -
				mpf_pow(2, 6)/(10 * i + 3) -
				mpf_pow(2, 2)/(10 * i + 5) -
				mpf_pow(2, 2)/(10 * i + 7) +
				1/(10 * i + 9)
			)
		);
	}
	pi = (1/mpf_pow(2, 6)) * pi; 
	std::cout << pi << std::endl;

	return 0;
}
