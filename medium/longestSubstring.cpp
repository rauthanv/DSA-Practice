// Problem: Longest Substring Without Repeating Characters

// Approach: Sliding Window + Hash map


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> chars;
        int maxLen = 0;
        int left = 0, right = 0;

        while (right < s.length()) {
            if (!chars.count(s[right])) {
                chars.insert(s[right]);
                maxLen = max(maxLen, right - left + 1);
                right++;
            } else {
                chars.erase(s[left]);
                left++;
            }
        }
        return maxLen;
    }
};
