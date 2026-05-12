// Problem: Subarray with Given Sum

// Method 1: Sliding Window
// Approach:
// 1. Use two pointers to maintain a window.
// 2. Expand window by adding right element.
// 3. Shrink window while sum > target.
// 4. If sum == target, return indices.
//
// Note:
// Works only when all array elements are positive.
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
  public:

    vector<int> subarraySumSlidingWindow(vector<int> &arr, int target) {

        int l = 0;
        int sum = 0;

        for(int r = 0; r < arr.size(); r++) {

            sum += arr[r];

            while(sum > target && l <= r) {
                sum -= arr[l];
                l++;
            }

            if(sum == target) {
                return {l + 1, r + 1};
            }
        }

        return {-1};
    }


    // =====================================================
    // Method 2: Prefix Sum + HashMap
    // Approach:
    // 1. Store prefix sums in hashmap.
    // 2. If (prefixSum - target) exists,
    //    then subarray with target sum exists.
    //
    // Works for:
    // - positive numbers
    // - negative numbers
    // - mixed arrays
    //
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    // =====================================================

    vector<int> subarraySumPrefix(vector<int> &arr, int target) {

        unordered_map<int, int> mp;

        int prefixSum = 0;

        for(int i = 0; i < arr.size(); i++) {

            prefixSum += arr[i];

            // Subarray from index 0
            if(prefixSum == target) {
                return {1, i + 1};
            }

            // Check previous prefix sum
            if(mp.find(prefixSum - target) != mp.end()) {

                return {mp[prefixSum - target] + 2, i + 1};
            }

            // Store prefix sum index
            mp[prefixSum] = i;
        }

        return {-1};
    }
};