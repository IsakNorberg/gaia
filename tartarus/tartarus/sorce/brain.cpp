#include "brain.h"

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


gaia::NodeSetUp::NodeSetUp(unsigned int inputNodeAmount,
						   unsigned int hiddenNodeAmountPerLayers,
						   unsigned int hiddenNodeLayers,
						   unsigned int outputNodeAmount) noexcept
	:_inputNodeAmount{ inputNodeAmount },
	_hiddenNodeAmountPerLayers{ hiddenNodeAmountPerLayers },
	_hiddenNodeLayers{ hiddenNodeLayers },
	_outputNodeAmount{ outputNodeAmount }
{
	correct_set_up_check(inputNodeAmount, hiddenNodeAmountPerLayers, hiddenNodeLayers, outputNodeAmount);
}

void gaia::NodeSetUp::correct_set_up_check(unsigned int inputNodeAmount, unsigned int hiddenNodeAmountPerLayers, unsigned int hiddenNodeLayers, unsigned int outputNodeAmount) noexcept
{

	if (0 == inputNodeAmount +
		hiddenNodeLayers +
		hiddenNodeAmountPerLayers +
		outputNodeAmount)
	{
		assert(!"set up is empty");
	}
	if (inputNodeAmount == 0 ||
		hiddenNodeAmountPerLayers == 0 ||
		hiddenNodeLayers == 0 ||
		outputNodeAmount == 0)
	{
		assert(!"no variable can be zero");
	}
}

gaia::Brain::Brain(gaia::BrainBluePrint bluePrint) noexcept:_setUp(bluePrint._setUp), _attribute(bluePrint._attribute)
{

}

gaia::NodeSetUp gaia::Brain::get_node_set_up()const noexcept
{
	return _setUp;
}

std::vector<float> gaia::Brain::compute(std::vector<bool>)
{
	return std::vector<float>();
}
