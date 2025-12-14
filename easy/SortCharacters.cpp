// Problem: Sort a String (Lowercase Letters)

string sortString(string s) {
    string res;
    const int MAX_CHAR = 26;
    int charCount[MAX_CHAR] = {0};

    for (int i = 0; i < s.length(); i++) {
        charCount[s[i] - 'a']++;
    }
    for (int i = 0; i < MAX_CHAR; i++) {
        while (charCount[i]--) {
            res += char('a' + i);
        }
    }
    return res;
}
