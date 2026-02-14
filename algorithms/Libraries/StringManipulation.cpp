#include <string>
#include <vector>
#include <sstream>
#include <iostream>

void string_review() {
    
    std::string s = "this is a string";
    std::stringstream ss(s);
    std::string word;

    // Splitting by the space
    while (ss >> word) {
        // We Process the word here
        std::cout << word;
    }

    // Conversions
    int val = std::stoi("42");
    std::string backToString = std::to_string(42);

    // Substrings (index, length)
    std::string sub = s.substr(0, 3); // "this"
}   