#include <stdio.h>

// Implement an algorithm to determine if a string has all unique characters
int isUnique(const char *str) {
    int seen[256] = {0}; 
    // Loop through the string
    while (*str) {
        // Converts char -> ASCII Value
        unsigned char val = *str;
        
        if (seen[val]) {
            return 0; // Character already seen
        }
        seen[val] = 1;
        str++;
    }
    return 1; // All characters are unique
}

int main() {
    const char *testStr1 = "abcdefg";
    const char *testStr2 = "hello";

    printf("Is \"%s\" unique? %s\n", testStr1, isUnique(testStr1) ? "Yes" : "No");
    printf("Is \"%s\" unique? %s\n", testStr2, isUnique(testStr2) ? "Yes" : "No");
    return 0;
}