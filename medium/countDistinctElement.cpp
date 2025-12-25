// Problem: Count Distinct Elements in Every Window

// Approach: Sliding Window + Hash Map
// Time Complexity: O(n)
// Space Complexity: O(k)

class Solution {
public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        unordered_map<int, int> freq;
        vector<int> ans;

        for (int i = 0; i < arr.size(); i++) {

            freq[arr[i]]++;

            if (i >= k) {
                freq[arr[i - k]]--;
                if (freq[arr[i - k]] == 0)
                    freq.erase(arr[i - k]);
            }

            if (i >= k - 1)
                ans.push_back(freq.size());
        }
        return ans;
    }
};
