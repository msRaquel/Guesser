/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};



// distance tester
TEST(GuesserTest, empty_string)
{
	Guesser my_guess("ABC");
	int distance = my_guess.distance("");
	ASSERT_EQ(3, distance);

}

TEST(GuesserTest, empty_space)
{
	Guesser my_guess("ABC");
	int distance = my_guess.distance("AB C");
	ASSERT_EQ(2, distance);
}

TEST(GuesserTest, less_than)
{
	Guesser my_guess("ABCD");
	int distance = my_guess.distance("ABC");
	ASSERT_EQ(1, distance);
}

TEST(GuesserTest, equal_length_case)
{
	Guesser my_guess("ABCDe");
	int distance = my_guess.distance("ABCeD");
	ASSERT_EQ(2, distance);
}
TEST(GuesserTest, long_guess)
{
	Guesser my_guess("ABCDe");
	int distance = my_guess.distance("ABCDEFGHIJKLMNOPQRXTUVWXYZ");
	ASSERT_EQ(5, distance);
}

TEST(GuesserTest, VerifyRemainingAttempts) {
    Guesser my_guess("secret");

  
    my_guess.match("wrong1");
    my_guess.match("wrong2");
    my_guess.match("wrong3");

    EXPECT_FALSE(my_guess.match("secret"));
}

TEST(GuesserTest, verify_match) {
    string input = "1234567890123456789012345678901234567890";
    string truncated = "12345678901234567890123456789012";
    Guesser my_guess(input);

    EXPECT_TRUE(my_guess.match(truncated));
}


TEST(GuesserTest, constructor_test) {
    string longSecret(40, 'A');
    Guesser my_guess(longSecret);

  
   
    EXPECT_EQ(my_guess.m_remaining, 3);
    EXPECT_FALSE(my_guess.m_locked);
}