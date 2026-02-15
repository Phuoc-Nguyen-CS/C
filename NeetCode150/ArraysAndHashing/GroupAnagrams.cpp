#include "includes.h"

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs) {

        // We have the map
        std::unordered_map<std::string, std::vector<std::string>> mp;

        // Grab each string
        for (const auto &s : strs) {
            // Sort the string and then input it in the mp
            std::string sortedS = s;
            std::sort(sortedS.begin(), sortedS.end());
            mp[sortedS].push_back(s);
        }

        std::vector<std::vector<std::string>> result;

        for (const auto &pair : mp) {
            result.push_back(pair.second);
        }

        return result;
    }
};
