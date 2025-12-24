// Problem: Subarray Sum Equals K

// Approach 1: Brute Force
// Approach 2: Prefix Sum + Hash Map (Optimized)


class Solution {
public:

    // -------------------------------
    // Approach 1: Brute Force
    // Time: O(n^2)
    // Space: O(1)
    // -------------------------------
    
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (sum == k)
                    count++;
            }
        }
        return count;
    }
    

    // -------------------------------
    // Approach 2: Prefix Sum + HashMap
    // Time: O(n)
    // Space: O(n)
    // -------------------------------
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1;   // Base case

        int sum = 0;
        int total = 0;

        for (int num : nums) {
            sum += num;

            int diff = sum - k;
            if (prefixSumCount.count(diff)) {
                total += prefixSumCount[diff];
            }

            prefixSumCount[sum]++;
        }
        return total;
    }
};
