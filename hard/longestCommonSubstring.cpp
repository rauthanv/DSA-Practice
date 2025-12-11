// Problem: Longest Common Substring

// Approach: Dp (Tabulation)
//
// dp[i][j] represents:
// → length of the longest common substring ending at s1[i-1] and s2[j-1]
//
// Transition:
// If characters match:
//      dp[i][j] = 1 + dp[i-1][j-1]
// Else:
//      dp[i][j] = 0
//
// Track max length during the process.

class Solution {
public:
    int longestCommonSubstr(string &s1, string &s2) {
        int n = s1.size();
        int m = s2.size();
        int len = 0;              

        int t[n + 1][m + 1];

        for (int i = 0; i <= n; i++) t[i][0] = 0;
        for (int j = 0; j <= m; j++) t[0][j] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (s1[i - 1] == s2[j - 1]) {
                    t[i][j] = 1 + t[i - 1][j - 1];
                    len = max(len, t[i][j]); 
                } 
                else {
                    t[i][j] = 0;
                }
            }
        }

        return len;
    }
};
