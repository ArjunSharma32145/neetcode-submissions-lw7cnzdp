class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlist(numCourses);
        for(auto it : prerequisites){
            adjlist[it[1]].push_back(it[0]);
        }
        vector<int> indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto it : adjlist[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++) if(indegree[i] == 0) q.push(i);
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto nei : adjlist[node]){
                indegree[nei]--;
                if(indegree[nei] == 0) q.push(nei);
            }
        }
        if(topo.size() != numCourses) return {};
        return topo;
    }
};
