#pragma once
#include <vector>
#include <algorithm>
#include <ranges>

#include "brain.h"
#include "random.h"
using  vectorOfBools = std::vector<bool>;

namespace gaia
{
	class Individual
	{	
		float _fitness{0};
		vectorOfBools _dna;
	public:
	
		Individual(NodeSetUp nodeSetUp);
		size_t size()noexcept;
		float at(unsigned int index);
		
		vectorOfBools::iterator begin()noexcept;
		vectorOfBools::iterator end()noexcept;
		float get_fitness() const noexcept;
		void set_fitness(float fitness) noexcept;
	};
	vectorOfBools add_node_dna(vectorOfBools dna, NodeSetUp nodeSetUp);
	namespace
	{
		inline void zero_check(NodeSetUp nodeSetUp) noexcept
		{
			if (0 == nodeSetUp._hiddenNodeAmountPerLayers +
				nodeSetUp._hiddenNodeLayers +
				nodeSetUp._inputNodeAmount +
				nodeSetUp._outputNodeAmount)
			{
				assert(!"set up is empty");
			}
		}
	}
}


