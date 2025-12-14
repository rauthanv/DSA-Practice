// Problem: Matrix Addition


class Solution {
public:
    void Addition(vector<vector<int>>& matrixA,vector<vector<int>>& matrixB) {

        int rows = matrixA.size();
        int cols = matrixA[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrixA[i][j] = matrixA[i][j] + matrixB[i][j];
            }
        }
    }
};
