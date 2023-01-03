#include "normalizedIndividual.h"

gaia::NormalizedIndividual::NormalizedIndividual(NormalizedIndividualBluePrint bluePrint, NodeSetUp nodeSetUp)
{
	_precision = bluePrint._precision;
	_dna.resize(bluePrint._dnaSize);

	std::ranges::for_each(_dna, [bluePrint](float& gene) noexcept
	{
		gene = random(bluePrint._precision, bluePrint._attribute);
	});
	NodeSetUp n = nodeSetUp; // ta bort ville bra kunna bugga 
	// kolla node set upp b�r brain
	// set upp f� resten av dna f�r hj�rnan
	// och skrive n�gra test f�r postivt dna och get och set
}

gaia::NormalizedIndividual::NormalizedIndividual(NormalizedIndividualBluePrint bluePrint)
{
	NormalizedIndividual(bluePrint, {});
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

float gaia::NormalizedIndividual::get_fitness() const noexcept
{
	return _fitness;
}

void gaia::NormalizedIndividual::set_fitness(float fitness) noexcept
{
	_fitness = fitness;
}

 