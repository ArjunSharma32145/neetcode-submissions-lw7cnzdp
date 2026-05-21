class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlist(numCourses);
    for(auto it : prerequisites){
        adjlist[it[1]].push_back(it[0]);
    }
    // just make topo sort if we have all elements in them means no cycle hence true else false
    vector<int> indegree(numCourses,0);
    for(auto it : adjlist){
       for(auto lol : it){
        indegree[lol]++;
       }
    }
    queue<int> q;
    for(int i=0;i<numCourses;i++){
        if(indegree[i] == 0) q.push(i);
    }
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
 return topo.size() == numCourses;
    }
};
