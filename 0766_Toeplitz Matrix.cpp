class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<bool> first(m+n-1, false);
        vector<int> value(m+n-1, 0);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                int idx = i + m - j - 1;
                if (!first[idx]){
                    first[idx] = true;
                    value[idx] = matrix[i][j];
                } else {
                    if (value[idx] != matrix[i][j]) return false;
                }
            }
        }
        return true;
    }
};
