class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        if(m==1 && n==1) return 0;
        vector<vector<int>> diff(m,vector<int>(n,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1}; 
        while(!pq.empty()){
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            int curdiff = pq.top().first;
            pq.pop();
            for(int i=0;i<4;i++){
                int newdiff = 0;
                int checker= 0;
                int newrow = r + drow[i];
                int newcol = c + dcol[i];
                if(newrow >=0 && newrow <m && newcol>=0 && newcol<n){
                  newdiff = abs(heights[r][c] - heights[newrow][newcol]);
                  checker = max(newdiff,curdiff);
                  if(checker < diff[newrow][newcol]){
                    diff[newrow][newcol] = checker;
                    pq.push({checker,{newrow,newcol}});
                  }
                }
            }
        }
        return diff[m-1][n-1];
    }
};