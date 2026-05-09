class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adjlist(n);
        for(auto it : flights){
            adjlist[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>> q;
        vector<int> dist(n,1e9);
        dist[src] = 0;
        q.push({0,{src,0}});
        while(!q.empty()){
            int node = q.front().second.first;
            int price = q.front().second.second;
            int steps = q.front().first;
            q.pop();
            if(steps > k) continue;
            for(auto nei : adjlist[node]){
                if( price + nei.second < dist[nei.first] && steps <= k){
                    dist[nei.first] = price + nei.second;
                    q.push({steps+1,{nei.first,dist[nei.first]}});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};
