// Problem: Climbing Stairs

// Concept: Dynamic Programming (Fibonacci Pattern)

class Solution {
public:

    // -----------------------------------
    // Memoization (Top-Down)
    // Time: O(n)
    // Space: O(n)
    // -----------------------------------
    
    int solve(int n, vector<int>& memo) {
        if (n == 0 || n == 1)
            return 1;
        if (memo[n] != -1)
            return memo[n];
        return memo[n] = solve(n - 1, memo) + solve(n - 2, memo);
    }

    int climbStairs(int n) {
        vector<int> memo(n + 1, -1);
        return solve(n, memo);
    }
    

    // -----------------------------------
    // Tabulation (Bottom-Up)
    // Time: O(n)
    // Space: O(n)
    // -----------------------------------
    
    int climbStairs(int n) {
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    // -----------------------------------
    // Space Optimized DP
    // Time: O(n)
    // Space: O(1)
    // -----------------------------------
    int climbStairs(int n) {
        int prev2 = 1; 
        int prev1 = 1;  

        for (int i = 2; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
