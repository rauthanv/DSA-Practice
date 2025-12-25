// Problem: Maximum Product Subarray

// Approach: Prefix & Suffix Product (Greedy)
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = INT_MIN;
        int prefix = 1, suffix = 1;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            prefix *= nums[i];
            suffix *= nums[n - i - 1];

            maxProd = max(maxProd, max(prefix, suffix));

            if (prefix == 0) prefix = 1;
            if (suffix == 0) suffix = 1;
        }
        return maxProd;
    }
};
