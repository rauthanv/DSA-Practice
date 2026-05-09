// Problem: Reverse a String

// Approach 1: Two Pointer Method()
// 1. Use two pointers:
//    - one from the beginning
//    - one from the end
// 2. Swap characters until both pointers meet.

// Approach 2: STL reverse()
// 1. Use built-in reverse() function from algorithm library.
// 2. It reverses the string directly.
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <algorithm>
using namespace std;

class Solution {
  public:

    // Method 1: Two Pointer Approach
    string reverseString(string& s) {
        int i = 0;
        int j = s.size() - 1;

        while(i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }

    // Method 2: STL Approach
    string reverseStringSTL(string& s) {
        reverse(s.begin(), s.end());
        return s;
    }
};