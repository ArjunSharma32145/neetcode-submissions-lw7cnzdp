class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
     // first take everyone distance then just k closest ones 
     // i can store in heap that is min heap sabse aage distance taki uske hisab se ho peeche points
     priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;   
     for(auto it : points){
        int x = it[0];
        int y = it[1];
        int dist = x*x + y*y;
        pq.push({dist,{x,y}});
     }
     vector<vector<int>> ans;
     int count = 0;
     while(count != k){
        auto lol = pq.top();
        pq.pop();
        ans.push_back({lol.second.first,lol.second.second});
        count++;
     }
     return ans;
    }
};
