// Problem: Move Zeroes

// Approach:
// 1. Maintain a pointer 'z' for the position where
//    next non-zero element should be placed.
// 2. Traverse array.
// 3. If current element is non-zero:
//      - swap it with nums[z]
//      - move z forward
// 4. All zeroes automatically shift to the end.
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:

    void moveZeroes(vector<int>& nums) {

        int z = 0;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] != 0) {

                swap(nums[i], nums[z]);
                z++;
            }
        }
    }
};