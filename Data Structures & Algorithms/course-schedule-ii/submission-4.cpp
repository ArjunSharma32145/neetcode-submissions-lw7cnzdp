class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlist(numCourses);
        vector<int> indegree(numCourses);
        for(auto it : prerequisites){
            adjlist[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        queue<int> q;
        vector<int> ans;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto nei : adjlist[node]){
                indegree[nei]--;
                if(indegree[nei] == 0){
                    q.push(nei);
                }
            }
        }
        if(ans.size() != numCourses) return {};
        return ans;
    }
};
