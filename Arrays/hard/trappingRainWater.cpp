// Problem: Trapping Rain Water

class Solution {
public:

    // =====================================================
    // Method 1: Highest Bar Split Approach
    // Approach:
    // 1. Find the tallest bar index.
    // 2. Traverse left side:
    //      maintain left maximum.
    // 3. Traverse right side:
    //      maintain right maximum.
    // 4. Water at each index:
    //      maxHeight - currentHeight
    //
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    // =====================================================

    int trapSplit(vector<int>& height) {

        int totalWater = 0;
        int maxHeight = 0;
        int idx = 0;

        // Find tallest bar
        for(int i = 0; i < height.size(); i++) {
            if(maxHeight < height[i]) {
                maxHeight = height[i];
                idx = i;
            }
        }

        int lmax = 0;

        // Traverse left side
        for(int i = 1; i <= idx; i++) {
            lmax = max(lmax, height[i-1]);
            if(lmax > height[i]) {
                totalWater += lmax - height[i];
            }
        }

        int rmax = 0;

        // Traverse right side
        for(int i = height.size()-2; i > idx; i--) {
            rmax = max(rmax, height[i+1]);
            if(rmax > height[i]) {
                totalWater += rmax - height[i];
            }
        }

        return totalWater;
    }


    // =====================================================
    // Method 2: Two Pointer (Optimal)
    // Approach:
    // 1. Maintain left and right pointers.
    // 2. Keep track of:
    //      lmax = maximum on left
    //      rmax = maximum on right
    // 3. Smaller side determines water.
    // 4. Add trapped water at each step.
    //
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    // =====================================================

    int trap(vector<int>& height) {

        int l = 0;
        int r = height.size()-1;

        int lmax = 0;
        int rmax = 0;
        int totalWater = 0;

        while(l < r) {

            if(height[l] <= height[r]) {
                lmax = max(lmax, height[l]);
                totalWater += lmax - height[l];
                l++;
            }

            else {
                rmax = max(rmax, height[r]);
                totalWater += rmax - height[r];
                r--;
            }
        }

        return totalWater;
    }
};