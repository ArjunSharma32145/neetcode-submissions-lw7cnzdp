class Solution {
    void dfs(int r,int c,vector<vector<int>> & visited,vector<vector<int>> & grid,int m,int n, int & area){
        visited[r][c] = 1;
        area++;
        int delrow[4]= {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];
            if(nrow >=0 && nrow<m && ncol>=0 && ncol<n && !visited[nrow][ncol] && grid[nrow][ncol] == 1){
                dfs(nrow,ncol,visited,grid,m,n,area);
            }
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxarea = 0;
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int area = 0;
                if(!visited[i][j] && grid[i][j] == 1){
                dfs(i,j,visited,grid,m,n,area);
                }
                maxarea = max(maxarea,area);
            }
        }
        return maxarea;
    }
};
