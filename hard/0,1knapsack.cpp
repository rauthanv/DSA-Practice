class Solution {
  public:
    int t[1001][1001];
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        memset(t, -1, sizeof(t)); 
        return knapsackRec(W, val, wt, val.size());
    }
    
    //recursive 2^n
    int knapsackRec(int W,vector<int> &val, vector<int> &wt,int n){
        if(n==0||W==0) return 0;
        if(wt[n-1]<=W){
            return max(val[n-1] + knapsackRec(W-wt[n-1],val,wt,n-1), knapsackRec(W,val,wt,n-1));
        }
        return knapsackRec(W,val,wt,n-1);
    }

    // memoization(optimized) o(n*W)
    int knapsackRec(int W,vector<int> &val, vector<int> &wt,int n){
        if(n==0||W==0) return 0;
        if(t[n][W]!=-1) return t[n][W];
        if(wt[n-1]<=W){
            return t[n][W]=max(val[n-1] + knapsackRec(W-wt[n-1],val,wt,n-1), knapsackRec(W,val,wt,n-1));
        }
        return t[n][W]=knapsackRec(W,val,wt,n-1);
    }
};