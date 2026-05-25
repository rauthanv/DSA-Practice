// Problem: Minimum Size Subarray Sum

// Approach:
// 1. Use Variable Size Sliding Window.
// 2. Expand right pointer and keep adding elements.
// 3. Once sum >= target:
//      - window becomes valid
//      - update minimum length
//      - shrink from left
// 4. Continue until smallest valid window is found.
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:

    int minSubArrayLen(int target, vector<int>& nums) {

        int l = 0;
        int r = 0;
        int sum = 0;
        int minLen = INT_MAX;
        bool found = false;

        while(r < nums.size()) {
            sum += nums[r];

            // Valid window
            while(sum >= target && l <= r) {

                found = true;
                minLen = min(minLen, r-l+1);
                sum -= nums[l];
                l++;
            }
            r++;
        }

        if(!found) return 0;
        return minLen;
    }
};