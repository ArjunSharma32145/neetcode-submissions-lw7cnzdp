class Solution {
    void dfs(string start,unordered_map<string,vector<pair<string,int>>> & adjlist,vector<string> & ans){
        for(auto & it : adjlist[start]){
            if(it.second == 1){
                it.second = 0;
                dfs(it.first,adjlist,ans);
            }
        }
        ans.push_back(start);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<pair<string,int>>> adjlist;
        sort(tickets.begin(),tickets.end());
        for(auto it : tickets){
            adjlist[it[0]].push_back({it[1],1});
        }
        string start = "JFK";
        vector<string> ans;
        dfs(start,adjlist,ans);
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
