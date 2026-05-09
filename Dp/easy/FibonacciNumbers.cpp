// Problem: Print First N Fibonacci Numbers

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    // ---------------------------------------------------
    // Method 1: Iterative Dynamic Programming
    // Approach:
    // 1. Store first two Fibonacci numbers.
    // 2. Generate remaining numbers iteratively.
    //
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    // ---------------------------------------------------

    vector<int> fibonacciIterative(int n) {

        if(n == 1) return {0};

        vector<int> fib(n);

        fib[0] = 0;
        fib[1] = 1;

        for(int i = 2; i < n; i++) {
            fib[i] = fib[i-1] + fib[i-2];
        }

        return fib;
    }



    // ---------------------------------------------------
    // Method 3: Simple Recursion
    // Approach:
    // 1. Use recursive formula:
    //    fib(n) = fib(n-1) + fib(n-2)
    //
    // Time Complexity: O(2^n)
    // Space Complexity: O(n)
    // ---------------------------------------------------

    int fibRecursive(int n) {

        if(n == 0) return 0;
        if(n == 1) return 1;

        return fibRecursive(n-1) + fibRecursive(n-2);
    }

    vector<int> fibonacciRecursive(int n) {

        vector<int> ans;

        for(int i = 0; i < n; i++) {
            ans.push_back(fibRecursive(i));
        }

        return ans;
    }


    // ---------------------------------------------------
    // Method 4: Recursion + Memoization
    // Approach:
    // 1. Store already computed Fibonacci numbers.
    // 2. Avoid repeated recursive calls.
    //
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    // ---------------------------------------------------

    int fibMemo(int n, vector<int>& dp) {

        if(n <= 1) return n;

        if(dp[n] != -1) return dp[n];

        return dp[n] = fibMemo(n-1, dp) + fibMemo(n-2, dp);
    }

    vector<int> fibonacciMemoization(int n) {

        vector<int> dp(n + 1, -1);
        vector<int> ans;

        for(int i = 0; i < n; i++) {
            ans.push_back(fibMemo(i, dp));
        }

        return ans;
    }
};