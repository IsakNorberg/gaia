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
		EXPECT_DEATH(getRandom(0), "");
	}
	TEST(GetRandom, ReturnsSmallerThenOne)
	{
		EXPECT_TRUE(1.0f > getRandom(100));
		EXPECT_TRUE(1.0f > getRandom(1000));
		EXPECT_TRUE(1.0f > getRandom(10000));
		EXPECT_TRUE(1.1f > getRandom(1));

	}
	TEST(ObjectDna, SetsUpToCorrectSize)
	{
		Dna dnaTest({ 20, 10 });

	}
}