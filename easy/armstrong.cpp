// Problem: Armstrong Number

class Solution {
public:
    bool armstrongNumber(int n) {
        int num = n;
        int sum = 0;

        while (n > 0) {
            int d = n % 10;
            sum += (d * d * d);
            n = n / 10;
        }

        return sum == num;
    }
};
