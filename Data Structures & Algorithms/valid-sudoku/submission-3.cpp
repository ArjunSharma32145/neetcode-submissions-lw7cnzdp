class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // ok so first lets check rows 
        for(int rows=0;rows<9;rows++){
            unordered_set<char> seen;
            for(int cols=0;cols<9;cols++){
                if(board[rows][cols] == '.') continue;
                if(seen.count(board[rows][cols])) return false;
                seen.insert(board[rows][cols]);
            }
        }
        // ok now lets check each cols
        for(int cols=0;cols<9;cols++){
            unordered_set<char> seen;
            for(int rows=0;rows<9;rows++){
                if(board[rows][cols] == '.') continue;
                if(seen.count(board[rows][cols])) return false;
                seen.insert(board[rows][cols]);
            }
        }
        // ok nwo each square
        for(int square =0;square<9;square++){
            unordered_set<char> seen;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    int row = (square/3)*3 + i;
                    int col = (square%3)*3 + j;
                    if(board[row][col] == '.') continue;
                    if(seen.count(board[row][col])) return false;
                    seen.insert(board[row][col]);
                }
            }
        }
        return true;
    }
};
