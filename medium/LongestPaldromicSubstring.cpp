class Solution {
public:
    string longestPalindrome(string s) {
        int start=0;
        int maxLen=1;

        for(int i =0;i<s.size()-1;i++){
            int l=i-1;
            int r=i+1;
            //odd len
            while(l>=0 && r<s.size() && s[l]==s[r]){
                if(maxLen<r-l+1){
                    start=l;
                    maxLen=r-l+1;
                }
                l--;
                r++;
            }
            l=i;
            r=i+1;
            //even len
            while(l>=0 && r<s.size() && s[l]==s[r]){
                if(maxLen<r-l+1){
                    start=l;
                    maxLen=r-l+1;
                } 
                l--;
                r++;
            }
        }
        return s.substr(start,maxLen);
    }
};