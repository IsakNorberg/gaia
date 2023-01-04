#include "normalizedIndividual.h"

namespace
{
	inline float random(unsigned int precition, gaia::Negativity atribute) noexcept
	{
		if (atribute == gaia::Negativity::NagativAndPositive)
		{
			return  gaia::get_random_range_normalized(precition);
		}
		else if (atribute == gaia::Negativity::Positive)
		{
			return  gaia::get_random_range_normalized_posetiv(precition);
		}
		assert(!"");
		return .0f;
	}
}
gaia::NormalizedIndividual::NormalizedIndividual(NormalizedIndividualBluePrint bluePrint, NodeSetUp nodeSetUp)
{
	initialize(bluePrint, nodeSetUp);
}

gaia::NormalizedIndividual::NormalizedIndividual(NormalizedIndividualBluePrint bluePrint)
{
	initialize(bluePrint, {0,0,0,0});
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

void gaia::NormalizedIndividual::initialize(NormalizedIndividualBluePrint bluePrint, NodeSetUp nodeSetUp)
{
	_precision = bluePrint._precision;
	_dna.resize(bluePrint._dnaSize);

	std::ranges::for_each(_dna, [bluePrint](float& gene) noexcept
	{
		gene = random(bluePrint._precision, bluePrint._attribute);
	});
	_dna = add_node_dna_to_end(_dna, nodeSetUp);
}

gaia::NodeSetUp::NodeSetUp(unsigned int inputNodeAmount,
						   unsigned int hiddenNodeAmountPerLayers,
						   unsigned int hiddenNodeLayers,
						   unsigned int outputNodeAmount) noexcept
	:_inputNodeAmount{ inputNodeAmount },
	_hiddenNodeAmountPerLayers{ hiddenNodeAmountPerLayers },
	_hiddenNodeLayers{ hiddenNodeLayers },
	_outputNodeAmount{ outputNodeAmount }
{

	if (0 == inputNodeAmount + 
			 hiddenNodeLayers + 
			 hiddenNodeAmountPerLayers +		
			 outputNodeAmount)
	{
		return;
	}
	if (inputNodeAmount == 0 ||
		hiddenNodeAmountPerLayers == 0 ||
		hiddenNodeLayers == 0 ||
		outputNodeAmount == 0)
	{
		assert(!"no variable can be zero");
	}
}

vectorOfFlots gaia::add_node_dna_to_end(vectorOfFlots dna, NodeSetUp nodeSetUp)
{
	if (0 == nodeSetUp._hiddenNodeAmountPerLayers + 
		     nodeSetUp._hiddenNodeLayers + 
			 nodeSetUp._inputNodeAmount + 
			 nodeSetUp._outputNodeAmount)
	{
		return dna;
	}
	// TODO: to the ading of the niber in the rhite rande herare
	return vectorOfFlots();
}
