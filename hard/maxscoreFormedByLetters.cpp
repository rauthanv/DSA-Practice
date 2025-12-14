// Problem: Max Score Words Formed by Letters
//
// Approach:
// Backtracking / Recursion


class Solution {
public:

    bool canTake(string word, vector<int> freq) {
        for (char c : word) {
            if (freq[c - 'a'] == 0)
                return false;
            freq[c - 'a']--;
        }
        return true;
    }

    // -----------------------------------------------------
    // Recursive function to calculate maximum score
    // -----------------------------------------------------
    int maxLen(vector<string>& words, vector<int>& freq,
               vector<int>& score, int idx) {

        if (idx == words.size())
            return 0;
        int notTake = maxLen(words, freq, score, idx + 1);

        int take = 0;
        int currScore = 0;

        if (canTake(words[idx], freq)) {
            for (char c : words[idx]) {
                freq[c - 'a']--;
                currScore += score[c - 'a'];
            }

            take = currScore + maxLen(words, freq, score, idx + 1);
            for (char c : words[idx])
                freq[c - 'a']++;
        }

        return max(take, notTake);
    }
    // -----------------------------------------------------
    // function
    // -----------------------------------------------------
    int maxScoreWords(vector<string>& words,
                      vector<char>& letters,
                      vector<int>& score) {

        vector<int> freq(26, 0);

        for (char c : letters)
            freq[c - 'a']++;

        return maxLen(words, freq, score, 0);
    }
};
