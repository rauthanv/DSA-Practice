// Problem: House Robber

// Concept: Dynamic Programming (1D DP)

class Solution {
public:

    // -----------------------------------
    // Approach 2: Memoization 
    // Time: O(n)
    // Space: O(n)
    // -----------------------------------
    
    int t[101];

    int solve(vector<int>& nums, int i) {
        if (i >= nums.size())
            return 0;
        if (t[i] != -1)
            return t[i];
        return t[i] = max(solve(nums, i + 1),
                           nums[i] + solve(nums, i + 2));
    }

    int rob(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        return solve(nums, 0);
    }


    // -----------------------------------
    // Approach 3: Tabulation (Bottom-Up)
    // Time: O(n)
    // Space: O(n)
    // -----------------------------------
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n + 2, 0);

        for (int i = n - 1; i >= 0; i--) {
            t[i] = max(t[i + 1],
                        nums[i] + t[i + 2]);
        }
        return t[0];
    }


    // -----------------------------------
    // Approach 4: Space Optimized DP
    // Time: O(n)
    // Space: O(1)
    // -----------------------------------
    int rob(vector<int>& nums) {
        int next1 = 0;  // t[i+1]
        int next2 = 0;  // t[i+2]

        for (int i = nums.size() - 1; i >= 0; i--) {
            int curr = max(next1, nums[i] + next2);
            next2 = next1;
            next1 = curr;
        }
        return next1;
    }
};
