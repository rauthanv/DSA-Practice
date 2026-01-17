/*
Problem:
Longest Strictly increasing or decreasing Subarray

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int incre = 1, decre = 1;
        int longestS = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                incre++;
                decre = 1;
            } 
            else if (nums[i] < nums[i - 1]) {
                decre++;
                incre = 1;
            } 
            else {
                incre = decre = 1;
            }
            longestS = max(longestS, max(incre, decre));
        }
        return longestS;
    }
};
