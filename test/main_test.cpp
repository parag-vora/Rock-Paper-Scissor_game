#include<gtest/gtest.h>
extern "C" {
#include "../src/logic_function.h"
}

TEST(RockPaperScissorTest, FinalDecision) {
    // Test cases for Finaldecision function
    EXPECT_NO_THROW(Finaldecision(1, 1)); // ROCK vs ROCK
    EXPECT_NO_THROW(Finaldecision(2, 2)); // PAPER vs PAPER
    EXPECT_NO_THROW(Finaldecision(3, 3)); // SCISSOR vs SCISSOR
    EXPECT_NO_THROW(Finaldecision(1, 2)); // ROCK vs PAPER
    EXPECT_NO_THROW(Finaldecision(2, 1)); // PAPER vs ROCK
    EXPECT_NO_THROW(Finaldecision(1, 3)); // ROCK vs SCISSOR
    EXPECT_NO_THROW(Finaldecision(3, 1)); // SCISSOR vs ROCK
    EXPECT_NO_THROW(Finaldecision(2, 3)); // PAPER vs SCISSOR
    EXPECT_NO_THROW(Finaldecision(3, 2)); // SCISSOR vs PAPER
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}