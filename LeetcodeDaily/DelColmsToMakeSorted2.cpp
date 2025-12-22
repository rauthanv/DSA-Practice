// Problem: Delete Columns to Make Sorted II
// LeetCode: https://leetcode.com/problems/delete-columns-to-make-sorted-ii/
//
// Approach: Greedy
// Time Complexity: O(n * m)
// Space Complexity: O(n)
//
// Intuition:
// - We process columns from left to right
// - Track which adjacent rows are already confirmed sorted
// - If a column breaks order for any unsorted pair → delete it
// - Otherwise, mark newly sorted row pairs



class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int ans = 0;

        vector<bool> sorted(n - 1, false);

        for (int col = 0; col < m; col++) {
            bool badOrder = false;

            for (int row = 0; row < n - 1; row++) {
                if (!sorted[row] && strs[row][col] > strs[row + 1][col]) {
                    badOrder = true;
                    break;
                }
            }

            if (badOrder) {
                ans++;
                continue;
            }

            for (int row = 0; row < n - 1; row++) {
                if (!sorted[row] && strs[row][col] < strs[row + 1][col]) {
                    sorted[row] = true;
                }
            }
        }
        return ans;
    }
};
