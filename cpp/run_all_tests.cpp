#include "chat_logic.h"
#include <gtest/gtest.h>

TEST(ChatSentiment, PositiveMessage) {
    std::vector<std::string> msgs = {"I am happy", "This is great"};
    EXPECT_EQ(analyzeSentiment(msgs), 1);
}
