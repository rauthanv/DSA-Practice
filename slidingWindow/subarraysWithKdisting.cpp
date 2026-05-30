// Problem: Subarrays with K Different Integers

class Solution {
public:

    // =====================================================
    // Helper Function:
    // Count subarrays having AT MOST k distinct integers.
    //
    // Approach:
    // 1. Use Variable Size Sliding Window.
    // 2. Maintain frequency map.
    // 3. Shrink window if distinct elements exceed k.
    // 4. Number of valid subarrays ending at r:
    //      (r - l + 1)
    //
    // Time Complexity: O(n)
    // Space Complexity: O(k)
    // =====================================================

    int countSubarrays(vector<int>& nums, int k) {

        unordered_map<int,int> freq;

        int l = 0;
        int r = 0;

        int count = 0;

        while(r < nums.size()) {

            freq[nums[r]]++;

            while(freq.size() > k) {

                freq[nums[l]]--;

                if(freq[nums[l]] == 0) {
                    freq.erase(nums[l]);
                }

                l++;
            }

            count += (r - l + 1);

            r++;
        }

        return count;
    }


    // =====================================================
    // Method: At Most K Trick
    //
    // Exactly K Distinct
    // = At Most K Distinct
    // - At Most (K-1) Distinct
    //
    // Time Complexity: O(n)
    // Space Complexity: O(k)
    // =====================================================

    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return countSubarrays(nums, k)
             - countSubarrays(nums, k - 1);
    }
};