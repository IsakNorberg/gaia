#pragma once
#include <assert.h>
#include <time.h>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <random>

static bool TEST = false;

namespace gaia
{
	//normalized
	//Get a random float between -1 and 1 with a given precision
	float get_random_range_normalized(unsigned  int precision) noexcept;
	unsigned int get_random_repeatable(unsigned int range) noexcept;
	//cant work whit the TEST
	template <typename type>
	std::vector<type> get_random_range_unique(unsigned int utilization, std::vector<type> completSet);
	float get_random_range_normalized_posetiv(unsigned  int precision) noexcept;
	bool get_random_bool() noexcept;
	void set_random_to_test(bool test) noexcept;

	template<typename type>
	std::vector<type> get_random_range_unique(unsigned int utilization, std::vector<type> completSet)
	{
		static std::random_device rd;
		static std::mt19937 g(rd());

		std::shuffle(completSet.begin(), completSet.end(), g);
		completSet.resize(utilization);
		return completSet;
	}
}