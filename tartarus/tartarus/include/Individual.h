#pragma once
#include <vector>
#include <algorithm>
#include <ranges>

#include "brain.h"
#include "random.h"
using  vectorOfBools = vectorOfBools;

namespace gaia
{
	class Individual
	{	
		float _fitness{0};
		vectorOfBools _dna;
	public:
		Individual(NodeSetUp nodeSetUp)  noexcept;
		[[nodiscard]] size_t size()const noexcept;
		float at(uint index);
		
		vectorOfBools::iterator begin()noexcept;
		vectorOfBools::iterator end()noexcept;
		[[nodiscard]] float get_fitness() const noexcept;
		void set_fitness(float fitness) noexcept;
	};
	vectorOfBools add_node_dna(vectorOfBools dna, NodeSetUp nodeSetUp);
	
}


