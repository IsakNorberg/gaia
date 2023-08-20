#include "population.h"

gaia::Population::Population(PopulationBluprint bluePrint): _brain({ bluePrint._nodeSetUp, Negativity::Positive })
{
	std::generate_n(_generation.begin(), bluePrint._size, [&]() {return Individual(bluePrint._nodeSetUp); });
}

gaia::CompleteIndevidual gaia::Population::run_compute(vectorOfFlots firtInput, PopulationRunOutput run(vectorOfFlots), float evaluate())
{
	vectorOfFlots input = firtInput;
	bool myContinue;
	for (size_t i = 0; i < _generation.size();)
	{
		vectorOfFlots runOutput = _brain.run_compute(_generation[i].get_DNA(), input);
		auto out = run(runOutput);
		input = out._output;
		myContinue = out._continue;

		if (myContinue)
		{
			_generation[i].set_fitness(evaluate());
			i++;
		}
	}
	// todo set fitnes tex sätter fösta input sen storar vad resultatet blir av förta inbut och evaluate callar de värdet
	//test
	return { _brain,_generation.at(0) };
}
