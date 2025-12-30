// Problem: Wildcard Matching
// Pattern Rules:
// '?' → matches exactly one character
// '*' → matches zero or more characters
//
// Approaches Included:
// 1. Recursion
// 2. Memoization 
// 3. Tabulation 

class Solution {
public:

    // -----------------------------------------------------
    // Recursion (Exponential)
    // -----------------------------------------------------
    bool recMatch(string &s, string &p, int n, int m) {

        if (n == 0 && m == 0) return true;
        if (m == 0 && n > 0) return false;
        if (n == 0 && m > 0) {
            for (int i = 0; i < m; i++)
                if (p[i] != '*') return false;
            return true;
        }

        if (s[n-1] == p[m-1] || p[m-1] == '?')
            return recMatch(s, p, n-1, m-1);

        if (p[m-1] == '*')
            return recMatch(s, p, n, m-1)     
                || recMatch(s, p, n-1, m);    

        return false;
    }


    // -----------------------------------------------------
    // 2️⃣ Memoization (Top-Down DP)
    // -----------------------------------------------------
    int t[2001][2001]; 

    bool memoMatch(string &s, string &p, int n, int m) {
        if (n == 0 && m == 0) return true;
        if (m == 0 && n > 0) return false;
        if (n == 0 && m > 0) {
            for (int i = 0; i < m; i++)
                if (p[i] != '*') return false;
            return true;
        }

        if (t[n][m] != -1) return t[n][m];

        if (s[n-1] == p[m-1] || p[m-1] == '?')
            return t[n][m] = memoMatch(s, p, n-1, m-1);

        if (p[m-1] == '*')
            return t[n][m] = memoMatch(s, p, n, m-1)
                          || memoMatch(s, p, n-1, m);

        return t[n][m] = false;
    }


    // -----------------------------------------------------
    // 3️⃣ Tabulation (Bottom-Up DP)
    // -----------------------------------------------------
    bool tabMatch(string s, string p) {

        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

        dp[0][0] = true;

        for (int j = 1; j <= m; j++) {
            if (p[j-1] == '*')
                dp[0][j] = dp[0][j-1];
            else
                dp[0][j] = false;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (s[i-1] == p[j-1] || p[j-1] == '?')
                    dp[i][j] = dp[i-1][j-1];

                else if (p[j-1] == '*')
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];       

                else
                    dp[i][j] = false;
            }
        }
        return dp[n][m];
    }


    // -----------------------------------------------------
    // function call
    // -----------------------------------------------------
    bool isMatch(string s, string p) {

        // Recursion
        // return recMatch(s, p, s.size(), p.size());

        // Memoization
        // memset(t, -1, sizeof(t));
        // return memoMatch(s, p, s.size(), p.size());

        // Tabulation
        return tabMatch(s, p);
    }
};
