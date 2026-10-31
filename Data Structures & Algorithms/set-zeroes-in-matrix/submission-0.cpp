class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < matrix.size(); i++) {
            if (matrix[i][0] == 0) {
                for (int k = 1; k < matrix[0].size(); k++) {
                    matrix[i][k] = 0;
                }
            }
        }
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[0][j] == 0) {
                for (int k = 0; k < matrix.size(); k++) {
                    matrix[k][j] = 0;
                }
            }
        }
    }
};
