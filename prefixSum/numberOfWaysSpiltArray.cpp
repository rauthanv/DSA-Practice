// Problem: Number of Ways to Split Array

class Solution {
public:

    // =====================================================
    // Method 1: Brute Force
    // Approach:
    // 1. Try every possible split position.
    // 2. Calculate left sum and right sum.
    // 3. If leftSum >= rightSum,
    //    increment answer.
    //
    // Time Complexity: O(n²)
    // Space Complexity: O(1)
    // =====================================================

    int waysToSplitArrayBrute(vector<int>& nums) {

        int ways = 0;

        for(int i = 0; i < nums.size()-1; i++) {

            long long leftSum = 0;
            long long rightSum = 0;

            for(int j = 0; j <= i; j++) {
                leftSum += nums[j];
            }

            for(int j = i+1; j < nums.size(); j++) {
                rightSum += nums[j];
            }

            if(leftSum >= rightSum) {
                ways++;
            }
        }

        return ways;
    }


    // =====================================================
    // Method 2: Prefix Sum / Running Sum (Optimal)
    // Approach:
    // 1. Compute total array sum.
    // 2. Maintain running left sum.
    // 3. Right sum can be calculated as:
    //
    //      totalSum - leftSum
    //
    // 4. Count valid splits where:
    //
    //      leftSum >= rightSum
    //
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    // =====================================================

    int waysToSplitArray(vector<int>& nums) {

        int ways = 0;

        long long totalSum = 0;

        for(int num : nums) {
            totalSum += num;
        }

        long long leftSum = 0;

        for(int i = 0; i < nums.size()-1; i++) {

            leftSum += nums[i];

            long long rightSum = totalSum - leftSum;

            if(leftSum >= rightSum) {
                ways++;
            }
        }

        return ways;
    }
};