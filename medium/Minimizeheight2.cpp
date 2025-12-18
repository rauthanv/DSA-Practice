// Problem: Minimize the Heights II
// GFG: https://www.geeksforgeeks.org/problems/minimize-the-heights3351/1
//
// Approach:
// Greedy + Sorting


class Solution {
public:
    int getMinDiff(vector<int> &arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int ans = arr[n - 1] - arr[0];

        for (int i = 1; i < n; i++) {
            int largest = max(arr[n - 1] - k, arr[i - 1] + k);
            int smallest = min(arr[0] + k, arr[i] - k);

            if (smallest < 0) continue;

            ans = min(ans, largest - smallest);
        }
        return ans;
    }
};
