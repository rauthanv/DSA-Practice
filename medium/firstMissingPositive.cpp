// Problem: First Missing Positive

// Approach 1: Brute Force (Using Extra Space)
// Time Complexity: O(n)
// Space Complexity: O(n)
//
// Approach 2: Optimized (Index Placement)
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:

    // ---------------- BRUTE FORCE ----------------
    int firstMissingPositiveBrute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> present(n + 1, false);

        for (int x : nums) {
            if (x >= 1 && x <= n)
                present[x] = true;
        }

        for (int i = 1; i <= n; i++) {
            if (!present[i])
                return i;
        }

        return n + 1;
    }

    // ---------------- OPTIMIZED ----------------
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            while (nums[i] >= 1 &&
                   nums[i] <= n &&
                   nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }

        return n + 1;
    }
};
