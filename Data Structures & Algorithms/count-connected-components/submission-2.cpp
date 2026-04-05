class Solution {
public:

   void dfs(int node,vector<int> & vis, vector<vector<int>> & adj){
    vis[node]=1;
    for(auto neighbour : adj[node]){
        if(!vis[neighbour]){
            dfs(neighbour,vis,adj);
        }
    }
   }
    int countComponents(int n, vector<vector<int>>& edges) {
    vector<int> vis(n,0);
    vector<vector<int>> adj(n);
    int count =0;
    for(auto edge : edges){
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
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
