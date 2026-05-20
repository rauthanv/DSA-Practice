// Problem: Sort Colors

class Solution {
public:

    // =====================================================
    // Method 1: Bubble Sort
    // Approach:
    // 1. Repeatedly compare adjacent elements.
    // 2. Swap if current element is greater.
    // 3. Stop early if no swap occurs.
    //
    // Time Complexity: O(n²)
    // Space Complexity: O(1)
    // =====================================================

    void sortColorsBubble(vector<int>& nums) {

        bool swapped;

        for(int i = 0; i < nums.size(); i++) {
            swapped = false;

            for(int j = 0; j < nums.size()-i-1; j++) {
                if(nums[j] > nums[j+1]) {
                    swap(nums[j], nums[j+1]);
                    swapped = true;
                }
            }

            if(!swapped)
                break;
        }
    }


    // =====================================================
    // Method 2: Dutch National Flag Algorithm
    // Approach:
    // 1. Maintain three pointers:
    //      l → next position for 0
    //      m → current element
    //      h → next position for 2
    //
    // Rules:
    // nums[m] == 0:
    //      swap with l
    //      l++, m++
    //
    // nums[m] == 1:
    //      m++
    //
    // nums[m] == 2:
    //      swap with h
    //      h--
    //
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    // =====================================================

    void sortColors(vector<int>& nums) {

        int l = 0;
        int m = 0;
        int h = nums.size()-1;

        while(m <= h) {

            if(nums[m] == 0) {
                swap(nums[m], nums[l]);
                l++;
                m++;
            }

            else if(nums[m] == 1) m++;

            else {
                swap(nums[m], nums[h]);
                h--;
            }
        }
    }
};