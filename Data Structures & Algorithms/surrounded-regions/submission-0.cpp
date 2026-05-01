class Solution {
private:
  void dfs(int row,int col,vector<vector<int>> & visited,vector<vector<char>> & board){
    visited[row][col] = 1;
    int m = board.size();
    int n = board[0].size();
    int delrow[4] = {-1,0,1,0};
    int delcol[4] = {0,1,0,-1};
    for(int i=0;i<4;i++){
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if(nrow >=0 && nrow <m && ncol >=0 && ncol <n && !visited[nrow][ncol] && board[nrow][ncol] == 'O'){
            dfs(nrow,ncol,visited,board);
        }
    }
  }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int j=0;j<n;j++){
            if(board[0][j] == 'O'){
                dfs(0,j,visited,board);
            }
            if(board[m-1][j] == 'O'){
                dfs(m-1,j,visited,board);
            }
        }
        for(int i=0;i<m;i++){
            if(board[i][0] == 'O'){
                dfs(i,0,visited,board);
            }
            if(board[i][n-1] == 'O'){
                dfs(i,n-1,visited,board);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]== 0 && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }

    }
};
