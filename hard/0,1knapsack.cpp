class Solution
{
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        int n = (int)val.size();
        return knapsackRec(W, val, wt, n);
    }
    int knapsackRec(int W, vector<int> &val, vector<int> &wt, int n)
    {
        if (n == 0 || W == 0)
            return 0;
        if (wt[n - 1] <= W)
        {
            return max(val[n - 1] + knapsackRec(W - wt[n - 1], val, wt, n - 1), knapsackRec(W, val, wt, n - 1));
        }
        return knapsackRec(W, val, wt, n - 1);
    }
};