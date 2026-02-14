// Design a method to find the frequency of occurences of any give nword in a book.

#include <string>
#include <iostream>
#include <unordered_map>
#include <sstream> //stringstream
// Takes in a book and returns the number of time the word is found in the book
// Time Complexity O(N)
// Space Complexity O(1)
int wordFrequency(std::string book, std::string target) {
    
    int found = 0;
    std::string word = "";
    
    // Loop through the book and find the number of occurrences.
    for (char c : book) {
        if (c == ' ') {
            if(!word.empty()) {
                if(word == target) found++;
                word = "";
            }
        }
        else {
            word += c;
        }
    }
    return found;
}

// What if we were running this algorith multiple times?

// We would then need to cache the book into a map so 
// if they were to call it again we'd have an immediate look up.
// Time Complexity O(N) but the look up for future words would be O(1)
void wordFrequencyCache(std::string book, std::unordered_map<std::string, int>& mp) {
    std::string word = "";
    // Loop through the book and every word add to cache 
    for (char c : book) {
        if (c == ' ') {
            if (!word.empty()) {
                mp[word]++;
                word = "";
            }
        } else {
            word += c;
        }
    }

    // Gets the last word in case no space at the end.
    if (!word.empty()) {
        mp[word]++;
    }
}

void wordFrequencyCacheStringStream(std::string book, std::unordered_map<std::string, int>& mp) {
    std::stringstream ss(book);
    std::string word;

    while (ss >> word) {
        mp[word]++;
    }
}
int main() {
    std::unordered_map<std::string, int> mp;
    std::string book = "  apple banana   apple orange banana apple  ";
    int wordCount = wordFrequency(book, "apple");
    wordFrequencyCacheStringStream(book, mp);

    std::cout << "--- wordFrequency O(N) ---" << std::endl;
    std::cout << wordCount << std::endl;

    std::cout << "--- Dictionary Contents ---" << std::endl;
    for (auto const &[word, count] : mp)
    {
        std::cout << word << ": " << count << std::endl;
    }
    return 0;
}