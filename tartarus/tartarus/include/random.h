#pragma once
#include <assert.h>
#include <time.h>
#include <cstdlib>

namespace gaia
{
	//normalized
	//Get a random float between -1 and 1 with a given precision
	float get_random_range_normalized(unsigned  int precision) noexcept;
	unsigned int get_random_repeatable(unsigned int utilization) noexcept;
	unsigned int get_random_unique(unsigned int utilization);

	namespace
	{
		inline void seed() noexcept
		{
			srand(static_cast<int>(time(0)));
		}
		inline auto random(unsigned int i) noexcept
		{
			static bool once = true;
			if(once)
			{
				seed();
				once = false;
			}
			return rand() % i;
		}
		
	}
}