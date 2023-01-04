#pragma once
#include <vector>
#include <algorithm>
#include <ranges>

#include "random.h"
using  vectorOfFlots = std::vector<float>;

namespace gaia
{
	

	enum class Negativity
	{
		NagativAndPositive,
		Positive 
	};
	
	struct NodeSetUp
	{
		NodeSetUp(unsigned int inputNodeAmount, unsigned int hiddenNodeAmountPerLayers, unsigned int hiddenNodeLayers, unsigned int outputNodeAmount) noexcept;
		unsigned int _inputNodeAmount{0};
		unsigned int _hiddenNodeAmountPerLayers{0};
		unsigned int _hiddenNodeLayers{0};
		unsigned int _outputNodeAmount{0};
	};
	//Use to create a Dna
	struct NormalizedIndividualBluePrint
	{
		Negativity _attribute;
		unsigned int _dnaSize;
		unsigned int _precision;
	};
	//TODO: Only Made In Braine

	//Genes that are normalized
	class NormalizedIndividual
	{
		int _precision{0};
		float _fitness{0};
		vectorOfFlots _dna;
		void initialize(NormalizedIndividualBluePrint bluePrint, NodeSetUp nodeSetUp);
		//Vector of intes set pu TODO: is the brain conactoons 
	public:
	
		NormalizedIndividual(NormalizedIndividualBluePrint bluePrint, NodeSetUp nodeSetUp);
		NormalizedIndividual(NormalizedIndividualBluePrint bluePrint);
		size_t size()noexcept;
		float at(unsigned int index);
		
		vectorOfFlots::iterator begin()noexcept;
		vectorOfFlots::iterator end()noexcept;
		float get_fitness() const noexcept;
		void set_fitness(float fitness) noexcept;
	};
	vectorOfFlots add_node_dna_to_end(vectorOfFlots dna, NodeSetUp nodeSetUp);
}


