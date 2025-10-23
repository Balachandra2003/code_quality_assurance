// copyright 2025 Bala
#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "cpp/chat_logic.h"

TEST(SentimentTest, PositiveMessages) {
    std::vector<std::string> msgs = {"I love this", "good job"};
    EXPECT_EQ(analyzeSentiment(msgs), 1);
}

TEST(SentimentTest, NegativeMessages) {
    std::vector<std::string> msgs = {"bad experience", "worst day"};
    EXPECT_EQ(analyzeSentiment(msgs), -1);
}

TEST(SentimentTest, NeutralMessages) {
    std::vector<std::string> msgs = {"ok", "fine"};
    EXPECT_EQ(analyzeSentiment(msgs), 0);
}
