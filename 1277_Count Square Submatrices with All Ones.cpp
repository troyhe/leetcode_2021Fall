class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> squares(n, vector<int>(m, 0));
        int area = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (matrix[i][j] == 1){
                    int left = (i > 0)?squares[i-1][j]:0;
                    int above = (j > 0)?squares[i][j-1]:0;
                    int dia = (i > 0 && j > 0)?squares[i-1][j-1]:0;
                    squares[i][j] = 1 + min(min(left, above), dia);
                    area += squares[i][j];
                }
            }
        }
        return area;
    }
};
