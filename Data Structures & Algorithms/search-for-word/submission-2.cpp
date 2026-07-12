class Solution {
    int ans = 0;
    void solve(int index,int r,int c,vector<vector<char>> & board,vector<vector<int>> & visited,string & word){

        if(index == word.size()){
            ans++;
            return;
        }

         int m = board.size();
        int n = board[0].size();

        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if(nrow >=0 && nrow <m && ncol >=0 && ncol <n && !visited[nrow][ncol] && board[nrow][ncol] == word[index] ){
                visited[nrow][ncol] = 1;
                solve(index+1,nrow,ncol,board,visited,word);
                visited[nrow][ncol] = 0;
            }
        }
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == word[0]){
                    visited[i][j] = 1;
                    solve(1,i,j,board,visited,word);
                    visited[i][j] = 0;
                }
            }
        }
        return ans != 0;
    }
};
