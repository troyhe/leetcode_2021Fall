class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 0) return 0;
        int m = mat[0].size();
        if (m == 0) return 0;
        int line = 0;
        vector<vector<int>> row(n, vector<int>(m, 0));
        vector<vector<int>> col(n, vector<int>(m, 0));
        vector<vector<int>> dia(n, vector<int>(m, 0));
        vector<vector<int>> antidia(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (mat[i][j] != 0){
                    row[i][j] = (j == 0)?1:1+row[i][j-1];
                    col[i][j] = (i == 0)?1:1+col[i-1][j];
                    dia[i][j] = (j == 0 || i == 0)?1:1+dia[i-1][j-1];
                    antidia[i][j] = (j == m-1 || i == 0)?1:1+antidia[i-1][j+1];
                    line = max(line, row[i][j]);
                    line = max(line, col[i][j]);
                    line = max(line, dia[i][j]);
                    line = max(line, antidia[i][j]);
                    
                }
            }
        }
        return line;
    }
};
