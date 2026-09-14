class Solution {
    bool dfs(int i,vector<vector<int>> & adj,vector<int> & visited,vector<int> & parent){
        visited[i] = 1;
        for(auto nei : adj[i]){
            if(!visited[nei]){
                parent[nei] = i;
                if(!dfs(nei,adj,visited,parent)) return false;
            }
            else{
                if(parent[i] != nei) return false;
            }
        }
        return true;
    } 
public:
    bool validTree(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adjlist(n);
    for(auto it : edges){
        adjlist[it[0]].push_back(it[1]);
        adjlist[it[1]].push_back(it[0]);
    }
    vector<int> visited(n,0);
    vector<int> parent(n,-1);
    int compo = 0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            compo++;
            if(!dfs(i,adjlist,visited,parent)) return false;
            if(compo > 1) return false;
        }
    }
    return true;
    }
};
