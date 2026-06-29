class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> time(n+1,1e9);
        time[0] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        time[k] = 0;
        vector<vector<pair<int,int>>> adjlist(n+1);
        for(auto it : times){
            adjlist[it[0]].push_back({it[1],it[2]});
        }
        while(!pq.empty()){
              auto tm = pq.top().first;
              auto node = pq.top().second;
              pq.pop();
              for(auto it : adjlist[node]){
                if( (tm + it.second )< time[it.first]){
                    time[it.first] = tm + it.second;
                    pq.push({time[it.first],it.first});
                }
              }
        }

int maxi = 0;
        for(auto it : time){ 
            if(it == 1e9) return -1;

       maxi = max(maxi,it);
        }
        return maxi;
    }
};
