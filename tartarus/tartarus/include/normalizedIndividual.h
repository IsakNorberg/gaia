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
		Positive
	};

	//Use to create a Dna
	struct NormalizedIndividualBluePrint
	{
		Negativity _attribute;
		unsigned int _dnaSize;
		unsigned int _precision;
	};
	//Genes that are normalized
	class NormalizedIndividual
	{
		int _precision;

		vectorOfFlots _dna;
	public:
		NormalizedIndividual(NormalizedIndividualBluePrint bluePrint);
		size_t size() noexcept;
		float at(unsigned int index);
		vectorOfFlots::iterator begin()noexcept;
		vectorOfFlots::iterator end()noexcept;
	};
}


