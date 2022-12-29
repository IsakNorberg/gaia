#include "dynamicIndividual.h"

int gaia::get_Random(Repeatability attribute, unsigned int utilization)
{
	if (attribute == Repeatability::Unique)
	{
		return get_random_unique(utilization);
	}
	else if(attribute == Repeatability::Repeatable)
	{
		return get_random_repeatable(utilization);
	}
	assert(!"No Repeatability with that Attribute");
	return 0;
}
