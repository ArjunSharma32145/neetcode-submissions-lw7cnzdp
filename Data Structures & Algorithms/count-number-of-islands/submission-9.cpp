class Solution {
    void bfs(int r,int c,vector<vector<int>> & visited,vector<vector<char>> & grid){
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        q.push({r,c});
        visited[r][c] = 1;
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};
        while(!q.empty()){
            auto nr = q.front().first;
            auto nc = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = nr + drow[i];
                int ncol = nc + dcol[i];
                if(nrow >= 0 && nrow < m && ncol >=0 && ncol<n && !visited[nrow][ncol] && grid[nrow][ncol] == '1'){
                    visited[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                    
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands =0;
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    islands++;
                    bfs(i,j,visited,grid);
                }
            }
        }
        return islands;
    }
};
