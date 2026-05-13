class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map<int,int> mpp;
        for(auto it : intervals){
            mpp[it[0]]++;
            mpp[it[1]]--;
        }
        int count =0;
        vector<vector<int>> ans;
        vector<int> lol;
        for(auto it : mpp){
             if(count == 0 && it.second > 0){
                lol.push_back(it.first);
             }
               count += it.second;     
                if(count == 0){
                    lol.push_back(it.first);
                    if(lol.size() == 1) lol.push_back(lol[0]);
                    ans.push_back(lol);
                    lol = {};
                }
            
        }
        return ans;
    }
};
