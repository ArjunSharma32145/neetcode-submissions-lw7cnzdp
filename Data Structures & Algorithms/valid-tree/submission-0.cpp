class Solution {
    bool dfs(int i,vector<int> & visited,vector<int> & prev,vector<vector<int>> & adjlist){
        visited[i] = 1;
        for(auto it : adjlist[i]){
            if(!visited[it]){
                prev[it] = i;
               if(!dfs(it,visited,prev,adjlist)) return false;
            }
            else if(prev[i] != it ) return false;
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
        vector<int> prev(n,-1);
        int components = 0;
        for(int i=0;i<n;i++){
             if(!visited[i]){
                components++;
                if(!dfs(i,visited,prev,adjlist)) return false;
             }
             if(components >1) return false;
        }
        return true;
    }
};
