#pragma once
#include "setings.h"

namespace gaia
{
	
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
	}; 
	
	
	class Population //TODO: implament
	{
		//genaration 
		

	public:
		//Population(); //take blue print 
		//at brain
		// end och begin 
	};
}
