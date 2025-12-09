// Problem: Subset Sum Problem

class Solution {
  public:
    int t[201][10001];

    // ------------- MEMOIZATION APPROACH (Top-Down) ------------- //
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        memset(t, -1, sizeof(t)); 
        return subset(sum, arr, arr.size());
    }
    
    bool subset(int sum, vector<int>& arr, int n) {
        if(sum == 0) return true;
        if(n == 0) return false;

        if(t[n][sum] != -1) return t[n][sum];

        if(arr[n-1] <= sum) {
            return t[n][sum] = subset(sum - arr[n-1], arr, n-1) ||
                               subset(sum, arr, n-1);
        }

        return t[n][sum] = subset(sum, arr, n-1);
    }

    
    // ------------- TABULATION APPROACH (Bottom-Up) ------------- //

    bool isSubsetSumTab(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> t(n+1, vector<bool>(sum+1, false));

        for(int i = 0; i <= n; i++){
            t[i][0] = true;
        } 
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= sum; j++) {

                if(arr[i-1] <= j) {
                    t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
                } else {
                    t[i][j] = t[i-1][j];
                }
            }
        }

        return t[n][sum];
    }
};

