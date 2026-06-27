class Solution {
    int bfs(int r,int c,vector<vector<int>> & visited,vector<vector<int>> & grid){
        int m = grid.size();
        int n = grid[0].size();
        visited[r][c] = 1;
        int area = 1;
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};
        queue<pair<int,int>> q;
        q.push({r,c});
        while(!q.empty()){
            auto w = q.front().first;
            auto e = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = w + drow[i];
                int ncol = e + dcol[i];
                if(nrow >=0 && nrow <m && ncol >= 0 && ncol< n && !visited[nrow][ncol] && grid[nrow][ncol]){
                    visited[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                    area++;
                }
            }
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int maxarea = 0;
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(!visited[i][j] && grid[i][j]){
               maxarea = max(maxarea,bfs(i,j,visited,grid));
               }
            }
        }
        return maxarea;
    }
};
