// Problem: Jump Game

// Approaches:
// 1. Recursion + Memoization   [Commented]
// 2. Greedy (Optimal)          [Implemented]
//
// Goal:
// Determine if we can reach the last index


class Solution {
public:

    /* -------------------- RECURSION + MEMO --------------------*/
    // Time: O(n^2), Space: O(n)
    vector<int> t;

    bool getans(vector<int>& nums, int n) {
        if (n >= nums.size() - 1) return true;
        if (t[n] != -1) return t[n];

        for (int jump = 1; jump <= nums[n]; jump++) {
            if (getans(nums, n + jump)) {
                return t[n] = true;
            }
        }
        return t[n] = false;
    }

    bool canJump(vector<int>& nums) {
        t.assign(nums.size(), -1);
        return getans(nums, 0);
    }
    


    /* -------------------- GREEDY (OPTIMAL) -------------------- */
    // Time: O(n), Space: O(1)
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;

        for (int i = 0; i < n; i++) {
            if (i > farthest) return false;

            farthest = max(farthest, i + nums[i]);

            if (farthest >= n - 1) return true;
        }
        return true;
    }
};
