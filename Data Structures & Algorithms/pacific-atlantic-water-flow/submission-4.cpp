class Solution {
    void dfs(int r,int c, vector<vector<int>> & heights, set<pair<int,int>> & st,vector<vector<int>>& visited){
         int m = heights.size();
        int n = heights[0].size();
 visited[r][c] = 1;
 st.insert({r,c});
 int delrow[4] = {-1,0,1,0};
 int delcol[4] = {0,1,0,-1};
 for(int i=0;i<4;i++){
    int nrow = r + delrow[i];
    int ncol = c + delcol[i];
    if(nrow >=0 && nrow<m && ncol>=0 && ncol<n && !visited[nrow][ncol] && heights[nrow][ncol] >= heights[r][c]){
        dfs(nrow,ncol,heights,st,visited);
    }
 }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        // pacific
        vector<vector<int>> pacific(m,vector<int>(n,0));
        set<pair<int,int>> pac;
        for(int j=0;j<n;j++) dfs(0,j,heights,pac,pacific);
        for(int i=0;i<m;i++) dfs(i,0,heights,pac,pacific);
        // atlantic
        set<pair<int,int>> atl;
            vector<vector<int>> ac(m,vector<int>(n,0));
        for(int j=0;j<n;j++) dfs(m-1,j,heights,atl,ac);
        for(int i=0;i<m;i++) dfs(i,n-1,heights,atl,ac);
        vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pac.count({i,j}) && atl.count({i,j})) ans.push_back({i,j});
            }
        }
        return ans;
    }
};
