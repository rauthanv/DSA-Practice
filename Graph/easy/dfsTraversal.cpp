// Problem: DFS of Graph

class Solution {
public:

    // ------------------------------------------------
    // Approach 1: Recursive DFS
    // Time: O(V + E)
    // Space: O(V) (visited + recursion stack)
    // ------------------------------------------------
    void dfsHelper(int node, vector<vector<int>>& adj,
                   vector<int>& visited, vector<int>& ans) {
        visited[node] = 1;
        ans.push_back(node);

        for (int n : adj[node]) {
            if (!visited[n]) {
                dfsHelper(n, adj, visited, ans);
            }
        }
    }

    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> visited(V, 0);
        vector<int> ans;

        dfsHelper(0, adj, visited, ans);
        return ans;
    }


    // ------------------------------------------------
    // Approach 2: Iterative DFS (Using Stack)
    // Time: O(V + E)
    // Space: O(V)
    // ------------------------------------------------
    
    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> visited(V, 0);
        vector<int> ans;
        stack<int> st;

        st.push(0);

        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (visited[node]) continue;

            visited[node] = 1;
            ans.push_back(node);

            for (int i = adj[node].size() - 1; i >= 0; i--) {
                if (!visited[adj[node][i]]) {
                    st.push(adj[node][i]);
                }
            }
        }
        return ans;
    }
};
