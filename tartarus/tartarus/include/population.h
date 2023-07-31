#pragma once
#include "setings.h"
#include "Individual.h"

#include <ranges>
#include <vector>

namespace gaia
{
	using vectorOfIndeviduals = std::vector<gaia::Individual>;
	enum class Reproduction
	{
		RandomMutation,
		Mating
	};

	struct PopulationBluprint
	{
		double _survivorRatio;
		uint _size;
		Reproduction _attribute;
		NodeSetUp _nodeSetUp;
	}; 
	
	
	class Population //TODO: implament
	{
		vectorOfIndeviduals _generation;
		Brain _brain;
	public:
		Population(PopulationBluprint bluePrint); 
		//run_cumpute pre indevidual till one predicet is dune then set fitnes unig a other predicet
		// then ovelode one that is the same but only a predicet for setting fitnses and uses the first one but 
		// the first predicet is set to return true	so it only runs once	
		// and return the best indevidual after being done
		// mby add seed to start whit added indeviduals 
		// todo: purge and mate probly privet functions 

	};
}
