#include "pch.h"

#include <type_traits>

#include "tartarus.h"
namespace gaia
{
	namespace Bacic
	{ 
		TEST(BasictTests, IncludeCorectly)
		{
			EXPECT_TRUE(test());
		}
	}
	namespace Random
	{
		TEST(GetNormalizedRandom, CantEnterLesThenOne)
		{
			EXPECT_DEATH(get_random_range_normalized(0), "");
		}
		TEST(GetNormalizedRandom, ReturnsSmallerThenOne)
		{
			EXPECT_TRUE(1.0f > get_random_range_normalized(100));
			EXPECT_TRUE(1.0f > get_random_range_normalized(1000));
			EXPECT_TRUE(1.0f > get_random_range_normalized(10000));
			EXPECT_TRUE(1.1f > get_random_range_normalized(1));

		}
		TEST(GetNormalizedRandom, ReturnsBiggerThenMinusOne)
		{
			EXPECT_TRUE(-1.0f < get_random_range_normalized(100));
			EXPECT_TRUE(-1.0f < get_random_range_normalized(1000));
			EXPECT_TRUE(-1.0f < get_random_range_normalized(10000));
			EXPECT_TRUE(-1.1f < get_random_range_normalized(1));

		}
	}
	namespace Indevidual
	{
		TEST(NormalizedIndevidual, SetsUpToCorrectSize)
		{
			NormalizedIndividual dnaTest({ Negativity::NagativAndPositive ,20, 10 });
			EXPECT_EQ(dnaTest.size(), 20);
		}
		TEST(NormalizedIndevidual, AllNumbersSetUp)
		{
			NormalizedIndividual dnaTest({ Negativity::NagativAndPositive ,20, 10 });
			std::for_each(dnaTest.begin(), dnaTest.end(), [](float gene)
			{
				EXPECT_TRUE(gene < 1.1f && gene > -1.1f);
			});
		}
		TEST(TestDynamicIndividualBluePrint, CantMakeUtilizationBiggerThenCompletSetIfUnique)
		{
			std::vector<int> test = { 4,9,3,7 };
			EXPECT_DEATH(DynamicIndividualBluePrint(Repeatability::Unique, 5, test), "");
			EXPECT_DEATH(DynamicIndividualBluePrint(Repeatability::Unique, 100, test), "");
		}
		
		TEST(TestDynamicIndividualBluePrint, CanMakeUtilizationBiggerThenCompletSetRepeatable)
		{
			std::vector<int> test = { 4,9,3,7 };
			auto test1 = DynamicIndividualBluePrint(Repeatability::Repeatable, 5, test);
			
			EXPECT_TRUE(test1._completSet.size() == test.size());
		}
		TEST(TestDynamicIndividual, TheSizeIsCorrect)
		{
			std::vector<int> test = { 4,9,3,7,4 };
			 
			auto test1 = DynamicIndividualBluePrint(Repeatability::Repeatable, 5, test);
			DynamicIndividual dynamic(test1);
			EXPECT_EQ(test.size(), dynamic.size());
		}
		TEST(TestDynamicIndividual, IsCorrectValue)
		{
			std::vector<int> test = { 4,9,3,7,4 };
			auto test1 = DynamicIndividualBluePrint<int>(Repeatability::Repeatable, 5, test);
			DynamicIndividual<int> dynamic(test1);
			
			EXPECT_TRUE(dynamic.at(2)> 3);
		}
		TEST(TestDynamicIndividual, CantAtBigerThenDNASize)
		{
			std::vector<int> test = { 4,9,3,7,4 };
			auto test1 = DynamicIndividualBluePrint<int>(Repeatability::Repeatable, 5, test);
			DynamicIndividual<int> dynamic(test1);
			EXPECT_DEATH(dynamic.at(5),"");
		}
	}
}