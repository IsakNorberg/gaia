#include "Individual.h"

//make new konstructer
gaia::Individual::Individual(NodeSetUp nodeSetUp)
{
	_dna = add_node_dna(_dna, nodeSetUp);
}


size_t gaia::Individual::size()const noexcept 
{
	return _dna.size();
}

float gaia::Individual::at(uint index)
{
	assert(_dna.size() > index);
	return _dna.at(index);
}

vectorOfBools gaia::Individual::get_DNA() const noexcept
{
	return _dna;
}

vectorOfBools::iterator gaia::Individual::begin() noexcept
{
	return _dna.begin();
}

vectorOfBools::iterator gaia::Individual::end() noexcept
{
	return _dna.end();
}

float gaia::Individual::get_fitness() const noexcept
{
	return _fitness;
}

void gaia::Individual::set_fitness(float fitness) noexcept
{
	_fitness = fitness;
}




vectorOfBools gaia::add_node_dna(vectorOfBools dna, NodeSetUp nodeSetUp)
{
	const int hiddenPerLayers = nodeSetUp._hiddenNodeBreadth;
	const int dnaSize = nodeSetUp._inputNodeAmount * hiddenPerLayers +
		hiddenPerLayers * hiddenPerLayers * (nodeSetUp._hiddenNodeLayers - 1) +
		nodeSetUp._outputNodeAmount * hiddenPerLayers;
	dna.resize(dnaSize);
(	std::ranges::generate(dna, [] {return get_random_bool(); });
	return dna;
}


