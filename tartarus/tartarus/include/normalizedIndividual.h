#pragma once
#include <vector>
#include <algorithm>
#include <ranges>

#include "random.h"
using  vectorOfFlots = std::vector<float>;

namespace gaia
{
	enum class Negativity // implematera
	{
		NagativAndPositive,
		Positive  //TODO: make so this woarks
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
		int _precision;
		float _fitness; //TODO: get end set
		vectorOfFlots _dna;
		//Vector of intes set pu TODO: is the brain conactoons 
	public:
		NormalizedIndividual(NormalizedIndividualBluePrint bluePrint);
		size_t size()noexcept;
		float at(unsigned int index);
		
		vectorOfFlots::iterator begin()noexcept;
		vectorOfFlots::iterator end()noexcept;
		
	};
}


