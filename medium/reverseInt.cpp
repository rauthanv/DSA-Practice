// Problem: Reverse Integer

// Approach:
// - Extract digits from the end using x % 10.
// - Build the reversed number: rev = rev * 10 + digit.
// - Before updating rev, check if rev would overflow 32-bit signed integer range.
// - If overflow is detected, return 0.

class Solution {
public:
    int reverse(int x) {
        int rev = 0;

        while (x != 0) {
            int digit = x % 10;
            // If rev * 10 would exceed INT_MAX or INT_MIN, return 0.
            if (rev > INT_MAX / 10 || rev < INT_MIN / 10)
                return 0;

            rev = rev * 10 + digit;
            x /= 10;
        }

        return rev;
    }
};
