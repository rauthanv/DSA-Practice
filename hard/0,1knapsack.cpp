#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
    // ------------------------------------
    // 1️⃣ Recursive Solution (Exponential: 2^n)
    // ------------------------------------
    int knapsackRecursive(int W, vector<int>& val, vector<int>& wt, int n) {
        if (n == 0 || W == 0) return 0;

        if (wt[n-1] <= W) {
            return max(
                val[n-1] + knapsackRecursive(W - wt[n-1], val, wt, n-1),
                knapsackRecursive(W, val, wt, n-1)
            );
        }

        return knapsackRecursive(W, val, wt, n-1);
    }

    int knapsackRecursive(int W, vector<int>& val, vector<int>& wt) {
        return knapsackRecursive(W, val, wt, val.size());
    }

    // ------------------------------------
    // 2️⃣ Memoization (Top-Down DP) - O(n * W)
    // ------------------------------------
    int t[1001][1001];

    int knapsackt(int W, vector<int>& val, vector<int>& wt, int n) {
        if (n == 0 || W == 0) return 0;

        if (t[n][W] != -1) return t[n][W];

        if (wt[n-1] <= W) {
            return t[n][W] = max(
                val[n-1] + knapsackt(W - wt[n-1], val, wt, n-1),
                knapsackt(W, val, wt, n-1)
            );
        }

        return t[n][W] = knapsackt(W, val, wt, n-1);
    }

    int knapsackt(int W, vector<int>& val, vector<int>& wt) {
        memset(t, -1, sizeof(t));
        return knapsackMemo(W, val, wt, val.size());
    }

    // ------------------------------------
    // 3️⃣ Tabulation (Bottom-Up DP) - O(n * W)
    // ------------------------------------
    int knapsackTabulation(int W, vector<int>& val, vector<int>& wt) {
        int n = val.size();
        vector<vector<int>> t(n+1, vector<int>(W+1, 0));

        for (int i = 1; i <= n; i++) {
            for (int w = 1; w <= W; w++) {
                if (wt[i-1] <= w) {
                    t[i][w] = max(
                        val[i-1] + t[i-1][w - wt[i-1]],
                        t[i-1][w]
                    );
                } else {
                    t[i][w] = t[i-1][w];
                }
            }
        }

        return dp[n][W];
    }
};
