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
		class TestRandomObject
		{
		public:
			TestRandomObject()
			{
				set_random_to_test(true);
			}
			~TestRandomObject()
			{
				set_random_to_test(false);
			}
		};
		TEST(RandomTest, TheRadomTestWoarks)
		{ 
			TestRandomObject t;
			std::vector<int> a;
			std::vector<int> b;
			a.resize(10);
			b.resize(10);
			std::ranges::generate(a, [] { return get_random_repeatable(100);});
			std::ranges::generate(b, [] { return get_random_repeatable(100); });
			EXPECT_EQ(a, b);
		
		}

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
			std::vector<int> vector = { 2,5,1,8,9,3,4,99,7,88 };
			vector = get_random_range_unique<int>(s,vector);
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

			int s2 = 10;
			std::vector<int> vector2 = { 33,2,5,4,77,6,4,72,99,9,78,24,11 };
			vector2 = get_random_range_unique<int>(s2, vector2);

			std::for_each(vector2.begin(), vector2.end(), [&](int num)
			{
				int once = 0;
				auto it = std::find_if(vector2.begin(), vector2.end(), [num, &once](int v)
			{
				if (v == num)
				{
					++once;
				}
				return once > 1;
			});
				EXPECT_TRUE(it == vector2.end());
			});
		}
		TEST(GetRandomBool, IsRandom)
		{
			vectorOfBools a;
			vectorOfBools b;
			a.resize(1000);
			b.resize(1000);
			std::ranges::generate(a, []{ return get_random_bool();});
			std::ranges::generate(b, [] { return get_random_bool(); });

			EXPECT_FALSE(a == b);
		}
	}
	namespace TestIndevidual//////////////////////////////////////////////////
	{
		//TODO::re write test fore indevidual
		TEST(TestForIndevidual, IsSetUpCorrectSize)
		{
			Individual i({ 3,5,5,4 });
			EXPECT_EQ(i.size(), 135);
		}
		TEST(TestForIndevidual, IsSetUpCorrectAt)
		{
			Individual i({ 3,5,5,4 });
			i.at(0);
			i.at(2);
			i.at(134);
			i.at(1);
			EXPECT_EQ(i.size(), 135);
		}
		TEST(TestForIndevidual, IsSetUpCorrectValus)
		{
			Random::TestRandomObject t;
			Individual i({ 3,5,5,4 });

			EXPECT_EQ(i.at(0), true);
			EXPECT_EQ(i.at(1), false);
			EXPECT_EQ(i.at(10), true);
			EXPECT_EQ(i.at(20), true);
			
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
	namespace TestBrain /////////////////////////////////////////////////////////////
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
		TEST(BrinStruct, AssurtOnATotelyEmty)
		{
			EXPECT_DEATH(gaia::NodeSetUp n({ 0,0,0,0 }), "");
		}
	}
}