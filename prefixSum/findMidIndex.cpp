// Problem: Find the Middle Index in Array

class Solution {
public:

    // =====================================================
    // Method 1: Brute Force
    // Approach:
    // 1. For every index:
    //      - calculate left sum
    //      - calculate right sum
    // 2. If both sums are equal,
    //    return the index.
    //
    // Time Complexity: O(n²)
    // Space Complexity: O(1)
    // =====================================================

    int findMiddleIndexBrute(vector<int>& nums) {

        for(int i = 0; i < nums.size(); i++) {

            int leftSum = 0;
            int rightSum = 0;

            for(int j = 0; j < i; j++) {
                leftSum += nums[j];
            }

            for(int j = i + 1; j < nums.size(); j++) {
                rightSum += nums[j];
            }

            if(leftSum == rightSum) {
                return i;
            }
        }

        return -1;
    }


    // =====================================================
    // Method 2: Prefix Sum (Optimal)
    // Approach:
    // 1. Compute total sum of array.
    // 2. Maintain running left sum.
    // 3. Calculate right sum using:
    //
    //    totalSum - leftSum - nums[i]
    //
    // 4. If left sum equals right sum,
    //    return current index.
    //
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    // =====================================================

    int findMiddleIndex(vector<int>& nums) {

        int totalSum = 0;

        for(int num : nums) {
            totalSum += num;
        }

        int leftSum = 0;

        for(int i = 0; i < nums.size(); i++) {

            int rightSum = totalSum - leftSum - nums[i];

            if(leftSum == rightSum) {
                return i;
            }

            leftSum += nums[i];
        }

        return -1;
    }
};