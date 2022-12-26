#pragma once
#include <assert.h>
#include <time.h>
#include <cstdlib>

namespace gaia
{
	//normalized
	//Get a random float between -1 and 1 with a given precision
	float get_Random_Range_Normalized(unsigned  int precision) noexcept;

}