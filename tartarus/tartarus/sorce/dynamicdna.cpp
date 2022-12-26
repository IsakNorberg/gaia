#include "dynamicdna.h"

gaia::DynamicDnaBluePrint::DynamicDnaBluePrint(unsigned int dnaSize, unsigned int utilization, std::vector<std::any> completSet) noexcept 
	: _dnaSize(dnaSize), _utilization(utilization), _completSet(completSet)
{
	assert(_dnaSize <= _utilization);
}

gaia::DynamicDna::DynamicDna(DynamicDnaBluePrint bluePrint)
{
	
}
