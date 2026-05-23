// Problem: Max Consecutive Ones

// Approach:
// 1. Use two pointers to track a continuous block of 1s.
// 2. Expand right pointer.
// 3. Whenever 0 is found:
//      - calculate current length
//      - update maximum
//      - move left after 0
// 4. Handle last segment separately.
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:

    int findMaxConsecutiveOnes(vector<int>& nums) {

        int l = 0;
        int r = 0;
        int maxOnes = 0;

        while(r < nums.size()) {

            if(nums[r] != 1) {
                maxOnes = max(maxOnes,r - l);
                l = r + 1;
            }
            r++;
        }
        maxOnes = max(maxOnes,r - l);
        
        return maxOnes;
    }
};