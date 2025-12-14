// Problem: Remove Duplicates from Sorted Array

// Approach:
// Two Pointer Technique

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int prev = 0;

        for (int nxt = 1; nxt < n; nxt++) {
            if (nums[nxt] != nums[prev]) {
                prev++;
                nums[prev] = nums[nxt];
            }
        }
        return prev + 1;
    }
};
