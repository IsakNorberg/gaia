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
		EXPECT_DEATH(get_Random_Range_Normalized(0), "");
	}
	TEST(GetRandom, ReturnsSmallerThenOne)
	{
		EXPECT_TRUE(1.0f > get_Random_Range_Normalized(100));
		EXPECT_TRUE(1.0f > get_Random_Range_Normalized(1000));
		EXPECT_TRUE(1.0f > get_Random_Range_Normalized(10000));
		EXPECT_TRUE(1.1f > get_Random_Range_Normalized(1));

	}
	TEST(ObjectDna, SetsUpToCorrectSize)
	{
		Dna dnaTest({ 20, 10 });
		EXPECT_EQ(dnaTest.size(), 20);
	}
}