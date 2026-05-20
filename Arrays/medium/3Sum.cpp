// Problem: 3Sum

// Approach:
// 1. Sort the array.
// 2. Fix one element at index i.
// 3. Use two pointers:
//      - j = i + 1
//      - k = last index
// 4. Find sum of three elements:
//      nums[i] + nums[j] + nums[k]
// 5. If sum < 0 → increase j
//    If sum > 0 → decrease k
//    Else store triplet.
// 6. Skip duplicates to avoid repeated triplets.
//
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// (excluding answer vector)

class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++) {

            // Skip duplicate first elements
            if(i != 0 && nums[i] == nums[i-1])
                continue;

            int j = i + 1;
            int k = nums.size() - 1;

            while(j < k) {

                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0) {
                    j++;
                }
                else if(sum > 0) {
                    k--;
                }
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    // Skip duplicates
                    while(j < k && nums[j] == nums[j-1]) j++;
                    while(j < k && nums[k] == nums[k+1]) k--;
                }
            }
        }

        return ans;
    }
};