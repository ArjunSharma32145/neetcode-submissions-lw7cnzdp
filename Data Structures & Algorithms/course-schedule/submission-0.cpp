class Solution {
private:
 bool dfsCheck(int node,vector<int> & visited, vector<int> & pathvis,vector<vector<int>> & adjlist){
    visited[node] = 1;
    pathvis[node] = 1;
     for(auto nei : adjlist[node]){
        if(!visited[nei]){
            if(dfsCheck(nei,visited,pathvis,adjlist) == true) return true;
        }
        else if(pathvis[nei]) return true;
     }


    pathvis[node] = 0;
    return false;
 }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses,0);
        vector<int> pathvis(numCourses,0);
        vector<vector<int>> adjlist(numCourses);
        for(auto it :prerequisites ){
            adjlist[it[0]].push_back(it[1]);
        }
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(dfsCheck(i,visited,pathvis,adjlist) == true) return false;
            }
        }
        return true;
    }
};
