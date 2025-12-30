// Problem: Longest Palindromic Subsequence

// Approach:
// Dynamic Programming (LCS based)
//
// Idea:
// - A palindrome reads the same forward and backward
// - Reverse the string and find the Longest Common Subsequence (LCS)
// - LCS(s, reverse(s)) = Longest Palindromic Subsequence


class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        int t[n + 1][m + 1];

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0)
                    t[i][j] = 0;
                else if (text1[i - 1] == text2[j - 1])
                    t[i][j] = 1 + t[i - 1][j - 1];
                else
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
        return t[n][m];
    }

    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        return longestCommonSubsequence(s, rev);
    }
};
