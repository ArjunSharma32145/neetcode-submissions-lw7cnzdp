class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source  == target) return 0;
        unordered_map<int,vector<int>> adj;
        int n = routes.size();
        for(int i=0;i<n;i++){
            for(auto it : routes[i]){
                adj[it].push_back(i);
            }
        }
        queue<int> q;
        vector<int> visited(501,0);
        for(auto bus : adj[source]){
            if(!visited[bus]){
                visited[bus] = 1;
                q.push(bus);
            }
        }
        int buscount = 1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto bus = q.front();
                q.pop();
                for(auto stop : routes[bus]){
                    if(stop == target) return buscount;
                    for(auto buses : adj[stop]){
                        if(!visited[buses]){
                            visited[buses] = 1;
                            q.push(buses);
                        }
                    }
                }
            }
            buscount++;
        }
        return -1;
    }
};