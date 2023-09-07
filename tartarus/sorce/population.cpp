#include "population.h"

gaia::Population::Population(PopulationBluprint bluePrint): _brain({ bluePrint._nodeSetUp, Negativity::Positive })
{
	std::generate_n(_generation.begin(), bluePrint._size, [&]() {return Individual(bluePrint._nodeSetUp); });
}

gaia::CompleteIndevidual gaia::Population::run_compute(vectorOfFlots fiertInput, PopulationRunOutput run(vectorOfFlots, uint), float evaluate(uint))
{
	vectorOfFlots input = fiertInput;
	bool myContinue;
	for (size_t i = 0; i < _generation.size();)
	{
		vectorOfFlots runOutput = _brain.run_compute(_generation[i].get_DNA(), input);
		auto out = run(runOutput, i);
		input = out._output;
		myContinue = out._continue;

		if (myContinue)
		{
			_generation[i].set_fitness(evaluate(i));
			i++;
		}
	}
    std::sort(_generation.begin(), _generation.end(), [](Individual lh, Individual rh)
    {
        return lh.get_fitness() > rh.get_fitness();
    });
	return { _brain,_generation.at(0) };

    //TODO:test population
}
