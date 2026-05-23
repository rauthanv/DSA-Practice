// Problem: Subarray Product Less Than K

class Solution {
public:

    // =====================================================
    // Method 1: Brute Force
    // Approach:
    // 1. Generate all possible subarrays.
    // 2. Keep multiplying elements.
    // 3. If product < k:
    //      increment count
    // 4. Break early if product >= k.
    //
    // Time Complexity: O(n²)
    // Space Complexity: O(1)
    // =====================================================

    int numSubarrayProductBrute(vector<int>& nums, int k) {

        int count = 0;

        for(int i = 0; i < nums.size(); i++) {
            long long product = 1;

            for(int j = i; j < nums.size(); j++) {
                product *= nums[j];

                if(product < k)
                    count++;
                else
                    break;
            }
        }
        return count;
    }


    // =====================================================
    // Method 2: Sliding Window (Optimal)
    // Approach:
    // 1. Expand right pointer.
    // 2. Maintain current product.
    // 3. Shrink window while product >= k.
    // 4. Number of valid subarrays ending at r:
    //      (r-l+1)
    //
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    // =====================================================

    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        if(k <= 1)
            return 0;

        int l = 0;
        int count = 0;
        long long product = 1;

        for(int r = 0; r < nums.size(); r++) {
            
          product *= nums[r];
            while(product >= k) {
                product /= nums[l];
                l++;
            }
            count += (r - l + 1);
        }
        return count;
    }
};