#pragma once
#include <vector>
#include <algorithm>
#include <ranges>

#include "random.h"
using  vectorOfFlots = std::vector<float>;

namespace gaia
{
	//Use to create a Dna
	struct DanBluePrint
	{
		unsigned int _dnaSize;
		unsigned int _precision;
	};
	//Genes from -1 to 1
	class Dna
	{
		int _precision;

		vectorOfFlots _data;
	public:
		Dna(DanBluePrint bluePrint);
		size_t size() noexcept;
	};
}


