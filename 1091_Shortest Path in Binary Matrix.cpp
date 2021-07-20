class Solution {
    
    bool addQueue(vector<vector<int>>& grid, unordered_map<int, int>& lengths, queue<pair<int,int>>& line, int length, int row, int col, int n){
        if (row == n - 1 && col == n - 1) return true;
        if (row < 0 || row >= n || col < 0 || col >= n || grid[row][col] == 1) return false;
        if (lengths.find(row*n + col) != lengths.end()) return false;
        lengths[row*n + col] = length;
        line.push({row, col});
        return false;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        unordered_map<int, int> lengths;
        queue<pair<int,int>> line;
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        if (n == 1) return 1;
        lengths[0] = 1;
        line.push({0,0});
        while (!line.empty()){
            pair<int, int> cur = line.front();
            line.pop();
            int row = cur.first;
            int col = cur.second;
            int length = lengths[cur.first * n + cur.second] + 1;
            bool find = false;
            find |= addQueue(grid, lengths, line, length, row - 1, col - 1, n);
            find |= addQueue(grid, lengths, line, length, row - 1, col, n);
            find |= addQueue(grid, lengths, line, length, row - 1, col + 1, n);
            find |= addQueue(grid, lengths, line, length, row, col - 1, n);
            find |= addQueue(grid, lengths, line, length, row, col + 1, n);
            find |= addQueue(grid, lengths, line, length, row + 1, col - 1, n);
            find |= addQueue(grid, lengths, line, length, row + 1, col, n);
            find |= addQueue(grid, lengths, line, length, row + 1, col + 1, n);
            if (find) return length;
        }
        return -1;
    }
};
