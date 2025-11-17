// Copyright 2025 Bala

#include <algorithm>
#include <string>
#include <vector>

#include "chat_logic.h"

int analyzeSentiment(const std::vector<std::string>& messages) {
    const std::vector<std::string> positive = {
        "good", "happy", "great", "love", "nicer", "awesome"
    };
    const std::vector<std::string> negative = {
        "bad", "sad", "angry", "hate", "worst", "ugly"
    };

    int posCount = 0;
    int negCount = 0;

    for (const auto& msg : messages) {
        posCount += std::count_if(
            positive.begin(), positive.end(),
            [&](const std::string& word) {
                return msg.find(word) != std::string::npos;
            });
        negCount += std::count_if(
            negative.begin(), negative.end(),
            [&](const std::string& word) {
                return msg.find(word) != std::string::npos;
            });
    }

    if (posCount > negCount) return 1;
    if (negCount > posCount) return -1;
    return 0;
}
