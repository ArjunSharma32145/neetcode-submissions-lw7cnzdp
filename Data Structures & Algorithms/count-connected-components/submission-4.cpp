class Solution {
    void bfs(int node,vector<vector<int>> & adjlist,vector<int> & visited){
        visited[node] = 1;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            for(auto nei : adjlist[node]){
                if(!visited[nei]){
                    visited[nei] = 1;
                    q.push(nei);
                }
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
      vector<vector<int>> adjlist(n);
      for(auto it : edges){
        adjlist[it[0]].push_back(it[1]);
        adjlist[it[1]].push_back(it[0]);
      }
      vector<int> visited(n,0);
      int cn=  0;

      for(int i=0;i<n;i++){
        if(!visited[i]){
            cn++;
            bfs(i,adjlist,visited);
        }
      }
      return cn;
    }
};
