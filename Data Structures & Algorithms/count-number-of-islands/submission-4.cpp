class Solution {
void dfs(int r,int c,vector<vector<int>> & visited, vector<vector<char>> & grid,int m,int n){
    visited[r][c] = 1;
    int delrow[4] = {-1,0,1,0};
    int delcol[4] = {0,1,0,-1};
    for(int i=0;i<4;i++){
        int nrow = r + delrow[i];
        int ncol = c + delcol[i];
        if(nrow >=0 && nrow<m && ncol >=0 && ncol<n && !visited[nrow][ncol] && grid[nrow][ncol] == '1'){
            dfs(nrow,ncol,visited,grid,m,n);
        }
    }
}
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        int islands = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                islands++;
                dfs(i,j,visited,grid,m,n);
                }
            }
        }
        return islands;
    }
};
