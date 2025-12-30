// Problem: Longest Palindromic Substring

class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;     // starting index of best palindrome
        int maxLen = 1;    // length of best palindrome

        for (int i = 0; i < s.size(); i++) {

            // -------------------
            // Odd length palindrome
            // -------------------
            int l = i - 1;
            int r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r - l + 1 > maxLen) {
                    start = l;
                    maxLen = r - l + 1;
                }
                l--;
                r++;
            }

            // --------------------
            // Even length palindrome
            // --------------------
            l = i;
            r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r - l + 1 > maxLen) {
                    start = l;
                    maxLen = r - l + 1;
                }
                l--;
                r++;
            }
        }
        return s.substr(start, maxLen);
    }
};
