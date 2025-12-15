// Problem: Jump Game II

// Approaches Used:
// 1. Recursion(Memo) (Exponential)      
// 2. DP (Tabulation)              
// 3. Greedy (Optimized)           
//
// Goal:
// Find the minimum number of jumps to reach the last index


class Solution {
public:

    /* -------------------- RECURSION(Memo) --------------------*/
    // Time: O(n^2)
    int t[10001];

    int findlen(vector<int>& nums, int n) {
        if (n >= nums.size() - 1) return 0;
        if (nums[n] == 0) return 1e9;
        if (t[n] != -1) return t[n];

        int ans = 1e9;
        for (int jump = 1; jump <= nums[n]; jump++) {
            ans = min(ans, 1 + findlen(nums, n + jump));
        }
        return t[n] = ans;
    }

    int jump(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        return findlen(nums, 0);
    }
    

    /* -------------------- DP (TABULATION) --------------------*/
    // Time: O(n^2)
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n, 1e9);
        t[n - 1] = 0;

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 1; j <= nums[i] && i + j < n; j++) {
                t[i] = min(t[i], 1 + t[i + j]);
            }
        }
        return t[0];
    }
    


    /* -------------------- GREEDY (OPTIMAL) -------------------- */
    // Time: O(n), Space: O(1)
    int jump(vector<int>& nums) {
        int l = 0, r = 0;
        int jumps = 0;
        int n = nums.size();

        while (r < n - 1) {
            int farthest = 0;

            for (int i = l; i <= r; i++) {
                farthest = max(farthest, i + nums[i]);
            }

            l = r + 1;
            r = farthest;
            jumps++;
        }
        return jumps;
    }
};
