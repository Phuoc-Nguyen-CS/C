// checkPermutation.c++
// Given two strings, write a method to decide if one is a permutation of the other

#include <iostream>
#include <unordered_map>
#include <string>
#include <chrono>

// Loop through string1 and add to hash
// Loop through string2 and decrement the hash
// Check if everything in hash table is set at 0
// If not return False
// If so return True

bool isPermutation(std::string *string1, std::string  *string2){
    if (string1->length() != string2->length()){
        return false;
    }

    std::unordered_map<char, int> hash;

    for (char c : *string1){
        hash[c]++;
    }

    for (char c : *string2){
        hash[c]--;
        if (hash[c] < 0) {
            return false;
        }
    }

    return true;
}

int main (){
    auto start = std::chrono::high_resolution_clock::now();

    std::string string1 = "abc";
    std::string string2 = "bac";
    std::string string3 = "bbb";

    std::cout << "Is " << string1 << " a permutation of " << string2 << "? " 
              << (isPermutation(&string1, &string2) ? "Yes" : "No") << std::endl;
    
    std::cout << "Is " << string2 << " a permutation of " << string3 << "? " 
              << (isPermutation(&string2, &string3) ? "Yes" : "No") << std::endl;

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end-start);

    std::cout << "Time taken: " << duration.count() << " microseconds" << std::endl;

    return 0;
}