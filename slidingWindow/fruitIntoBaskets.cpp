// Problem: Fruit Into Baskets

// Approach:
// 1. Use Variable Size Sliding Window.
// 2. Maintain frequency map of fruits in current window.
// 3. Expand right pointer.
// 4. If basket types become more than 2:
//      shrink window from left.
// 5. Store maximum valid window size.
//
// Time Complexity: O(n)
// Space Complexity: O(2) ≈ O(1)

class Solution {
public:

    int totalFruit(vector<int>& fruits) {

        unordered_map<int,int> freq;

        int l = 0;
        int r = 0;

        int maxFruits = 0;

        while(r < fruits.size()) {

            freq[fruits[r]]++;
            // More than 2 fruit types
            while(freq.size() > 2) {
                freq[fruits[l]]--;
                if(freq[fruits[l]] == 0)
                    freq.erase(fruits[l]);
                l++;
            }

            maxFruits = max(maxFruits,r-l+1);
            r++;
        }
        return maxFruits;
    }
};