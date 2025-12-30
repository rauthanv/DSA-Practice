// ------------------------------------------------------------
// Problem: Minimum Falling Path Sum
// Link: https://leetcode.com/problems/minimum-falling-path-sum/

// Approaches:
// 1. Recursion
// 2. Memoization (Top-Down DP)
// 3. Tabulation (Bottom-Up DP)
// ------------------------------------------------------------

class Solution {
public:

    /* ============================================================
       1. RECURSION
       ============================================================ */
    // Time Complexity: O(3^n)
    // Space Complexity: O(n) (recursion stack)

    int solveRecursive(vector<vector<int>>& matrix, int i, int j) {
        int n = matrix.size();

        if (j < 0 || j >= n)
            return 1e9;

        if (i == n - 1)
            return matrix[i][j];

        int down      = solveRecursive(matrix, i + 1, j);
        int leftDiag  = solveRecursive(matrix, i + 1, j - 1);
        int rightDiag = solveRecursive(matrix, i + 1, j + 1);

        return matrix[i][j] + min(down, min(leftDiag, rightDiag));
    }


    /* ============================================================
       2. MEMOIZATION (TOP-DOWN DP)
       ============================================================ */
    // Time Complexity: O(n^2)
    // Space Complexity: O(n^2) + recursion stack

    int t[101][101];

    int solveMemo(vector<vector<int>>& matrix, int i, int j) {
        int n = matrix.size();

        if (j < 0 || j >= n)
            return 1e9;

        if (i == n - 1)
            return matrix[i][j];

        if (t[i][j] != -1)
            return t[i][j];

        int down      = solveMemo(matrix, i + 1, j);
        int leftDiag  = solveMemo(matrix, i + 1, j - 1);
        int rightDiag = solveMemo(matrix, i + 1, j + 1);

        return t[i][j] = matrix[i][j] + min(down, min(leftDiag, rightDiag));
    }


    /* ============================================================
       3. TABULATION (BOTTOM-UP DP)
       ============================================================ */
    // Time Complexity: O(n^2)
    // Space Complexity: O(n^2)

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> t(n, vector<int>(n, 0));

        // Base Case: First Row
        for (int j = 0; j < n; j++) {
            t[0][j] = matrix[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int up = t[i - 1][j];
                int leftDiag=1e9,rightDiag=1e9;
                if(j-1>=0) leftDiag=t[i-1][j-1];
                if(j+1<n) rightDiag=t[i-1][j+1];

                t[i][j] =
                    matrix[i][j] + min(up, min(leftDiag, rightDiag));
            }
        }

        // Result: Minimum value in the last row
        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            ans = min(ans, t[n - 1][j]);
        }

        return ans;
    }
};
