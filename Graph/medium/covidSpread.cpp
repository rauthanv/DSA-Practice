// Problem: Help Aterp (Hospital Infection Problem)

class Solution {
public:
    // Directions: up, down, left, right
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};
    
    int r, c;

    bool valid(int i, int j) {
        return i >= 0 && i < r && j >= 0 && j < c;
    }

    // ------------------------------------------------
    // Approach: Multi-source BFS
    // ------------------------------------------------
    int helpaterp(vector<vector<int>> hospital) {

        r = hospital.size();
        c = hospital[0].size();

        queue<pair<int,int>> q;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (hospital[i][j] == 2)
                    q.push({i, j});
            }
        }

        int time = 0;
        while (!q.empty()) {
            time++;
            int curr_infected = q.size();
            
            while (curr_infected--) {
                int i=q.front().first;
                int j=q.front().second;
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int ni = i + row[k];
                    int nj = j + col[k];

                    if (valid(ni, nj) && hospital[ni][nj] == 1) {
                        hospital[ni][nj] = 2;
                        q.push({ni, nj});
                    }
                }
            }
        }
        if(time==0) return 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (hospital[i][j] == 1)
                    return -1;
            }
        }
        return time-1;
    }
};
