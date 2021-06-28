class TicTacToe {
    int num;
    vector<vector<int>> rows;
    vector<vector<int>> cols;
    vector<int> dia1;
    vector<int> dia2;  
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        num = n;
        rows.resize(2, vector<int>(n, 0));
        cols.resize(2, vector<int>(n, 0));
        dia1.resize(2,0);
        dia2.resize(2,0); 
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        rows[player - 1][row] += 1;
        if (rows[player - 1][row] == num) return player;
        cols[player - 1][col] += 1;
        if (cols[player - 1][col] == num) return player;
        if (row == col) dia1[player - 1] += 1;
        if (dia1[player - 1] == num) return player;
        if (row + col == num -1) dia2[player - 1] += 1;
        if (dia2[player - 1] == num) return player;
        return 0;
            
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
