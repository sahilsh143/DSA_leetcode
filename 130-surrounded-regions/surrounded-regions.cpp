class Solution {
public:

    bool valid(int i, int j, int m, int n) {
        if(i < 0 || i >= m || j < 0 || j >= n)
            return false;

        return true;
    }

    int x[4] = {1, -1, 0, 0};
    int y[4] = {0, 0, 1, -1};

    void dfs(vector<vector<char>>& a, int i, int j, int m, int n) {

        a[i][j] = '#';

        for(int k = 0; k < 4; k++) {

            int row = i + x[k];
            int col = j + y[k];

            if(valid(row, col, m, n) && a[row][col] == 'O') {
                dfs(a, row, col, m, n);
            }
        }
    }

    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        // First row
        for(int j = 0; j < n; j++) {
            if(board[0][j] == 'O') {
                dfs(board, 0, j, m, n);
            }
        }

        // First column
        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O') {
                dfs(board, i, 0, m, n);
            }
        }

        // Last row
        for(int j = 0; j < n; j++) {
            if(board[m-1][j] == 'O') {
                dfs(board, m-1, j, m, n);
            }
        }

        // Last column
        for(int i = 0; i < m; i++) {
            if(board[i][n-1] == 'O') {
                dfs(board, i, n-1, m, n);
            }
        }

        // Convert remaining O to X
        // Convert # back to O
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(board[i][j] == 'O')
                    board[i][j] = 'X';

                else if(board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};