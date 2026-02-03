// One Away: There are three types of edits that can be performed on strings
// One Away: There are three types of edits that can be performed on strings
// One Away: There are three types of edits that can be performed on strings
// 1.) Insert a character
// 2.) Remove a character
// 3.) Replace a character
// Given two strings, write a function to cvheck if they are one edit or zero edits away
#include <iostream>
#include <string>
#include <cmath>
#include <iterator>

int oneAway(std::string str1, std::string str2) {

    // If the difference in string length is greater than 1
    // Return
    if (std::abs((int)str1.length() - (int)str2.length()) > 1) {
        return 0;
    }

    // Employ the two pointer
    auto p1 = str1.begin();
    auto p2 = str2.begin();

    int numChanges = 0;

    while (p1 != str1.end() && p2 != str2.end()){
        if (*p1 != *p2) {
            numChanges++;
            // If there is more than one change. Return
            if (numChanges > 1) return numChanges;

            if (str1.length() > str2.length()) {
                p1++;
            }
            else if (str2.length() > str1.length()) {
                p2++;
            } 
            else {
                p1++;
                p2++;
            }
        } 
        else {
            p1++;
            p2++;
        }
    }



    return numChanges;
}

int main() {
    std::string str1 = "pale";
    std::string str2 = "ple";

    std::string str3 = "pales";
    std::string str4 = "pale";

    std::string str5 = "pale";
    std::string str6 = "bale";

    std::string str7 = "pale";
    std::string str8 = "bake";

    std::cout << "The number of changes == " << (oneAway(str1, str2)) << std::endl;
    std::cout << "The number of changes == " << (oneAway(str3, str4)) << std::endl;
    std::cout << "The number of changes == " << (oneAway(str5, str6)) << std::endl;
    std::cout << "The number of changes == " << (oneAway(str7, str8)) << std::endl;

    return 0;
}