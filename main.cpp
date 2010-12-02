/* 
 * This is a very simple C++ implementation of Bellard's formula for
 * calculating PI.
 * This implementation is GPL3 licensed.
 * Author: Sven-Hendrik Haase <sh@lutzhaase.com>
 */

#include <boost/foreach.hpp>

#include <cmath>
#include <iostream>
#include <vector>

int main() {
	std::cout.precision(300);
	long double current_value = 0;
	long double n = 10;

	std::vector<long double> pi_store;

	for(long double i = 0; i < n; ++i) {
		current_value = (
			(pow(-1, i)/pow(2, 10 * i)) * (
				-(pow(2, 5)/(4 * i + 1)) -
				1/(4 * i + 3) +
				pow(2, 8)/(10 * i + 1) -
				pow(2, 6)/(10 * i + 3) -
				pow(2, 2)/(10 * i + 5) -
				pow(2, 2)/(10 * i + 7) +
				1/(10 * i + 9)
			)
		);

		pi_store.push_back(current_value);
	}

	long double sum = 0;
	BOOST_FOREACH(long double g, pi_store) {
		sum += g;
		std::cout << (1/pow(2, 6)) * sum << std::endl;
	}

	return 0;
}
