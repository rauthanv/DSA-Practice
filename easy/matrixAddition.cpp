// Problem: Matrix Addition

class Solution {
public:
    void Addition(vector<vector<int>>& matrixA,vector<vector<int>>& matrixB) {
        int row = matrixA.size();
        int col = matrixA[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrixA[i][j] = matrixA[i][j] + matrixB[i][j];
            }
        }
    }
};
