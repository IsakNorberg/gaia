#include "dna.h"

gaia::Dna::Dna(DanBluePrint bluePrint)
{
	_precision = bluePrint._precision;
	_data.resize(bluePrint._dnaSize);

	std::ranges::for_each(_data, [bluePrint](float& gene) noexcept
	{
		gene = get_Random_Range_Normalized(bluePrint._precision);
	});
}

size_t gaia::Dna::size() noexcept
{
	return _data.size();
}
 