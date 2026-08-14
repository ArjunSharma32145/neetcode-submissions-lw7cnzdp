class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        vector<vector<int>> visited(n,vector<int>(n,0));
        visited[0][0] = 1;
        int ans = INT_MAX;
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};
        while(!pq.empty()){
            auto r = pq.top().second.first;
            auto c = pq.top().second.second;
            auto time = pq.top().first;
            pq.pop();
            if(r == n-1 && c == n-1) ans = min(ans,time);
            for(int i=0;i<4;i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow >=0 && nrow<n && ncol >=0 && ncol<n && !visited[nrow][ncol]){
                    visited[nrow][ncol] = 1;
                       if(time >= grid[nrow][ncol]){
                          pq.push({time,{nrow,ncol}});
                       }
                       else pq.push({grid[nrow][ncol],{nrow,ncol}});
                }
            }
        }
        return ans;
    }
};
