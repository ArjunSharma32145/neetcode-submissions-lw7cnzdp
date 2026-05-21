class Solution {
    void dfs(int i,bool & cycle, vector<int> & visited, vector<vector<int>> & adjlist,stack<int> & st,vector<int> & pathvis){
        visited[i] = 1;
        pathvis[i] = 1;
        for(auto it : adjlist[i]){
            if(!visited[it]){
                dfs(it,cycle,visited,adjlist,st,pathvis);
            }
            else if(pathvis[it]){
                cycle = true;
                return ;
            }
        }
        pathvis[i] = 0;
        st.push(i);
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlist(numCourses);
        for(auto it : prerequisites){
            adjlist[it[1]].push_back(it[0]);
        }
        stack<int> st;
        vector<int> visited(numCourses,0);
        vector<int> pathvis(numCourses,0);
        for(int i=0;i<numCourses;i++){
            bool cycle = false;
           if(!visited[i]) dfs(i,cycle,visited,adjlist,st,pathvis);
           if(cycle) return {};
        }
        vector<int> topo;
        while(!st.empty()){
            topo.push_back(st.top());
            st.pop();
        }
        if(topo.size() != numCourses) return {};
        return topo;
    }
};
