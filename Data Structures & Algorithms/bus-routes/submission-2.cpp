class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        unordered_map<int,vector<int>> adj;
        int n = routes.size();
        for(int i=0;i<n;i++){
            for(auto bus : routes[i]){
                adj[bus].push_back(i);
            }
        }
        queue<pair<int,int>> q;
        q.push({source,0});
        vector<int> visited(501,0);
        while(!q.empty()){
            auto stop = q.front().first;
            auto buses = q.front().second;
            q.pop();
            for(auto bus : adj[stop]){
                if(!visited[bus]){
                    visited[bus] = 1;
                    for(auto stops : routes[bus]){
                        if(stops == target) return buses+1;
                        q.push({stops,buses+1});
                    }
                }
            }
        }
        return -1;
    }
};