// Problem: Matrix Chain Multiplication

// Idea:
// Given array arr[] of size N
// Matrix i has dimension arr[i-1] x arr[i]
// Find minimum cost to multiply matrices from 1 to N-1


class Solution {
public:

    // ------------------------------------------------
    // Approach 1: Recursive (Brute Force)
    // Time: Exponential
    // ------------------------------------------------
    
    int solve(vector<int>& arr, int i, int j) {
        if (i == j) return 0;

        int ans = INT_MAX;
        for (int k = i; k < j; k++) {
            ans = min(ans,
                      solve(arr, i, k) +
                      solve(arr, k + 1, j) +
                      arr[i - 1] * arr[k] * arr[j]);
        }
        return ans;
    }

    int matrixMultiplication(vector<int>& arr) {
        return solve(arr, 1, arr.size() - 1);
    }
    

    // ------------------------------------------------
    // Approach 2: Memoization 
    // Time: O(N³)
    // ------------------------------------------------
    
    int dp[101][101];

    int solve(vector<int>& arr, int i, int j) {
        if (i == j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;
        for (int k = i; k < j; k++) {
            ans = min(ans,
                      solve(arr, i, k) +
                      solve(arr, k + 1, j) +
                      arr[i - 1] * arr[k] * arr[j]);
        }
        return dp[i][j] = ans;
    }

    int matrixMultiplication(vector<int>& arr) {
        memset(dp, -1, sizeof(dp));
        return solve(arr, 1, arr.size() - 1);
    }
    
};
