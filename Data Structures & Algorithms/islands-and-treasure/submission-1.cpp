class Solution {
public:
   const int INF = 2147483647;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0){
                    q.push({{i,j},0});
                }
            }
        }
        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol] == INF){
                    grid[nrow][ncol] = dist +1;
                    q.push({{nrow,ncol},dist+1});
                }
            }
        }
        
    }
};
