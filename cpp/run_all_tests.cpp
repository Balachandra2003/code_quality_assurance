// Copyright 2025 Bala

#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "cpp/chat_logic.h"

TEST(ChatSentiment, PositiveMessage) {
    std::vector<std::string> msgs = {"I am happy", "This is great"};
    EXPECT_EQ(analyzeSentiment(msgs), 1);
}
