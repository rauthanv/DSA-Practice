/*
------------------------------------------------------------
Problem: Number of Islands
LeetCode: https://leetcode.com/problems/number-of-islands/

Time Complexity:
- O(R × C)
  (Each cell is visited at most once)

Space Complexity:
- O(R × C) in worst case (queue for BFS)
------------------------------------------------------------
*/

class Solution {
public:
    // Direction arrays: up, down, left, right
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};

    int r, c;

    // Check if cell is within grid bounds
    bool valid(int i, int j) {
        return i >= 0 && i < r && j >= 0 && j < c;
    }

    int numIslands(vector<vector<char>>& grid) {
        r = grid.size();
        c = grid[0].size();

        queue<pair<int,int>> q;
        int count = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {

                // Found an unvisited land cell
                if (grid[i][j] == '1') {
                    count++;            // New island found
                    grid[i][j] = '0';   // Mark as visited
                    q.push({i, j});

                    
                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();

                        for (int k = 0; k < 4; k++) {
                            int nx = x + row[k];
                            int ny = y + col[k];

                            if (valid(nx, ny) && grid[nx][ny] == '1') {
                                grid[nx][ny] = '0';
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};
