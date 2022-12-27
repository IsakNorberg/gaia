#include "random.h"

namespace gaia
{
	
	float get_random_range_normalized(unsigned int precision) noexcept
	{
		assert(precision > 0);
		static time_t t = 0;
		srand(static_cast<int>(time(&t)));
		++t;
		float randomOut  =  static_cast<float>(rand() % precision * 2); // to get negative numbers 
		randomOut = randomOut - precision;         // to get negative numbers 
		randomOut = randomOut / precision;
		return randomOut;
	}

	unsigned int get_random_repeatable(unsigned int utilization) noexcept
	{
		static time_t t = 0;
		srand(static_cast<int>(time(&t)));
		++t;
		return static_cast<unsigned int>(rand() % utilization);;
	}

}
