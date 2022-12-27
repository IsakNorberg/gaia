#pragma once

#include <vector>
#include <ranges>
#include <algorithm>
#include <assert.h>
#include <any>

#include "random.h"


namespace gaia
{
	enum class Repeatability
	{
		Unique,
		Repeatable
	};

	//Use to create a DynamicDna, utilization is the amount of the gens that have to be in the dna 
	struct DynamicIndividualBluePrint
	{
		Repeatability _attribute;
		unsigned int _utilization;
		std::vector<std::any> _completSet;
		DynamicIndividualBluePrint(Repeatability attribute, unsigned int utilization, std::vector<std::any> completSet);
	};

	//Genes that can be anything in any range
	class DynamicIndividual
	{

		std::vector<std::any> _dna;
	public:
		DynamicIndividual(DynamicIndividualBluePrint bluePrint);
	};
}