// Problem: Longest Common Subsequence (LCS)

// Approaches Included:
// 1. Recursion (Exponential)
// 2. Memoization 
// 3. Tabulation 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // -----------------------------------------------------
    // 1️⃣ Recursion
    // -----------------------------------------------------
    int lcsRec(string &text1, string &text2, int n, int m) {
        if (n == 0 || m == 0) return 0;

        if (text1[n - 1] == text2[m - 1])
            return 1 + lcsRec(text1, text2, n - 1, m - 1);

        return max(
            lcsRec(text1, text2, n, m - 1),
            lcsRec(text1, text2, n - 1, m)
        );
    }


    // -----------------------------------------------------
    // 2️⃣ Memoization
    // -----------------------------------------------------
    int t[1001][1001];

    int lcsMemo(string &text1, string &text2, int n, int m) {
        if (n == 0 || m == 0) return t[n][m] = 0;

        if (t[n][m] != -1) return t[n][m];

        if (text1[n - 1] == text2[m - 1])
            return t[n][m] = 1 + lcsMemo(text1, text2, n - 1, m - 1);

        return t[n][m] = max(
            lcsMemo(text1, text2, n, m - 1),
            lcsMemo(text1, text2, n - 1, m)
        );
    }


    // -----------------------------------------------------
    // 3️⃣ Tabulation 
    // -----------------------------------------------------
    int lcsTabu(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        int dp[n + 1][m + 1];

        // Base initialization
        for (int i = 0; i <= n; i++) dp[i][0] = 0;
        for (int j = 0; j <= m; j++) dp[0][j] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }


    // -----------------------------------------------------
    // function —
    // -----------------------------------------------------
    int longestCommonSubsequence(string text1, string text2) {

        // Recursion
        // return lcsRec(text1, text2, text1.size(), text2.size());

        // Memoization
        // memset(t, -1, sizeof(t));
        // return lcsMemo(text1, text2, text1.size(), text2.size());

        //Tabulation
        return lcsTabu(text1, text2);
    }
};
