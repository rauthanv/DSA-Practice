// Problem: Convert to Base -2

class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) return "0";

        string s;

        while (n != 0) {
            int rem = n % -2;
            n /= -2;
            
            if (rem < 0) {
                rem += 2;
                n++;
            }

            s.push_back(rem + '0');
        }

        reverse(s.begin(), s.end());
        return s;
    }
};
