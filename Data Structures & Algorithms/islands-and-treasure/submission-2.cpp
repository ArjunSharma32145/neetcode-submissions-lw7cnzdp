class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0){
                    q.push({{i,j},0});
                }
            }
        }
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};
        while(!q.empty()){
           auto r = q.front().first.first;
           auto c = q.front().first.second;
           auto dist = q.front().second;
           q.pop();
           for(int i=0;i<4;i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if(nrow >=0 && nrow <m && ncol >=0 && ncol <n && grid[nrow][ncol] != 0 && grid[nrow][ncol] != -1 && (dist+1) < grid[nrow][ncol]){
                grid[nrow][ncol] = dist+1;
                q.push({{nrow,ncol},dist+1});
                
            }
           }
        }
    }
};
