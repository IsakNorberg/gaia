#pragma once
#include <assert.h>
#include <time.h>
#include <cstdlib>
#include <vector>
#include <algorithm>

namespace gaia
{
	//normalized
	//Get a random float between -1 and 1 with a given precision
	float get_random_range_normalized(unsigned  int precision) noexcept;
	unsigned int get_random_repeatable(unsigned int range) noexcept;
	unsigned int get_random_unique(unsigned int utilization);
	float get_random_range_normalized_posetiv(unsigned  int precision) noexcept;
	bool get_random_bool() noexcept;

}