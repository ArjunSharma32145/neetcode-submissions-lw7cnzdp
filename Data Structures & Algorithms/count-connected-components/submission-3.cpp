class Solution {
public:
    void dfs(int node,vector<int> & vis,vector<vector<int>> & adj){
        vis[node]=1;
        for(auto padosi : adj[node]){
            if(!vis[padosi]){
                dfs(padosi,vis,adj);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);
        int count=0;
        for(auto vec : edges){
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        } 
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,adj);
               count++;
            }
        }
        return count;
    }
};
