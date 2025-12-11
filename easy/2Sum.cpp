// Problem: Two Sum

// Approaches Included:
// 1. Brute Force (O(n^2))
// 2. Optimized HashMap Solution (O(n))


class Solution {
public:

    // -----------------------------------------------------
    // 1️⃣ Brute Force — O(n²)
    // -----------------------------------------------------
    
    
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target)
                    return {i, j};
            }
        }
        return {};
    }


    // -----------------------------------------------------
    // 2️⃣ Optimized — HashMap (O(n))
    // -----------------------------------------------------

    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;  // value → index

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (mp.count(diff)) {
                return {mp[diff], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};
