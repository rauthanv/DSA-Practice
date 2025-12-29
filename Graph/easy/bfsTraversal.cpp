// Problem: BFS of Graph

class Solution {
public:

    // ------------------------------------------------
    // Approach: Breadth First Search (BFS)
    // Time: O(V + E)
    // Space: O(V)
    // ------------------------------------------------
    vector<int> bfs(vector<vector<int>> &adj) {
        int V = adj.size();
        vector<int> ans;
        vector<int> visited(V, 0);
        queue<int> q;

        visited[0] = 1;
        q.push(0);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (int n : adj[node]) {
                if (!visited[n]) {
                    visited[n] = 1;
                    q.push(n);
                }
            }
        }
        return ans;
    }
};
