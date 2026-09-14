class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlist(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto it : prerequisites){
            adjlist[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int> q;
        int count  = 0;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0){
                 q.push(i);
                 count++;
            }
        }
        while(!q.empty()){
         auto node = q.front();
         q.pop();
         for(auto nei : adjlist[node]){
            indegree[nei]--;
            if(indegree[nei] == 0){
                 q.push(nei);
                 count++;
            }
         }
        }
       return count == numCourses;
    }
};
