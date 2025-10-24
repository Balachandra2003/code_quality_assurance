// Copyright 2025 Bala

#include <string>
#include <vector>

#include "chat_logic.h"

int analyzeSentiment(const std::vector<std::string>& messages) {
    std::vector<std::string> positive = {
        "good", "happy", "great", "love", "nice", "awesome"
    };
    std::vector<std::string> negative = {
        "bad", "sad", "angry", "hate", "worst", "ugly"
    };

    int posCount = 0;
    int negCount = 0;
    for (const auto& msg : messages) {
        for (const auto& word : positive) {
            if (msg.find(word) != std::string::npos) posCount++;
        }
        for (const auto& word : negative) {
            if (msg.find(word) != std::string::npos) negCount++;
        }
    }

    if (posCount > negCount) return 1;
    if (negCount > posCount) return -1;
    return 0;
}
