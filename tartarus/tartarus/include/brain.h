#pragma once

#include "random.h"

namespace gaia
{
	struct NodeSetUp
	{
		NodeSetUp(unsigned int inputNodeAmount, unsigned int hiddenNodeAmountPerLayers, unsigned int hiddenNodeLayers, unsigned int outputNodeAmount) noexcept;
		unsigned int _inputNodeAmount{ 0 };
		unsigned int _hiddenNodeAmountPerLayers{ 0 };
		unsigned int _hiddenNodeLayers{ 0 };
		unsigned int _outputNodeAmount{ 0 };
	private:
		void correct_set_up_check(unsigned int inputNodeAmount, unsigned int hiddenNodeAmountPerLayers, unsigned int hiddenNodeLayers, unsigned int outputNodeAmount) noexcept;
	};
	enum class Negativity
	{
		NagativAndPositive,
		Positive
	};
	// blue print 
	// inpot nodes per layer
	// lyers 
	// outpost nods 
	// Noramazed indevidual Bluprint 

	class Brain //TODO: implemt and list ut hur konac tions väljsa 
	{
		// tack blue orint in constructor 
		// mby normalezed indevidual  
		// vecrtor of vector of lots
		// vector<flot> outpuit 
		// or unsind int as a index as put pot as the bigest valu 
	};

}