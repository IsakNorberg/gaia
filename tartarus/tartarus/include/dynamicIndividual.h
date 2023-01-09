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
		int get_random(Repeatability attribute, unsigned int utilization);
		std::vector<DNAType> _dna;
		float _fitness{0};
	public:

		DynamicIndividual(DynamicIndividualBluePrint<DNAType> bluePrint);
		size_t size() noexcept;
		
		DNAType at(unsigned int index);

		float get_fitness() const noexcept;
		void set_fitness(float fitness)noexcept;

	    std::vector<DNAType>::iterator begin()  noexcept;
		std::vector<DNAType>::iterator end() noexcept;
	};


	template<typename DNAType>
	int DynamicIndividual<DNAType>::get_random(Repeatability attribute, unsigned int utilization)
	{
		if (attribute == Repeatability::Unique)
		{
			return  gaia::get_random_range_unique(utilization);
		}
		else if (attribute == Repeatability::Repeatable)
		{
			return gaia::get_random_repeatable(utilization);
		}
		assert(!"No Repeatability with that Attribute");
		return 0;
	}

	template<typename DNAType>
	gaia::DynamicIndividual<DNAType>::DynamicIndividual(DynamicIndividualBluePrint<DNAType> bluePrint)
	{
		_dna.resize(bluePrint._utilization);
		std::vector<DNAType> completSet = bluePrint._completSet;
		if (bluePrint._attribute == Repeatability::Repeatable)
		{
			std::ranges::generate(_dna, [&] {return completSet.at(get_random_repeatable(bluePrint._utilization)); });
		}
		else if (bluePrint._attribute == Repeatability::Unique)
		{
			_dna = get_random_range_unique(bluePrint._utilization, completSet);
		}
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
	inline float DynamicIndividual<DNAType>::get_fitness() const noexcept
	{
		return _fitness;
	}

	template<typename DNAType>
	inline void DynamicIndividual<DNAType>::set_fitness(float fitness) noexcept
	{
		_fitness = fitness;
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

	

}