
// Problem: Find All Anagrams in a String (LeetCode 438)

// Approach: Sliding Window + Frequency Array
// 1. Create two frequency arrays of size 26:
//    - freqP stores the frequency of characters in p.
//    - freqS stores the frequency of characters in the current window of s.
// 2. Initialize both frequency arrays using the first n characters.
// 3. Slide the window across s:
//    - Compare freqS and freqP.
//    - If both arrays are equal, store the starting index.
//    - Decrease the frequency of the character leaving the window.
//    - Increase the frequency of the character entering the window.
// 4. Return the indices where anagrams are found.

// Time Complexity: O(m + n)
// Space Complexity: O(1)

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        int n = p.size();
        int m = s.size();

        if (n > m)
            return ans;

        vector<int> freqS(26, 0), freqP(26, 0);

        // Initialize frequency arrays for the first window
        for (int i = 0; i < n; i++) {
            freqS[s[i] - 'a']++;
            freqP[p[i] - 'a']++;
        }

        // Slide the window across the string
        for (int i = 0; i <= m - n; i++) {

            // Check if the current window is an anagram of p
            if (freqP == freqS)
                ans.push_back(i);

            // Remove the character leaving the window
            freqS[s[i] - 'a']--;

            // Add the next character entering the window
            if (i + n < m) {
                freqS[s[i + n] - 'a']++;
            }
        }

        return ans;
    }
};
