#pragma once

#include <vector>
#include <ranges>
#include <algorithm>
#include <assert.h>
#include <memory>

#include "random.h"



namespace gaia
{
	enum class Repeatability
	{
		Unique,
		Repeatable
	};

	//Use to create a DynamicDna, utilization is the amount of the gens that have to be in the dna 
	template <typename DNAType>
	struct DynamicIndividualBluePrint
	{
		Repeatability _attribute;
		unsigned int _utilization;
		std::vector<DNAType> _completSet;
		DynamicIndividualBluePrint(Repeatability attribute, unsigned int utilization, std::vector<DNAType> completSet);
	};

	template <typename DNAType>
	gaia::DynamicIndividualBluePrint<DNAType>::DynamicIndividualBluePrint(Repeatability attribute,
																		  unsigned int utilization,
																		  std::vector<DNAType> completSet) : _attribute(attribute), _utilization(utilization), _completSet(completSet)
	{
		if (_attribute == Repeatability::Unique)
		{
			assert(_completSet.size() >= _utilization);
		}
	}


	//Genes that can be anything in any range
	template <typename DNAType>
	class DynamicIndividual
	{	
		std::vector<DNAType> _dna;
	public:

		DynamicIndividual(DynamicIndividualBluePrint<DNAType> bluePrint);
		size_t size() noexcept;
		
		DNAType at(unsigned int index);

	    std::vector<DNAType>::iterator begin()  noexcept;
		std::vector<DNAType>::iterator end() noexcept;
	};

	template<typename DNAType>
	gaia::DynamicIndividual<DNAType>::DynamicIndividual(DynamicIndividualBluePrint<DNAType> bluePrint)
	{
		_dna.resize(bluePrint._utilization);
		const unsigned int utilization = bluePrint._utilization;
		std::vector<DNAType> completSet = bluePrint._completSet;
		std::ranges::for_each(_dna, [&](auto& gene)
		{
			gene = completSet.at(get_Random(bluePrint._attribute,utilization));
		});

	}
	template<typename DNAType>
	size_t gaia::DynamicIndividual<DNAType>::size() noexcept
	{
		return _dna.size();
	}

	template<typename DNAType>
	DNAType gaia::DynamicIndividual<DNAType>::at(unsigned int index)
	{
		assert(_dna.size() > index);
		return  _dna.at(index);
	}

	template<typename DNAType>
	inline std::vector<DNAType>::iterator DynamicIndividual<DNAType>::begin() noexcept
	{
		return _dna.begin();
	}

	template<typename DNAType>
	inline  std::vector<DNAType>::iterator DynamicIndividual<DNAType>::end() noexcept
	{
		return _dna.end();
	}

	int get_Random(Repeatability attribute, unsigned int utilization);
}