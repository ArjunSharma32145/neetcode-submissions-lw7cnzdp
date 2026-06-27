class Solution {
    void dfs(int r,int c,vector<vector<int>> & visited,vector<vector<char>> & board){
        visited[r][c] = 1;
                int m = board.size();
        int n = board[0].size();
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
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
            if(!visited[0][j] && board[0][j] == 'O'){
                dfs(0,j,visited,board);
            }
        }
          for(int i=0;i<m;i++){
            if(!visited[i][0] && board[i][0] == 'O'){
                dfs(i,0,visited,board);
            }
        }
          for(int j=0;j<n;j++){
            if(!visited[m-1][j] && board[m-1][j] == 'O'){
                dfs(m-1,j,visited,board);
            }
        }
          for(int i=0;i<m;i++){
            if(!visited[i][n-1] && board[i][n-1] == 'O'){
                dfs(i,n-1,visited,board);
            }
        }
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j] && board[i][j] == 'O'){
                board[i][j] = 'X';
            }
        }
       }
    }
};
