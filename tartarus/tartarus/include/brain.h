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
	struct BrainBluePrint
	{
		NodeSetUp _setUp;
		Negativity _attribute;
	};


	class Brain //TODO: implemt and list ut hur konac tions väljsa 
	{
		NodeSetUp _setUp;
		Negativity _attribute;
	public:
		Brain(BrainBluePrint bluePrint) noexcept;
		NodeSetUp get_node_set_up()const noexcept;
		//takes a vector of normalized floats == to inpot nodes
		void input(std::vector<float> input); // maby make a input class 
		std::vector<float> compute(std::vector<bool> DNA) const noexcept;
		float compute_trigger_value(std::vector<bool> DNA) const noexcept ;
		// tack blue orint in constructor 
		// mby normalezed indevidual  
		// vecrtor of vector of lots
		// vector<flot> outpuit 
		// or unsind int as a index as put pot as the bigest valu 
	};

}