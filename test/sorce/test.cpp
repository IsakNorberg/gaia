#include "pch.h"

#include "tartarus.h"
#include <algorithm>
namespace gaia
{
	namespace Bacic
	{ 
		TEST(BasictTests, IncludeCorectly)
		{
			EXPECT_TRUE(test());
		}
	}
	namespace Random////////////////////////////////////////////////
	{
		TEST(GetNormalizedRandom, CantEnterLesThenOne)
		{
			EXPECT_DEATH(get_random_range_normalized(0), "");
		}
		TEST(GetNormalizedRandom, ReturnsSmallerThenOne)
		{
			EXPECT_TRUE(1.1f > get_random_range_normalized(100));
			EXPECT_TRUE(1.1f > get_random_range_normalized(1000));
			EXPECT_TRUE(1.1f > get_random_range_normalized(10000));
			EXPECT_TRUE(1.1f > get_random_range_normalized(1));

		}
		TEST(GetNormalizedRandom, ReturnsBiggerThenMinusOne)
		{
			EXPECT_TRUE(-1.1f < get_random_range_normalized(100));
			EXPECT_TRUE(-1.1f < get_random_range_normalized(1000));
			EXPECT_TRUE(-1.1f < get_random_range_normalized(10000));
			EXPECT_TRUE(-1.1f < get_random_range_normalized(1));

		}
		TEST(GetRandomUnique, TheNumbersAreUniqe)
		{
			int s = 8;
			std::vector<int> vector;
			vector.resize(s);
			std::for_each(vector.begin(), vector.end(), [&](int& num)
			{
				num = get_random_unique(static_cast<int>(vector.size()));
			});
			std::for_each(vector.begin(), vector.end(), [&](int num)
			{
				int once = 0;
				auto it = std::find_if(vector.begin(), vector.end(), [num, &once](int v)
				{
					if (v == num)
					{
						++once;
					}
					return once > 1;
				});
				EXPECT_TRUE(it == vector.end());
			});
		}
	}
	namespace Indevidual//////////////////////////////////////////////////
	{
		TEST(NormalizedIndevidual, SetsUpToCorrectSize)
		{
			NormalizedIndividual dnaTest({ Negativity::NagativAndPositive ,20, 10 });
			EXPECT_EQ(dnaTest.size(), 20);
		}
		TEST(NormalizedIndevidual, SetsUpToCorrectSizePosetiv)
		{
			NormalizedIndividual dnaTest({ Negativity::Positive ,20, 10 });
			EXPECT_EQ(dnaTest.size(), 20);
		}
		TEST(NormalizedIndevidual, HandelZero)
		{
			NormalizedIndividual dnaTest({ Negativity::NagativAndPositive ,0, 0 });
			EXPECT_EQ(dnaTest.size(), 0);
		}
		TEST(NormalizedIndevidual, AllNumbersSetUp)
		{
			NormalizedIndividual dnaTest({ Negativity::NagativAndPositive ,20, 10 });
			std::for_each(dnaTest.begin(), dnaTest.end(), [](float gene)
			{
				EXPECT_TRUE(gene < 1.1f && gene > -1.1f);
			});
		}
		TEST(NormalizedIndevidual, AllNumbersSetUpPosetiv)
		{
			NormalizedIndividual dnaTest({ Negativity::Positive ,20, 10 });
			std::for_each(dnaTest.begin(), dnaTest.end(), [](float gene)
			{
				EXPECT_TRUE(gene < 1.1f && gene >= 0);
			});
		}
		TEST(NormalizedIndevidual, CantAtOutSisdeOfDNASize)
		{
			NormalizedIndividual dnaTest({ Negativity::NagativAndPositive ,20, 100 });
			EXPECT_DEATH(dnaTest.at(20), "");
		}
		TEST(NormalizedIndevidual, CanATSmallerThenDNASIze)
		{
			NormalizedIndividual dnaTest({ Negativity::NagativAndPositive ,20, 100 });
			EXPECT_TRUE(dnaTest.at(3) > -1.1);
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
			std::vector<int> test = { 4,9,3,7,4,5,9,55 };
			
			auto test1 = DynamicIndividualBluePrint(Repeatability::Repeatable, 6, test);
			DynamicIndividual dynamic(test1);
			EXPECT_EQ(6, dynamic.size());
			std::vector<int> test2= { 4,9,3,7,4 };

			auto test3 = DynamicIndividualBluePrint(Repeatability::Repeatable, 5, test2);
			DynamicIndividual dynamic1(test3);
			EXPECT_EQ(5, dynamic1.size());
		}
		TEST(TestDynamicIndividual, IsCorrectValue)
		{
			std::vector<int> test = { 4,9,3,7,4 };
			auto test1 = DynamicIndividualBluePrint<int>(Repeatability::Repeatable, 5, test);
			DynamicIndividual dynamic(test1);
			
			EXPECT_TRUE(dynamic.at(2)> 2);
		}
		TEST(TestDynamicIndividual, CantAtBigerThenDNASize)
		{
			std::vector<int> test = { 4,9,3,7,4 };
			auto test1 = DynamicIndividualBluePrint(Repeatability::Repeatable, 5, test);
			DynamicIndividual dynamic(test1);
			EXPECT_DEATH(dynamic.at(5),"");
		}
		TEST(TestDynamicIndividual, AlNumbersAreSetUp)
		{
			std::vector<int> test = { 4,9,3,7,4,7,5 };
			auto test1 = DynamicIndividualBluePrint(Repeatability::Repeatable, 5, test);
			DynamicIndividual dynamic(test1);
			std::for_each(dynamic.begin(), dynamic.end(), [&](auto gene)
			{
				EXPECT_TRUE(gene > 2);
				EXPECT_TRUE(gene < 10);
				EXPECT_TRUE(gene < 100);
			});
		}
		TEST(TestDynamicIndividual, UniqeDNAAllNumbersSetUP)
		{
			std::vector<int> test = { 1,2,-5,0,4,11,9,14 };
			auto test1 = DynamicIndividualBluePrint(Repeatability::Unique, 8, test);
			DynamicIndividual dynamic(test1);
			std::for_each(dynamic.begin(), dynamic.end(), [&](auto gene)
			{
				EXPECT_TRUE(gene > -6);
				EXPECT_TRUE(gene < 15);
			});
		}
		TEST(TestDynamicIndividual, UniqeDNAHandelZero)
		{
			std::vector<int> test = { 1,2,-5,0,4,11,9,14 };
			auto test1 = DynamicIndividualBluePrint(Repeatability::Unique, 0, test);
			DynamicIndividual dynamic(test1);
			std::for_each(dynamic.begin(), dynamic.end(), [&](auto gene)
			{
				EXPECT_TRUE(gene > -6);
				EXPECT_TRUE(gene < 15);
			});
		}
	}
	namespace Brain /////////////////////////////////////////////////////////////
	{
		TEST(BrinStruct, AssurtIfSomeValuseAre0)
		{
			EXPECT_DEATH(gaia::NodeSetUp({ 0,0,0,1 }), "");
			EXPECT_DEATH(gaia::NodeSetUp({ 1,0,0,1 }), "");
			EXPECT_DEATH(gaia::NodeSetUp({ 1,1,0,1 }), "");
			EXPECT_DEATH(gaia::NodeSetUp({ 1,0,1,1 }), "");
			EXPECT_DEATH(gaia::NodeSetUp({ 0,0,1,1 }), "");
			EXPECT_DEATH(gaia::NodeSetUp({ 0,1,0,0 }), "");
		}
		TEST(BrinStruct, DontAssurtOnATotelyEmty)
		{
			gaia::NodeSetUp n({ 0,0,0,0 });
			EXPECT_TRUE(true);
		}
	}
}