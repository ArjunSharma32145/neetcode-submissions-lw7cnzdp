class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> toposort;
        vector<vector<int>> adjlist(numCourses);
        for(auto it : prerequisites){
            adjlist[it[1]].push_back(it[0]);
        }
        vector<int> inorder(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto it : adjlist[i]){
                inorder[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(inorder[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            toposort.push_back(node);
            for(auto it : adjlist[node]){
                inorder[it]--;
                if(inorder[it] == 0) q.push(it);
            }
        }
        return toposort.size() == numCourses;
    }
};
