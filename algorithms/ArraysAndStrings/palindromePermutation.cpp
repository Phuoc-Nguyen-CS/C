// Palindrome Permutation: Given a string, write a function to check if it is a permutation of
// a palindrome. 

#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype> // Required for toLower

int palindromePermutation(std::string& str){
    // Add all char from str1 to a hashmap
    std::unordered_map<char, int>  hm;
    for (unsigned char c : str) {
        if (std::isalpha(c)){
            hm[std::tolower(c)]++;
        }
    }
    int oddCount = 0;
    for (auto const& [character, count] : hm) {
        if (count % 2 != 0){
            oddCount++;
        }
    }
    return oddCount <= 1;
}

int main() {
    std::string str1 = "Tact Coa";

    std::cout << (palindromePermutation(str1) ? "Yes":"No") << std::endl;
    return 0;
}