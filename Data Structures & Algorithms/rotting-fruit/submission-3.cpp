class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int tm=  0;
        queue<pair<int,pair<int,int>>> q;
        int freshs = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    q.push({0,{i,j}});
                }
                if(grid[i][j] == 1) freshs++;
            }
        }
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};
        while(!q.empty()){
            auto time = q.front().first;
            auto r = q.front().second.first;
            auto c = q.front().second.second;
            q.pop();
            tm = max(tm,time);
            for(int i=0;i<4;i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow >=0 && nrow < m && ncol >=0 && ncol <n && grid[nrow][ncol] == 1){
                    grid[nrow][ncol] = 2;
                    freshs--;
                    q.push({time+1,{nrow,ncol}});
                }
            }
        }
        if(freshs) return -1;
        return tm;
    }
};
