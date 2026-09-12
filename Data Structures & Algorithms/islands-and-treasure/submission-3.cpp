class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // so first as we need shortest path plus from treasure so gonna start from pushing all treasure chests in queue with dist 
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0){
                    q.push({0,{i,j}});
                }
            }
        }
        int INF = 2147483647;
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};
        while(!q.empty()){
            auto dist = q.front().first;
            auto r = q.front().second.first;
            auto c = q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow >=0 && nrow < m && ncol >=0 && ncol <n && grid[nrow][ncol] == INF){
                    grid[nrow][ncol] = dist+1;
                    q.push({dist+1,{nrow,ncol}});
                }
            }
        }
    }
};
