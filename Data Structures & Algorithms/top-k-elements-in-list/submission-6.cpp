class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> mpp;
        for(auto it : nums){
            mpp[it]++;
        }
       vector<pair<int,int>> ans;
       for(auto iit : mpp){
             ans.push_back({iit.second,iit.first});
       } 
       sort(ans.rbegin(),ans.rend());
       vector<int> result;
       for(int i=0;i<k;i++){
        result.push_back(ans[i].second);
       }
       return result;
    }
};
