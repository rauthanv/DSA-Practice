// Problem: Allocate Minimum Number of Pages

// Approach:
// apply Binary Search on the answer (minimum possible maximum pages).
// For a guessed limit `mid`, we check if allocation to `k` students is possible
// such that no student reads more than `mid` pages consecutively.

// If allocation is possible -> try smaller limit (high = mid - 1)
// Else -> increase the limit (low = mid + 1)

class Solution {
public:
    
    // Helper function: checks if we can allocate books
    bool canAllocate(vector<int>& arr, int k, int limit){
        int students = 1, pages = 0;
        
        for(int a : arr){
            if(pages + a > limit){
                students++;
                pages = a;
                if(students > k) return false;
            } else {
                pages += a;
            }
        }
        return true;
    }

    int findPages(vector<int> &arr, int k) {
        if(arr.size() < k) return -1;

        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int res = high;
        
        while(low <= high){
            int mid = (low + high) / 2;
            
            if(canAllocate(arr, k, mid)){
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return res;
    }
};
