#include "random.h"

namespace gaia
{
	namespace
	{
		inline unsigned int get_pattern(unsigned int range) noexcept
		{
			static bool getZero = false;
			if (getZero)
			{
				getZero = false;
				return 0;
			}
			getZero = true;
			return range-1;
		}
		inline void seed() noexcept
		{
			srand(static_cast<int>(time(nullptr)));
		}
		inline auto random(unsigned int range)  noexcept
		{
			static bool haveRunSeed = true;
			if (haveRunSeed)
			{
				seed();
				haveRunSeed = false;
			}
			if (TEST)
			{
				return get_pattern(range);
			}
			return rand() % range;
		}
	}
	
	float get_random_range_normalized(unsigned int precision) noexcept
	{
		assert(precision > 0);
		float randomOut = static_cast<float>(random(precision) * 2); // to get negative numbers 
		randomOut = randomOut - precision;         // to get negative numbers 
		randomOut = randomOut / precision;
		return randomOut;
	}

	unsigned int get_random_repeatable(unsigned int range) noexcept
	{
		return static_cast<unsigned int>(random(range));
	}


	float get_random_range_normalized_posetiv(unsigned int precision) noexcept
	{
		assert(precision > 0);
		float randomOut = static_cast<float>(random(precision));
		randomOut = randomOut / precision;
		return randomOut;
	}

	bool get_random_bool() noexcept
	{
		bool  outBool = false;
		unsigned const int precision = 1000;
		float const testNumber = get_random_range_normalized(precision);
		if (testNumber > 0)
		{
			outBool = true;
		}
		return outBool;
	}

	void set_random_to_test(bool test) noexcept
	{
		TEST = test;
	}

}
