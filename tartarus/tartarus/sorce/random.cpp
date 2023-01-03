#include "random.h"

namespace gaia
{
	
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

	unsigned int get_random_unique(unsigned int utilization) 
	{
		static std::vector<int> genaratedInts;

		while (true)
		{
			const int testValue = random(utilization);
			auto iterator = std::find_if(genaratedInts.begin(), genaratedInts.end(), [testValue](int value)
			{
				return value == testValue;
			});
			if (iterator == genaratedInts.end())
			{
				genaratedInts.push_back(testValue);
				if (genaratedInts.size() == utilization)
				{
					genaratedInts.clear();
				}
				return testValue;
			}
		}
		assert(!"");
		return 0;
	}

	float get_random_range_normalized_posetiv(unsigned int precision) noexcept
	{
		assert(precision > 0);
		float randomOut = static_cast<float>(random(precision));
		randomOut = randomOut / precision;
		return randomOut;
	}

}
