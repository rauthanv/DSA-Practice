// Problem: First Non-Repeating Character in a Stream

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    // =====================================================
    // Method 1: Frequency Array
    // Approach:
    // 1. Maintain frequency of characters.
    // 2. For every step:
    //    - update frequency
    //    - scan string till current index
    //    - find first character with frequency 1
    //
    // Time Complexity: O(n^2)
    // Space Complexity: O(26)
    // =====================================================

    string firstNonRepeatingFreq(string &s) {

        vector<int> freq(26, 0);

        string ans = "";

        for(int i = 0; i < s.size(); i++) {

            freq[s[i] - 'a']++;

            char first = '#';

            for(int j = 0; j <= i; j++) {

                if(freq[s[j] - 'a'] == 1) {
                    first = s[j];
                    break;
                }
            }

            ans.push_back(first);
        }

        return ans;
    }


    // =====================================================
    // Method 2: Queue + Frequency Array (Optimal)
    // Approach:
    // 1. Store frequency of characters.
    // 2. Use queue to maintain insertion order.
    // 3. Remove repeating characters from front.
    // 4. Front of queue = first non-repeating character.
    //
    // Time Complexity: O(n)
    // Space Complexity: O(26)
    // =====================================================

    string firstNonRepeatingOptimal(string &s) {

        vector<int> freq(26, 0);
        queue<char> q;

        string ans = "";

        for(char ch : s) {

            freq[ch - 'a']++;
            q.push(ch);

            while(!q.empty() && freq[q.front() - 'a'] > 1) {
                q.pop();
            }

            if(q.empty()) {
                ans.push_back('#');
            }
            else {
                ans.push_back(q.front());
            }
        }

        return ans;
    }
};