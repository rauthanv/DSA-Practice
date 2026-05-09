// Problem: Count Digits

// Approach:
// 1. Keep dividing the number by 10.
// 2. Count how many times division happens until number becomes 0.
// 3. The count represents total digits.

class Solution {
public:
    int countDigits(int n) {
        // Edge case for 0
        if(n == 0) return 1;

        int ans = 0;

        while(n != 0) {
            ans++;
            n /= 10;
        }

        return ans;
    }
};