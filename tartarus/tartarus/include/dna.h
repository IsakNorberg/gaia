#pragma once
#include <vector>

using  vectorOfFlots = std::vector<float>;

namespace gaia
{
	//Use to create a Dna
	struct BluePrint
	{
		int _dnaSize;
		int _precision;
	};

	class Dna
	{
		int _precision;

		vectorOfFlots _data;
	public:
		Dna(BluePrint bluePrint);
	};
}


