#include "normalizedIndividual.h"

gaia::NormalizedIndividual::NormalizedIndividual(NormalizedIndividualBluePrint bluePrint)
{
	_precision = bluePrint._precision;
	_dna.resize(bluePrint._dnaSize);

	std::ranges::for_each(_dna, [bluePrint](float& gene) noexcept
	{
		gene = get_random_range_normalized(bluePrint._precision);
	});
}

size_t gaia::NormalizedIndividual::size() noexcept
{
	return _dna.size();
}
 