// Problem: Minimum Path Sum
// LeetCode: https://leetcode.com/problems/minimum-path-sum/
//
// Concept: Dynamic Programming 
//
// Rule:
// - You can move only RIGHT or DOWN
// - Find the minimum sum path from top-left to bottom-right


class Solution {
public:

    // -----------------------------------
    // Approach 1: Recursive (Brute Force)
    // Time: Exponential
    // Space: O(n + m)
    // -----------------------------------
    
    int solve(vector<vector<int>>& grid, int i, int j) {
        if (i >= grid.size() || j >= grid[0].size())
            return INT_MAX;
        if (i == grid.size() - 1 && j == grid[0].size() - 1)
            return grid[i][j];

        return grid[i][j] + min(solve(grid, i + 1, j),
                                 solve(grid, i, j + 1));
    }

    int minPathSum(vector<vector<int>>& grid) {
        return solve(grid, 0, 0);
    }

    // -----------------------------------
    // Approach 2: Memoization
    // Time: O(n × m)
    // Space: O(n × m)
    // -----------------------------------

    int t[201][201];

    int solve(vector<vector<int>>& grid, int i, int j) {
        if (i >= grid.size() || j >= grid[0].size())
            return INT_MAX;
        if (i == grid.size() - 1 && j == grid[0].size() - 1)
            return grid[i][j];
        if (t[i][j] != -1)
            return t[i][j];

        return t[i][j] = grid[i][j] + min(solve(grid, i + 1, j),
                                          solve(grid, i, j + 1));
    }

    int minPathSum(vector<vector<int>>& grid) {
        memset(t, -1, sizeof(t));
        return solve(grid, 0, 0);
    }
    */

    // -----------------------------------
    // Approach 3: Tabulation 
    // Time: O(n × m)
    // Space: O(n × m)
    // -----------------------------------
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m));

        dp[0][0] = grid[0][0];

        for (int j = 1; j < m; j++)
            dp[0][j] = grid[0][j] + dp[0][j - 1];

        for (int i = 1; i < n; i++)
            dp[i][0] = grid[i][0] + dp[i - 1][0];

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                dp[i][j] = grid[i][j] + min(dp[i - 1][j],
                                            dp[i][j - 1]);
            }
        }
        return dp[n - 1][m - 1];
    }
};
