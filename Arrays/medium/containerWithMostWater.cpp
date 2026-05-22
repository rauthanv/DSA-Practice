// Problem: Container With Most Water

class Solution {
public:

    // =====================================================
    // Method 1: Brute Force
    // Approach:
    // 1. Try every pair of lines.
// 2. Width = j - i
// 3. Height = min(height[i], height[j])
// 4. Area = width × height
// 5. Store maximum area
//
// Time Complexity: O(n²)
// Space Complexity: O(1)
    // =====================================================

    int maxAreaBrute(vector<int>& height) {

        int ans = 0;

        for(int i = 0; i < height.size(); i++) {
            for(int j = i + 1; j < height.size(); j++) {

                int width = j - i;
                int h = min(height[i], height[j]);
                ans = max(ans, width * h);
            }
        }
        return ans;
    }


    // =====================================================
    // Method 2: Two Pointers (Optimal)
    // Approach:
    // 1. Place one pointer at beginning
    //    and one at end.
    // 2. Area depends on:
    //      width × smaller height
    // 3. Move smaller height pointer
    //    because larger one cannot help.
    // 4. Keep track of maximum area.
    //
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    // =====================================================

    int maxArea(vector<int>& height) {

        int l = 0;
        int r = height.size()-1;
        int maxArea = 0;

        while(l < r) {

            if(height[l] > height[r]) {
                maxArea = max(maxArea,height[r] * (r-l));
                r--;
            }
            else {
                maxArea = max(maxArea,height[l] * (r-l));
                l++;
            }
        }
        return maxArea;
    }
};