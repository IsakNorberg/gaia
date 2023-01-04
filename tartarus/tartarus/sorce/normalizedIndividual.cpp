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
	NodeSetUp n = nodeSetUp; // ta bort ville bra kunna bugga 
	// kolla node set upp bär brain
	// set upp fö resten av dna för hjärnan
}

gaia::NodeSetUp::NodeSetUp(unsigned int inputNodeAmount,
						   unsigned int hiddenNodeAmountPerLayers,
						   unsigned int hiddenNodeLayers,
						   unsigned int outputNodeAmount)
	:_inputNodeAmount{ inputNodeAmount },
	_hiddenNodeAmountPerLayers{ hiddenNodeAmountPerLayers },
	_hiddenNodeLayers{ hiddenNodeLayers },
	_outputNodeAmount{ outputNodeAmount }
{
	int sentanal = inputNodeAmount + hiddenNodeLayers + hiddenNodeAmountPerLayers + outputNodeAmount;
	if (sentanal == 0)
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
