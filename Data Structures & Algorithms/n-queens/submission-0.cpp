class Solution {
    bool safe(int row,int col,vector<vector<int>> & board){
        for(int i=0;i<col;i++){
            if(board[row][i]) return false; 
        }
        int n = board.size();
        int i = row;
        int j = col;
        while(i>=0 && j>=0){
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
    void solve(int col,vector<vector<int>> & board,vector<vector<string>> & ans,vector<string> & temp){
        int n = board.size();
        if(col == n){
            ans.push_back(temp);
            return;
        }
        string lol;
        for(int i=0;i<n;i++) lol += '.';
        for(int i=0;i<n;i++){
            if(safe(i,col,board)){
                board[i][col] = 1;
                lol[i] = 'Q';
                temp.push_back(lol);
                solve(col+1,board,ans,temp);
                lol[i]= '.';
                board[i][col] = 0;
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp;
        vector<vector<int>> board(n,vector<int>(n,0));
     solve(0,board,ans,temp);
     return ans;

    }
};
