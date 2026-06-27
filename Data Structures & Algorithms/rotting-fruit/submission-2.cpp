class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int tm = 0;
        int freshchicks = 0;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                }
                else if(grid[i][j] == 1) freshchicks++;
            }
        }
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};
        while(!q.empty()){
            auto r = q.front().first.first;
            auto c = q.front().first.second;
            auto time = q.front().second;
            tm = max(tm,time);
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow >=0 && nrow <m && ncol >=0 && ncol <n && grid[nrow][ncol] == 1){
                    grid[nrow][ncol] = 2;
                    q.push({{nrow,ncol},time+1});
                    freshchicks--;
                }
            }
        }
        if(freshchicks) return -1;
        return tm;
    }
};
