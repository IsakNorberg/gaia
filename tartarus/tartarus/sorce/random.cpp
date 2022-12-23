#include "random.h"

namespace gaia
{
	
	float getRandom(unsigned int precision)
	{
		assert(precision > 0);
		static time_t t = 0;
		srand(static_cast<int>(time(&t)));
		++t;
		float randomOut  =  static_cast<float>(rand() % precision * 2); // to get negative numbers 
		randomOut = randomOut - precision;         //
		randomOut = randomOut / precision;
		return randomOut;
	}

}
