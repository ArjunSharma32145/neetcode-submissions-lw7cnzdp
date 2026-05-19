class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // min dist so obv would require min heap
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        for(auto it : points){
            int dist = it[0]*it[0] + it[1]*it[1];
            pq.push({dist,{it[0],it[1]}});
        }
        vector<vector<int>> ans;
        while(k--){
          auto lol = pq.top();
          pq.pop();
          int x = lol.second.first;
          int y = lol.second.second;
          ans.push_back({x,y});
        }
        return ans;
    }
};
