// Problem: Frequency of Elements

// Approach:
// 1. Use unordered_map to store frequency of elements.
// 2. Traverse array and count occurrences.
// 3. Store answer in 2D vector.
//
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
  public:

    vector<vector<int>> countFreq(vector<int>& arr) {

        unordered_map<int, int> um;
        
        for(int num : arr) {
            um[num]++;
        }

        vector<vector<int>> ans;

        for(auto it : um) {
            ans.push_back({it.first, it.second});
        }

        return ans;
    }
};