class Solution {
    void bfs(int r,int c,vector<vector<int>> & visited,vector<vector<int>> & grid,int m,int n, int & area){
        visited[r][c] = 1;
        int delrow[4]= {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};
      queue<pair<int,int>> q;
      q.push({r,c});
      while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        area++;
        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >=0 && nrow<m && ncol>= 0 && ncol<n && !visited[nrow][ncol] && grid[nrow][ncol] == 1){
                visited[nrow][ncol] = 1;
                q.push({nrow,ncol});
            }
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
                bfs(i,j,visited,grid,m,n,area);
                }
                maxarea = max(maxarea,area);
            }
        }
        return maxarea;
    }
};
