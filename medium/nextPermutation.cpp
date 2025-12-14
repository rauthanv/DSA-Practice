// Problem: Next Permutation

// Approach:
// Two Pointer
//
// Idea:
// 1. Find the first index (idx1) from right where nums[i-1] < nums[i]
// 2. If no such index exists → array is the largest permutation
//    → reverse the whole array
// 3. Otherwise, find index (idx2) from right such that nums[idx2] > nums[idx1]
// 4. Swap nums[idx1] and nums[idx2]
// 5. Reverse the subarray after idx1 to get the next smallest permutation

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void swap(vector<int>& nums, int id1, int id2) {
        int temp = nums[id1];
        nums[id1] = nums[id2];
        nums[id2] = temp;
    }

    void nextPermutation(vector<int>& nums) {
        int idx1 = -1;
        int idx2 = -1;

        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i - 1] < nums[i]) {
                idx1 = i - 1;
                break;
            }
        }
        if (idx1 == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int i = nums.size() - 1; i > idx1; i--) {
            if (nums[i] > nums[idx1]) {
                idx2 = i;
                break;
            }
        }
        swap(nums, idx1, idx2);
        reverse(nums.begin() + idx1 + 1, nums.end());
    }
};
