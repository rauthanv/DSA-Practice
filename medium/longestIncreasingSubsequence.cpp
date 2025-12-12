// Problem: Longest Increasing Subsequence (LIS)
//
// Approaches Included:
// 1. Pure Recursion  — O(2^n)
// 2. Memoization     — O(n²)
// 3. Tabulation DP   — O(n²)
// 4. Optimized O(n log n) using Binary Search

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // -----------------------------------------------------
    // 1️⃣ Pure Recursion (Exponential)
    // prev = index of previous element included in LIS
    // -----------------------------------------------------
    int lisRec(vector<int>& nums, int n, int prev) {
        if (n == 0) return 0;

        int notTake = lisRec(nums, n - 1, prev);
        int take = 0;

        if (prev == -1 || nums[n - 1] < nums[prev])
            take = 1 + lisRec(nums, n - 1, n - 1);

        return max(take, notTake);
    }


    // -----------------------------------------------------
    // 2️⃣ Memoization — Top-Down DP (O(n²))
    // dp[n][prev+1] → LIS of nums[0…n-1] with previous index = prev
    // -----------------------------------------------------
    int t[2501][2501];

    int lisMemo(vector<int>& nums, int n, int prev) {
        if (n == 0) return 0;

        if (t[n][prev + 1] != -1) return t[n][prev + 1];

        int notTake = lisMemo(nums, n - 1, prev);
        int take = 0;

        if (prev == -1 || nums[n - 1] < nums[prev])
            take = 1 + lisMemo(nums, n - 1, n - 1);

        return t[n][prev + 1] = max(take, notTake);
    }


    // -----------------------------------------------------
    // 3️⃣ Tabulation DP — O(n²)
    // Classic DP based on dp[i] = LIS ending at index i
    // -----------------------------------------------------
    int lisTabulation(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n, 1);
        int ans = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    t[i] = max(t[i], 1 + t[j]);
                }
            }
            ans = max(ans, t[i]);
        }

        return ans;
    }


    // -----------------------------------------------------
    // 4️⃣ Optimized LIS — O(n log n)
    // Using "tails" array + binary search 
    // -----------------------------------------------------
    int lisOptimized(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > temp.back()) {
                temp.push_back(nums[i]);          
            } 
            else {
                int idx = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[idx] = nums[i];             
            }
        }

        return temp.size();
    }


    // -----------------------------------------------------
    // function call 
    // -----------------------------------------------------
    int lengthOfLIS(vector<int>& nums) {

        // 1️⃣ Pure Recursion
        // return lisRec(nums, nums.size(), -1);

        // 2️⃣ Memoization
        // memset(t, -1, sizeof(t));
        // return lisMemo(nums, nums.size(), -1);

        // 3️⃣ Tabulation O(n²)
        // return lisTabulation(nums);

        // 4️⃣ Optimized O(n log n)
        return lisOptimized(nums);
    }
};
