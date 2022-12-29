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

float gaia::NormalizedIndividual::at(unsigned int index)
{
	assert(_dna.size() > index);
	return _dna.at(index);
}

vectorOfFlots::iterator gaia::NormalizedIndividual::begin() noexcept
{
	return _dna.begin();
}

vectorOfFlots::iterator gaia::NormalizedIndividual::end() noexcept
{
	return _dna.end();
}


 