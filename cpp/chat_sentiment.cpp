// copyright 2025 Bala
#include <iostream>
#include <string>
#include <vector>
#include "chat_logic.h"

int main() {
    std::cout << "------ Chat Session Started ------" << std::endl;
    std::vector<std::string> messages;
    std::string msg;
    int turn = 1;

    while (true) {
        std::cout << "User" << turn << ": ";
        std::getline(std::cin, msg);
        if (msg == "end" || msg == "END") break;
        messages.push_back(msg);
        turn = (turn == 1) ? 2 : 1;
    }

    int sentiment = analyzeSentiment(messages);
    if (sentiment == 1) std::cout << "Overall Sentiment: Positive\n";
    else if (sentiment == -1) std::cout << "Overall Sentiment: Negative\n";
    else std::cout << "Overall Sentiment: Neutral\n";
}
