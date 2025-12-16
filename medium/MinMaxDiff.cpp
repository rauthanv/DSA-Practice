// Problem: Minimize the Maximum Difference of P Pairs

// Approach:
// Binary Search on Answer + Greedy
//
// Idea:
// - Sort the array
// - Binary search on the maximum allowed difference
// - For a given maxDiff, greedily form pairs with difference <= maxDiff
// - If we can form at least p pairs → try smaller maxDiff


class Solution {
public:

    bool canFormPairs(vector<int>& nums, int p, int maxDiff) {
        int count = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] <= maxDiff) {
                count++;
                i++;   
            }
        }
        return count >= p;
    }
    
    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0) return 0;

        sort(nums.begin(), nums.end());

        int l = 0;
        int r = nums.back() - nums.front();
        int ans = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (canFormPairs(nums, p, mid)) {
                ans = mid;
                r = mid - 1;   
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
