#pragma once

#include <vector>
#include <ranges>
#include <algorithm>
#include <assert.h>
#include <typeinfo>

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
		DNAType type();
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

	template<typename DNAType>
	inline DNAType DynamicIndividualBluePrint<DNAType>::type() 
	{
		return DNAType;
	}

	//Genes that can be anything in any range
	template <typename DNAType, typename BluePrint = DynamicIndividualBluePrint<DNAType>>
	class DynamicIndividual
	{
		std::vector<DNAType> _dna;
	public:

		DynamicIndividual(BluePrint bluePrint);
		size_t size() noexcept;
		
		DNAType at(unsigned int index);
		std::vector<DNAType>::iterator begin()noexcept;
		std::vector<DNAType>::iterator end()noexcept;
	};

	template<typename DNAType, typename BluePrint>
	gaia::DynamicIndividual<DNAType, BluePrint>::DynamicIndividual(BluePrint bluePrint)
	{
		_dna.resize(bluePrint._utilization);
		const unsigned int utilization = bluePrint._utilization;
		std::vector<DNAType> completSet = bluePrint._completSet;
		if (bluePrint._attribute == Repeatability::Repeatable)
		{
			std::ranges::for_each(_dna, [&](auto& gene)
			{
				gene = completSet.at(get_random_repeatable(utilization));
			});
		}
		else if (bluePrint._attribute == Repeatability::Unique)
		{
			std::ranges::for_each(_dna, [&](auto& gene)
			{
				gene = completSet.at(get_random_unique(utilization));
			});
		}
	}
	template<typename DNAType, typename BluePrint>
	size_t gaia::DynamicIndividual<DNAType, BluePrint>::size() noexcept
	{
		return _dna.size();
	}

	template<typename DNAType, typename BluePrint>
	DNAType gaia::DynamicIndividual<DNAType, BluePrint>::at(unsigned int index)
	{
		assert(_dna.size() > index);
		return  _dna.at(index);
	}

	template<typename DNAType, typename BluePrint>
	inline std::vector<DNAType>::iterator DynamicIndividual<DNAType, BluePrint>::begin() noexcept
	{
		return _dna.begin();
	}

	template<typename DNAType, typename BluePrint>
	inline std::vector<DNAType>::iterator DynamicIndividual<DNAType, BluePrint>::end() noexcept
	{
		return _dna.end();
	}
	
}