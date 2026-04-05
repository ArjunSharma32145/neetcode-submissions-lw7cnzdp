class Solution {
    void dfs(int i, int j,vector<vector<int>>& grid,int & dist ){
             int n = grid.size();
        int m = grid[0].size();
        if(i<0 || j<0 ||i>=n || j>=m) return;
        if(grid[i][j] != 1) return;
        dist++;
        grid[i][j] = 2;
        dfs(i-1,j,grid,dist);
        dfs(i+1,j,grid,dist);
        dfs(i,j-1,grid,dist);
        dfs(i,j+1,grid,dist);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int dist =0;
               if(grid[i][j] != 1) continue;
               dfs(i,j,grid,dist);
               ans = max(ans,dist);
            }
        }
        return ans;
    }
};
