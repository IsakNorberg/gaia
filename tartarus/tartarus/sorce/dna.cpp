#include "dna.h"

gaia::Dna::Dna(BluePrint bluePrint)
{
	_precision = bluePrint._precision;
	_data.resize(bluePrint._dnaSize);
}
