#include "dynamicIndividual.h"

gaia::DynamicIndividual::DynamicIndividual(DynamicIndividualBluePrint bluePrint)
{
	_dna.resize(bluePrint._utilization);

	std::ranges::for_each(_dna, [&](auto& gene)
	{
		gene = bluePrint._completSet[get_random_repeatable(bluePrint._utilization)];
	});
}

gaia::DynamicIndividualBluePrint::DynamicIndividualBluePrint(Repeatability attribute,
															 unsigned int utilization,
															 std::vector<std::any> completSet) : _attribute(attribute), _utilization(utilization), _completSet(completSet)
{
	if (_attribute == Repeatability::Unique)
	{
		assert(_completSet.size() >= _utilization);
	}
}
