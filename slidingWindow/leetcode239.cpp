// Problem: Sliding Window Maximum

class Solution {
public:

    // =====================================================
    // Method 1: Brute Force
    // Approach:
    // 1. For every window of size k.
    // 2. Find maximum element by traversing window.
    // 3. Store result.
    //
    // Time Complexity: O(n * k)
    // Space Complexity: O(1)
    // =====================================================

    vector<int> maxSlidingWindowBrute(vector<int>& nums, int k) {

        vector<int> ans;

        for(int i = 0; i <= nums.size()-k; i++) {

            int maxi = nums[i];

            for(int j = i; j < i+k; j++) {
                maxi = max(maxi, nums[j]);
            }

            ans.push_back(maxi);
        }

        return ans;
    }


    // =====================================================
    // Method 2: Monotonic Deque (Optimal)
    // Approach:
    // 1. Store indices in deque.
    // 2. Maintain decreasing order of values.
    // 3. Remove smaller elements from back.
    // 4. Remove out-of-window elements from front.
    // 5. Front always stores maximum element.
    //
    // Time Complexity: O(n)
    // Space Complexity: O(k)
    // =====================================================

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> dq;
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {

            // Remove smaller elements
            while(!dq.empty() &&
                  nums[i] > nums[dq.back()]) {

                dq.pop_back();
            }

            dq.push_back(i);

            // Remove out-of-window index
            if(dq.front() <= i-k) {
                dq.pop_front();
            }

            // Window formed
            if(i >= k-1) {
                ans.push_back(
                    nums[dq.front()]
                );
            }
        }

        return ans;
    }
};