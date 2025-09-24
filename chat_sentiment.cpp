// copyright 2025 Balu
#include <iostream>
#include <string>
#include <vector>
// using namespace std;

int main() {
    // Define positive and negative keywords
    std::vector<std::string> positive = {
        "good", "happy", "great", "love", "nice", "awesome"};
    std::vector<std::string> negative = {
        "bad", "sad", "angry", "hate", "worst", "ugly"};

    std::cout << "------ Chat Session Started ------" << std::endl;
    std::cout << "Type 'end' anytime to stop the chat." << std::endl;

    std::string msg;
    int posCount = 0, negCount = 0;
    int turn = 1;  //1 = User1, 2 = User2

    while (true) {
        std::cout << "User" << turn << ": ";
        getline(std::cin, msg);

        if (msg == "end" || msg == "END")
            break;  //stop chat

        // Check for positive/negative keywords
        for (auto &word : positive) {
            if (msg.find(word) != std::string::npos) {
                posCount++;
            }
        }
        for (auto &word : negative) {
            if (msg.find(word) != std::string::npos) {
                negCount++;
            }
        }

        // Switch turn
        turn = (turn == 1) ? 2 : 1;
    }

    // Show sentiment report
    std::cout << "\n------ Chat Sentiment Report ------\n";
    std::cout << "Positive messages count: " << posCount << std::endl;
    std::cout << "Negative messages count: " << negCount << std::endl;

    if (posCount > negCount)
        std::cout << "Overall Sentiment: Positive" << std::endl;
    else if (negCount > posCount)
        std::cout << "Overall Sentiment: Negative" << std::endl;
    else
        std::cout << "Overall Sentiment: Neutral" << std::endl;

    std::cout << "------ Chat Session Ended ------" << std::endl;

    return 0;
}
