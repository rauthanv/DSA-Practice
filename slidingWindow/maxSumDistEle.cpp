// Problem: Maximum Sum of Distinct Subarrays With Length K

// Approach:
// 1. Use Sliding Window of size k.
// 2. Maintain:
//      - current window sum
//      - frequency map for distinct elements
// 3. Expand window using right pointer.
// 4. When window size becomes k:
//      - if frequency map size == k,
//        all elements are distinct
//      - update maximum sum
// 5. Remove left element and shrink window.
//
// Time Complexity: O(n)
// Space Complexity: O(k)

class Solution {
public:

    long long maximumSubarraySum(vector<int>& nums, int k) {

        int l = 0;
        int r = 0;

        long long sum = 0;
        long long maxSum = 0;

        unordered_map<int,int> freq;

        while(r < nums.size()) {
            sum += nums[r];
            freq[nums[r]]++;

            // Window size reached k
            if(r - l + 1 == k) {
                // all elements distinct
                if(freq.size() == k) {
                    maxSum = max(maxSum, sum);
                }

                // Remove left element
                sum -= nums[l];
                freq[nums[l]]--;

                if(freq[nums[l]] == 0) {
                    freq.erase(nums[l]);
                }
                l++;
            }
            r++;
        }
        return maxSum;
    }
};