#pragma once

#include <vector>
#include <assert.h>
#include <any>


namespace gaia
{
	//Use to create a DynamicDna, utilization is the amount of the gens that have to be in a dna 
	struct DynamicDnaBluePrint
	{
		unsigned int _dnaSize;
		unsigned int _utilization;
		std::vector<std::any> _completSet;
		DynamicDnaBluePrint(unsigned int dnaSize, unsigned int utilization, std::vector<std::any> completSet) noexcept;
	};

	//Genes that can be anything in any range
	class DynamicDna
	{

		std::vector<std::any> _data;
	public:
		DynamicDna(DynamicDnaBluePrint bluePrint);
	};
}