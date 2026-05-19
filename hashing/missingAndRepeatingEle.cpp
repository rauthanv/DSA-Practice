// Problem: Find Missing And Repeating Element

// Approach:
// 1. Use hashmap to count frequency.
// 2. Duplicate element is the one whose frequency > 1.
// 3. Compute expected sum of first n natural numbers.
// 4. Difference between expected sum and current sum
//    gives (missing - duplicate).
// 5. Find missing element.
//
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
  public:

    vector<int> findTwoElement(vector<int>& arr) {

        unordered_map<int,int> mp;

        long long currentSum = 0;
        int duplicate;

        // Count frequency and find duplicate
        for(auto num : arr) {

            mp[num]++;

            if(mp[num] > 1) {
                duplicate = num;
            }

            currentSum += num;
        }

        long long n = arr.size();

        // Sum of first n natural numbers
        long long expectedSum = n * (n + 1) / 2;

        // missing = duplicate + (expected - current)
        int missing = duplicate + (expectedSum - currentSum);

        return {duplicate, missing};
    }
};