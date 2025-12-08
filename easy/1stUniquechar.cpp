// Problem: First Unique Character in a String

// Approach:
// 1. Count frequency of every character using unordered_map.
// 2. Loop again to find the first character with frequency == 1.

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> um;

        // Count occurrences
        for(char c : s) {
            um[c]++;
        }

        // Find first unique character
        for(int i = 0; i < s.size(); i++) {
            if(um[s[i]] == 1) return i;
        }

        return -1;
    }
};

