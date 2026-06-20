class Solution {
    bool safe(int row,int col,vector<vector<int>> & board){
        int n = board.size();
        for(int i=0;i<col;i++){
            if(board[row][i]) return false;
        }
        int i = row;
        int j = col;
        while(i>=0 && j>=0 ){
            if(board[i][j]) return false;
            i--;
            j--;
        }
        i=row;
        j=col;
        while(i<n && j>=0){
            if(board[i][j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(int col,vector<vector<int>> & board,vector<string> & temp,vector<vector<string>> & ans){
         int n= board.size();
        if(col == n){
            ans.push_back(temp);
            return;
        }
        string lol;
        for(int i=0;i<n;i++) lol += '.';
  // har row ko dekhenge specific col ke liye
        for(int i=0;i<n;i++){
            if(safe(i,col,board)){
                lol[i] = 'Q';
                temp.push_back(lol);
                board[i][col] = 1;
                solve(col+1,board,temp,ans);
                lol[i] = '.';
                temp.pop_back();
                board[i][col] = 0;  
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp;
        vector<vector<int>> board(n,vector<int>(n,0));
        solve(0,board,temp,ans);
        return ans;
    }
};
