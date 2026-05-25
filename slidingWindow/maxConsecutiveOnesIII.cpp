// Problem: Max Consecutive Ones III

// Approach:
// 1. Use Variable Size Sliding Window.
// 2. Expand right pointer.
// 3. Count number of zeros in current window.
// 4. If zeros exceed k:
//      shrink window from left.
// 5. Keep track of maximum valid window length.
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:

    int longestOnes(vector<int>& nums, int k) {

        int l = 0;
        int r = 0;
        int zeros = 0;
        int maxLen = 0;

        while(r < nums.size()) {

            if(nums[r] == 0)
                zeros++;

            // Invalid window
            if(zeros > k) {
                if(nums[l] == 0) zeros--;
                l++;
            }

            // Valid window
            if(zeros <= k) {
                maxLen = max(maxLen, r-l+1);
            }
            r++;
        }
        return maxLen;
    }
};