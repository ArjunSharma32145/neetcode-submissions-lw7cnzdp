class Solution {
    void dfs(int r,int c,vector<vector<int>> & visited,vector<vector<int>> & grid,int & area){
                int m = grid.size();
        int n = grid[0].size();
        visited[r][c] = 1;
        area++;
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if(nrow >=0 && nrow <m && ncol >=0 && ncol <n && !visited[nrow][ncol] && grid[nrow][ncol]){
                dfs(nrow,ncol,visited,grid,area);
            }
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea =0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int area= 0;
                if(!visited[i][j] && grid[i][j] == 1){
                    dfs(i,j,visited,grid,area);
                    maxarea = max(maxarea,area);
                }
            }
        }
        return maxarea;
    }
};
