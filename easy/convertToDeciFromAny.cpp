// Problem: Decimal Equivalent of a Number in Given Base


class Solution {
public:
    int decimalEquivalent(string N, int b) {
        long long result = 0;

        for (char c : N) {
            int value;

            if (c >= '0' && c <= '9')
                value = c - '0';
            else if (c >= 'A' && c <= 'Z')
                value = c - 'A' + 10;
            else
                return -1;
                
            if (value >= b)
                return -1;

            result = result * b + value;
        }
        return result;
    }
};
