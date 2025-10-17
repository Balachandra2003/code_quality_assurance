#include "chat_logic.cpp"  // include only logic
#include "googletest/googletest/include/gtest/gtest.h"

TEST(ChatSentimentTest, PositiveSentiment) {
    std::vector<std::string> msgs = {"I am happy", "You are great", "This is awesome"};
    EXPECT_EQ(analyzeSentiment(msgs), 1);
}

TEST(ChatSentimentTest, NegativeSentiment) {
    std::vector<std::string> msgs = {"I am sad", "This is bad", "I hate it"};
    EXPECT_EQ(analyzeSentiment(msgs), -1);
}

TEST(ChatSentimentTest, NeutralSentiment) {
    std::vector<std::string> msgs = {"hello", "how are you", "normal chat"};
    EXPECT_EQ(analyzeSentiment(msgs), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}