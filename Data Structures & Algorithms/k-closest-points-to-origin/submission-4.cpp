class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // closest matlab nearest smallest hence max heap
        // ab heap mein pop dist ke logic ke hisab se ho to obv pair rakhenge
        priority_queue<pair<int,vector<int>>> pq;
        for(auto it : points){
         int dist = it[0]*it[0] + it[1]*it[1];
         pq.push({dist,it});
         if(pq.size() > k) pq.pop();
        }
       vector<vector<int>> ans;
       while(!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
       }
       return ans;
    }
};
