#include "gtest/gtest.h"

#include "tartarus.h"
namespace gaia
{
	TEST(BasictTests, IncludeCorectly)
	{
		EXPECT_TRUE(test());
	}

	TEST(GetRandom, CantEnterLesThenOne)
	{
		EXPECT_DEATH(get_random_range_normalized(0), "");
	}
	TEST(GetRandom, ReturnsSmallerThenOne)
	{
		EXPECT_TRUE(1.0f > get_random_range_normalized(100));
		EXPECT_TRUE(1.0f > get_random_range_normalized(1000));
		EXPECT_TRUE(1.0f > get_random_range_normalized(10000));
		EXPECT_TRUE(1.1f > get_random_range_normalized(1));

	}
	TEST(NormalizedIndevidual, SetsUpToCorrectSize)
	{
		NormalizedIndividual dnaTest({Negativity::NagativAndPositive ,20, 10 });
		EXPECT_EQ(dnaTest.size(), 20);
	}
	TEST(TestDynamicIndividualBluePrint, CantMakeUtilizationBiggerThenCompletSetIfUnique)
	{
		std::vector<std::any> test = { 4,9,3,7};
		EXPECT_DEATH(DynamicIndividualBluePrint(Repeatability::Unique,5,test), "");
		EXPECT_DEATH(DynamicIndividualBluePrint(Repeatability::Unique, 100, test), "");
	}
	TEST(TestDynamicIndividualBluePrint, CanMakeUtilizationBiggerThenCompletSetRepeatable)
	{
		std::vector<std::any> test = { 4,9,3,7 };
		auto test1 = DynamicIndividualBluePrint(Repeatability::Repeatable, 5, test);
		EXPECT_TRUE(test1._completSet.size() == test.size());
	}
}