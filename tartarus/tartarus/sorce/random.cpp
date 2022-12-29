#include "random.h"

namespace gaia
{
	
	float get_random_range_normalized(unsigned int precision) noexcept
	{
		assert(precision > 0);
		float randomOut  =  static_cast<float>(random(precision) * 2); // to get negative numbers 
		randomOut = randomOut - precision;         // to get negative numbers 
		randomOut = randomOut / precision;
		return randomOut;
	}

	unsigned int get_random_repeatable(unsigned int utilization) noexcept
	{
		return static_cast<unsigned int>(random(utilization));
	}

	unsigned int get_random_unique(unsigned int utilization)
	{
		return utilization -1;
	}

}
