class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        int dist = 0;
        for(auto it : points){
            dist = it[0]*it[0] + it[1]*it[1];
            pq.push({dist,it[0],it[1]});
        }
        vector<vector<int>> result;
      while(k--){
        auto lol = pq.top();
        pq.pop();
        result.push_back({lol[1],lol[2]});
      }
      return result;
    } 
};
