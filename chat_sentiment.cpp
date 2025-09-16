#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    // Define positive and negative keywords
    vector<string> positive = {"good", "happy", "great", "love", "nice", "awesome"};
    vector<string> negative = {"bad", "sad", "angry", "hate", "worst", "ugly"};

    cout << "------ Chat Session Started ------" << endl;
    cout << "Type 'end' anytime to stop the chat." << endl;

    string msg;
    int posCount = 0, negCount = 0;
    int turn = 1; // 1 = User1, 2 = User2

    while (true) {
        cout << "User" << turn << ": ";
        getline(cin, msg);

        if (msg == "end" || msg == "END") break; // stop chat

        // Check for positive/negative keywords
        for (auto &word : positive) {
            if (msg.find(word) != string::npos) posCount++;
        }
        for (auto &word : negative) {
            if (msg.find(word) != string::npos) negCount++;
        }

        // Switch turn
        turn = (turn == 1) ? 2 : 1;
    }

    // Show sentiment report
    cout << "\n------ Chat Sentiment Report ------\n";
    cout << "Positive messages count: " << posCount << endl;
    cout << "Negative messages count: " << negCount << endl;

    if (posCount > negCount)
        cout << "Overall Sentiment: Positive" << endl;
    else if (negCount > posCount)
        cout << "Overall Sentiment: Negative" << endl;
    else
        cout << "Overall Sentiment: Neutral" << endl;

    cout << "------ Chat Session Ended ------" << endl;

    return 0;
}
