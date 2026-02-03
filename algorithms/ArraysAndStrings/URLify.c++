// Write a method to replace all spaces in a strong with '%20'
// Assume string has sufficient space and given the correct length of a string

#include <iostream>
#include <string>

// Completed with Time Complexity of O(N) and Space Complexity of O(N)

// std::string urlify(std::string& input,int strLength){
//     std::string output;
//     for (auto &c : input) {
//         if (c == ' '){
//             output += "%20";
//         }
//         else {
//             output += c;
//         }
//     }
//     return output;
// }


// Completed with Time Complexity of O(N) and Space Complexity of O(1)

std::string urlify(std::string& input, int strLength) {
    // Grab the amount of spaces within the input string
    int spaceCount = 0;
    for (const auto &c : input){
        if (c == ' ') {
            spaceCount++;
        }
    }

    // Calculate the new length of the string
    // Each ' ' will be changed to '%20' therefore adding 2 extra space per space found
    int newLength = strLength + spaceCount * 2;
    input.resize(newLength);

    // Work backwards to add all chars
    for (int i = strLength - 1, j = newLength - 1; i >= 0 ; i--){
        
        // If space is found
        if (input[i] == ' '){
            input[j--] = '0';
            input[j--] = '2';
            input[j--] = '%';
        } else {
            input[j--] = input[i];
        }  
    }

    return input;
}

// 0123456789012
// Mr John Smith

int main() {
    std::string input = "Mr John Smith";
    int inputLength = input.length();

    std::string output = urlify(input, inputLength);
    std::cout << output;
    return 0;
}